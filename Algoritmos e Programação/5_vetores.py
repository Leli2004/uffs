##################################################################
# TODLeia um número indefinido de valores, até que o usuário digite o valor 0. 
# Em seguida, mostre qual é o menor e qual é o maior valor da lista.O

lista = []
while True:
    valor = int(input('Informe um número inteiro (0 para terminar): '))
    if valor == 0:
        break
    lista.append(valor)

maior = lista.pop()
menor = maior
for valor in lista:
    if maior < valor:
        maior = valor
    if menor > valor:
        menor = valor
print(menor)
print(maior)

##################################################################
# Faça um programa que leia cinco (5) valores em uma lista e, ao final,
# imprima-os de forma ordenada sem usar a função sort().

for i in range(5):
    lista.append(int(input('Digite um número para adicionar na lista: ')))
print(lista)
# Solução 1 - Bubble Sort
for rep in lista:
    for i in range(0, len(lista) - 1):
        if lista[i] > lista[i+1]:
            lista[i], lista[i+1] = lista[i+1], lista[i]
print(lista)

##################################################################
# A cantina da UFFS e o RU fazem uma promoção semanal de 
# descontos para clientes de acordo com as iniciais do nome da pessoa. 
# Crie um algoritmo que leia o primeiro nome do cliente, o valor de sua conta 
# e se o nome do cliente iniciar com as letras A, D, S ou B o cliente terá um desconto de 30%. 
# Para o cliente cujo nome não se inicia por nenhuma dessas letras, 
# exibir a mensagem indicando desconto não aplicável.

# Resolução da atividade 6
# Solicita o primeiro nome do cliente e o valor da conta
primeiro_nome = input("Digite o primeiro nome do cliente: ")
valor_conta = float(input("Digite o valor da conta: "))

if primeiro_nome[0].upper() in 'ADSB':
    valor_desconto = 0.3 * valor_conta
    valor_final = valor_conta - valor_desconto
    print(f"Parabéns! Você ganhou um desconto de 30% na sua conta. O valor final é: R$ {valor_final:.2f}")
else:
    print("Desconto não aplicável")

##################################################################
# A turma de Algoritmo e Programação, por ter muitos alunos, será dividida em dias de provas.
# A turma será dividida em três grupos. Fazer um algoritmo que leia o nome do aluno e indique a sala em que ele deverá fazer as provas. 
# Use a primeira letra do nome do aluno e a tabela a seguir:
# A-K : sala 101
# L-N : sala 102
# O-Z : sala 103

nome_aluno = input("Digite o nome do aluno: ")

primeira_letra = nome_aluno[0].upper()  # Converte para maiúscula para facilitar a comparação

if 'A' <= primeira_letra <= 'K':
    sala = "sala 101"
elif 'L' <= primeira_letra <= 'N':
    sala = "sala 102"
else:
    sala = "sala 103"

print("O aluno", nome_aluno, "deverá fazer as provas na", sala, "do bloco F.")
