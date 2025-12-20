
##################################################################
# Crie uma função que dadas duas matrizes A e B de mesmo tamanho, 
# retorne uma nova matriz que é a soma de A e B.

def soma_matriz(A, B):
    for l in range(len(A)):
        for c in range(len(A[0])):
            print(A[l][c] + B[l][c])
            A[l][c] = A[l][c] + B[l][c]
            print(A)
    return A

def criar_matriz(linhas, colunas, valor_inicial):
    return [[valor_inicial for _ in range(colunas)] for _ in range(linhas)]

A = criar_matriz(4, 3, 5)
print(A)
B = criar_matriz(4, 3, 6)
print(B)
print(soma_matriz(A, B))

##################################################################
# Crie duas matrizes 4x4 e crie uma função que faça a multiplicação da 
# primeira matriz pela segunda e retorne a matriz resultante. 
# Depois chame a função e imprima a matriz resultante.

import random # biblioteca usada para sortear números aleatórios

def criar_matriz2d(linhas, colunas, valor_inicial = 0):
    return [[valor_inicial for _ in range(colunas)] for _ in range(linhas)]

def criar_matriz2d_aleatoria(linhas, colunas):
    return [[random.randint(-9, 9) for _ in range(colunas)] for _ in range(linhas)]

def mult_matriz(A, B):
    if len(A[0]) != len(B):
        print(f"Não é possível multiplicar a matriz A({len(A)}x{len(A[0])}) por B({len(B)}x{len(B[0])})")
        return None
    C = criar_matriz2d(len(A), len(B[0])) # Matriz resultante sempre tem o número de linha da matriz A e número de colunas da matriz B
    for i in range (len(A)):
        for j in range (len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C

def imprimir_matriz(matriz):
    for l in range(len(matriz)):
	    for c in range(len(matriz[0])):
		    print(f'[{matriz[l][c]:^5}]', end='')

A = criar_matriz2d_aleatoria(2, 3)
B = criar_matriz2d_aleatoria(3, 4)
C = mult_matriz(A, B)

imprimir_matriz(A)
imprimir_matriz(B)
if C != None:
    imprimir_matriz(C)

##################################################################
# Criar um algoritmo que leia os elementos de matriz inteira 5 x 5 
# e escreva somente os elementos abaixo da diagonal principal.

def ler_matriz():
    matriz = []
    print("Digite os elementos da mat5riz 5x5:")
    for i in range(5):
        linha = []
        for j in range(5):
            elemento = int(input(f"Digite o elemento [{i}][{j}]: "))
            linha.append(elemento)
        matriz.append(linha)
    return matriz

def imprimir_matriz(matriz):
    print("Matriz Original:")
    for linha in matriz:
        for elemento in linha:
            print(elemento, end=" ")
        print()  # Para mudar de linha após imprimir uma linha completa

def elementos_abaixo_diagonal(matriz):
    print("Elementos abaixo da diagonal principal:")
    for i in range(1, 5):  # Começamos em 1 para estar abaixo da diagonal principal
        for j in range(i):
            print(matriz[i][j], end=" ")
        print()  # Para mudar de linha após imprimir uma linha completa

# Exemplo de uso:
matriz = ler_matriz()
imprimir_matriz(matriz)
elementos_abaixo_diagonal(matriz)
