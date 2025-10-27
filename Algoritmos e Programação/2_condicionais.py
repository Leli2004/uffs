##################################################################
# Construir um programa que leia dois números e efetue a adição. 
# Caso o valor somado seja maior que 20, este deverá ser apresentado 
# somando-se a ele mais 8; caso o valor somado seja menor ou igual a 20, 
# este deverá ser apresentado subtraindo-se 5.
n1 = float(input("n1: "))
n2 = float(input("n2: "))

soma = n1 + n2
if soma > 20:
    soma += 8
else:
    soma -= 5

print(f"\nResultado: {soma}")

##################################################################
# A prefeitura de Chapecó abriu uma linha de crédito para os funcionários. 
# O valor máximo da prestação não poderá ultrapassar 30% do salário bruto.
# Fazer um algoritmo que permita entrar com o salário bruto e o valor da 
# prestação e informar se o empréstimo pode ou não ser concedido.
salario = float(input("Salário  : R$"))
prestacao = float(input("Prestação: R$"))

if prestacao > (salario*0.3):
    print("\nEmpréstimo NÃO PODE ser concedido!")
else:
    print("\nEmpréstimo PODE ser concedido!")

##################################################################
# Escreva um programa que leia 3 valores inteiros a, b e c e informe 
# se eles representam os lados de um triângulo. Três valores podem 
# representar os lados de um triângulo se e somente se a soma de 
# quaisquer 2 lados for maior que o terceiro lado.
n1 = int(input("n1: "))
n2 = int(input("n2: "))
n3 = int(input("n3: "))

if n1 + n2 > n3 and n1 + n3 > n2 and n2 + n3 > n1:
    print("\nValores formam um triângulo")
else:
    print("\nValores não formam um triângulo")
