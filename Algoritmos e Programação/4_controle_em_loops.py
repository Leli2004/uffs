##################################################################
# Faça um programa que imprima todos os valores de 0 a 100 menos aqueles que são múltiplos de 5.

i = 0
while i < 100:
    i += 1
    if i % 5 == 0:
        continue
    print(i)

##################################################################
# Faça um programa que leia um conjunto de notas de alunos e, ao final, 
# mostre a média geral da turma. A entrada será finalizada quando for lida a nota 999.

media = 0
contador = 0
while True:
    num = float(input('Digite uma nota (999 para terminar): '))
    if num == 999:
        break
    media += num
    contador += 1
print(f'A média geral da turma é: {(media/contador):.2f}')

##################################################################
# Escreva um programa para verificar se um número natural digitado pelo
# usuário é um número primo (um número é primo quando ele é maior 
# que 1 e ele é divisível apenas por 1 e por ele mesmo).

num = int(input('Digite um número natural: '))
if num <= 1:
    print(f'{num} NÃO é primo.')
for i in range(num - 1, 0, -1):
    if i == 1:
        print(f'{num} é primo.')
        break
    if num % i == 0:
        print(f'{num} NÃO é primo.')
        break

