##################################################################
# Crie uma lista com 3 carros (objetos da classe Carro), faça a 
# leitura dos dados e, ao final, imprima os dados dos 3 carros.

class Carro_4:
    marca = None
    modelo = None
    ano = None
    cor = None

loja = []
for i in range(3):
    c = Carro_4()
    c.marca = input("\nMarca: ")
    c.modelo = input("Modelo: ")
    c.ano = input("Ano: ")
    c.cor = input("Cor: ")
    loja.append(c)

print("\nRelatório de carros da loja:")
for carro in loja:
    print("   marca: ",carro.marca, " modelo: ", carro.modelo, " ano: ", carro.ano, " cor", carro.cor)

##################################################################
# Defina uma classe que armazene os dados de um aluno. A classe deve 
# conter CPF, nome do aluno, nota da primeira prova, nota da segunda 
# prova e média final. Depois, instancie um aluno com todos os seus dados. 
# A média deve ser calculada a partir das notas da prova. 

class Aluno:
    cpf = None
    nome = None
    nota1 = None
    nota2 = None
    media_final = None

aluno1 = Aluno()

aluno1.cpf = "012.345.678-90"
aluno1.nome = "João da Silva"
aluno1.nota1 = 10
aluno1.nota2 = 7

aluno1.media_final = (aluno1.nota1 + aluno1.nota2)/2

print(f" A média final do aluno foi: {aluno1.media_final}.")

##################################################################
# Crie uma classe para representar um número complexo (possui dois atributos, 
# parte real e imaginária. Implemente os métodos de adição, subtração 
# e multiplicação na classe do número com outro número.

class Complexo:
    def __init__(self, real, imaginario):
        self.real = real
        self.imaginario = imaginario

    def __str__(self):
        if self.imaginario >= 0:
            return f"{self.real} + {self.imaginario}i"
        else:
            return f"{self.real} - {abs(self.imaginario)}i"

    def __add__(self, other):
        return Complexo(self.real + other.real, self.imaginario + other.imaginario)

    def __sub__(self, other):
        return Complexo(self.real - other.real, self.imaginario - other.imaginario)

    def __mul__(self, other):
        real = self.real * other.real - self.imaginario * other.imaginario
        imaginario = self.real * other.imaginario + self.imaginario * other.real
        return Complexo(real, imaginario)

# Testando a classe Complexo
c1 = Complexo(3, 4)
c2 = Complexo(5, -2)

# Soma
soma = c1 + c2
print("Soma:", soma)

# Subtração
subtracao = c1 - c2
print("Subtração:", subtracao)

# Produto
produto = c1 * c2
print("Produto:", produto)
