##################################################################
# Crie uma função que receba 2 argumentos de entrada (base e expoente) e retorne o resultado da potenciação.

def potenciacao(base, expoente):
    return base ** expoente
valor_base = int(input('Digite o valor da base: '))
valor_expoente = int(input('Digite o valor do expoente: '))
print(potenciacao(valor_base, valor_expoente))

##################################################################
# Suponha que a função abs() não está mais disponível para uso, 
# mas que seu programa precisa calcular o valor absoluto de um número.

def absoluto(valor):
    if valor >= 0:
        return valor
    else:
        return valor * -1

resultado = absoluto(0)
print(resultado)
print(absoluto(123))
print(absoluto(-34))

##################################################################
# Crie um programa que declare uma lista de 10 inteiros. Em seguida, chame uma função
# que retorne o menor elemento do conjunto (sem usar a função min do Python).

lista = [3, 4, -2, 6, 45, 0, -30, 23, 30, -7]

def menor_elemento(lista):
    menor = lista.pop()
    for valor in lista:
        if menor > valor:
            menor = valor
    return menor

print(menor_elemento(lista))

##################################################################
# Escreva uma função que realiza a correção de uma prova objetiva com 10 questões. 
# A função deve receber duas listas, a primeira contendo o gabarito e a segunda 
# contendo as respostas de um determinado aluno. A função deve retornar o número de acertos.

def corrige_prova(gabarito, resposta_aluno):
    acertos = 0
    for i in range(len(gabarito)):
        if gabarito[i] == resposta_aluno[i]:
            acertos += 1
    return acertos

gabarito = ["A","B", "A", "C", "B", "D", "E", "A", "A", "C"]
resposta_aluno = ["A", "B", "C", "C", "B", "D", "B", "A", "E", "C"]
acertos = corrige_prova(gabarito, resposta_aluno)

print(f"O aluno acertou {acertos}/10")

