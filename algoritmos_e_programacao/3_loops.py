##################################################################
# Escreva um programa que imprima os 10 primeiros múltiplos de 7 começando em 0.
val = []

for num in range(10*7):
    if num % 7 == 0:
       val.append(num)
    if len(val) == 10:
        break

print(f"\nOs 10 primeiros múltiplos de 7 são: {val}")

##################################################################
# Faça um algoritmo usando o comando while ou for que leia um valor inteiro 
# fornecido pelo usuário e calcule a soma de seus 10 sucessores e seus 10 antecessores. 
num = int(input("Int: "))
sumSuc = sumAnt = 0

for i in range(10):
    i += 1
    sumSuc += num + i
    sumAnt += num - i

print(f"\nSoma dos sucessores = {sumSuc} \nSoma dos antecessores = {sumAnt}")

##################################################################
# Dado um país A, com 5.000.000 de habitantes e uma taxa de natalidade de 3% ao ano, e um país 
# B com 7.000.000 de habitantes e uma taxa de natalidade de 2% ao ano, crie um program que calcule 
# e imprima o tempo necessario para que a população do pais A ultrapasse a população do pais B
a = 5000000
b = 7000000
taxa_a = 0.03
taxa_b = 0.02

anos = 0

while a <= b:
    a += a * taxa_a
    b += b * taxa_b
    anos += 1

print("Serão necessários", anos, "anos para que a população do país A ultrapasse a do país B.")

##################################################################
# Escreva um programa que recebe um número inteiro positivo e retorna 
# a quantidade de divisores positivos que ele possui.
n = int(input("Digite um número inteiro positivo: "))
quantidade = 0

for i in range(1, n + 1):
    if n % i == 0:
        quantidade += 1

print("O número", n, "possui", quantidade, "divisores positivos.")

##################################################################
# Faça um programa que conte quantas vogais possui o texto: Aurélio aterrisou de paraquedas na praia.
texto = "Aurélio aterrisou de paraquedas na praia."
vogais = "aeiouAEIOU"
quantidade = 0

for letra in texto:
    if letra in vogais:
        quantidade += 1

print("O texto possui", quantidade, "vogais.")

##################################################################
# Faça um programa que peça para o usuário um número inteiro e imprima quantos digitos ele possui.
numero = input("Digite um número inteiro: ")
quantidade = len(numero)
print("O número possui", quantidade, "dígitos.")

##################################################################
# Faça uma função que indique se um numero é forte (um numero forte é um numero cujo 
# a soma do fatorial de seus dígitos é igual ao próprio número)
def fatorial(n):
    resultado = 1
    for i in range(1, n + 1):
        resultado *= i
    return resultado

def eh_forte(numero):
    soma = 0
    for digito in str(numero):
        soma += fatorial(int(digito))
    return soma == numero

num = int(input("Digite um número: "))

if eh_forte(num):
    print(num, "é um número forte!")
else:
    print(num, "não é um número forte.")

##################################################################