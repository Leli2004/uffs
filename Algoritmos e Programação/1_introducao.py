##################################################################
# Leia quatro números e imprima a média ponderada desses números, 
# sabendo-se que os pesos são respectivamente: 1, 2, 3 e 4
n1 = float(input("Digite o primeiro número: "))
n2 = float(input("Digite o segundo número: "))
n3 = float(input("Digite o terceiro número: "))
n4 = float(input("Digite o quarto número: "))

media = (n1*1 + n2*2 + n3*3 + n4*4) / (1 + 2 + 3 + 4)
print("A média ponderada é:", media)

##################################################################
# Faça um programa que leia um número inteiro e exiba True caso o
# número for um resultado possível da inequação abaixo e False caso 
# contrário. Inequação: 3 * número - 12 > 19 
numero = int(input("Digite um número inteiro: "))
resultado = 3 * numero - 12 > 19
print(resultado)

##################################################################
# Faça um programa que compute as raízes da equação dada por 
# ax² + bx + c = 0 sendo que a = 2, b = 14 e c = -60
a = 2
b = 14
c = -60

delta = b**2 - 4*a*c
x1 = (-b + delta**0.5) / (2*a)
x2 = (-b - delta**0.5) / (2*a)

print("As raízes são:", x1, "e", x2)

##################################################################
# 
