#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall exes_prova_antiga.c -o exes_prova_antiga

struct filme {
    int id;
    char titulo[100];
    char diretor[100];
    int anoLancamento;
    float notaIMDB;
};
typedef struct filme Filme;

void printSomaP(int l, int c);
void imprimeFilme(Filme *f);
int filmesPorAno(Filme f[], int tam, int ano);
Filme melhorClassificacao(Filme f[] , int tam);

struct tsimp {
    int info;
    struct tsimp *next;
};
typedef struct tsimp simples;

struct tsentsimp {
    simples *first;
    simples *last;
};
typedef struct tsentsimp sents;

sents *getList (int *v, int tam);
sents *getInter(sents s1, sents s2);

int main() {
    // printf("\n***********************************\nExe 01:\n");
    // printSomaP(4,5);

    // printf("\n***********************************\nExe 02 A:\n");
    // Filme f1;
    // f1.id = 1;
    // strcpy(f1.titulo, "Imitation Game");
    // strcpy(f1.diretor, "Morten Tyldum");
    // f1.anoLancamento = 2014;
    // f1.notaIMDB = 8.0;
    // imprimeFilme(&f1);

    // printf("\n***********************************\nExe 02 B:\n");
    // Filme f[3] = {
    //     {1, "aaa", "aaa", 2014, 8.8},
    //     {1, "bbb", "bbb", 2017, 9.2},
    //     {3, "ccc", "ccc", 2017, 6.1}
    // };
    // int ano = 2017;
    // int n;
    // n = filmesPorAno(f, 3, ano);
    // printf("Filmes em %d = %d\n", ano, n);

    // printf("\n***********************************\nExe 02 C:\n");
    // Filme vFilmes[] = {
    //     {42, "Imitation Game", "Morten Tyldum", 2014, 8.0},
    //     {43, "Interestelar", "Christopher Nolan", 2014, 8.7},
    //     {44, "A Teoria de Tudo", "James Marsh", 2014, 7.7},
    //     {45, "Conclave", "Edward Berger", 2025, 7.4}
    // };

    // int elementos = sizeof(vFilmes) / sizeof(vFilmes[0]);
    // Filme melhorFilme = melhorClassificacao(vFilmes, elementos);
    // printf("Título: %s, ano: %d \n", melhorFilme.titulo, melhorFilme.anoLancamento);

    // printf("\n***********************************\nExe 03:\n");
    // int vetor[5] = {5,4,3,2,1};
    // sents *s=NULL;
    // s = (sents*)malloc(sizeof(sents));
    // s = getList(vetor, 5);
    // printf("Info sentinela retornado = %d \n", s->first->info);

    printf("\n***********************************\nExe 04:\n");
    int v1[5] = {1,2,3,4,5};
    int v2[4] = {3,4,6,7};
    sents *s1, *s2, *inter;

    s1 = getList(v1, 5);
    s2 = getList(v2, 4);

    inter = getInter(*s1, *s2);

    simples *aux;
    printf("Interseccao: {");
    for(aux = inter->first; aux != NULL; aux = aux->next) {
        printf("%d ", aux->info);
    }
    printf("}\n");

    return 0;
}

/* Exe 01
    Crie uma função que receba o número de linhas l e colunas c de uma matriz hipotética.
    A função deve imprimir soma das posições (linha + coluna) dos elementos da matriz que estão acima da diagonal principal.
    Lembre que a diagonal principal é o conjunto de elementos onde o índice da linha é igual ao índice da coluna.
    Considere que a célula da matriz na primeira linha e primeira coluna tem posições l = 0 e c = 0.
    Exemplo: 
    Dada a entrada l = 4 e c = 5, ou seja uma matriz 4x5, a função deve imprimir:
    1 2 3 4
      3 4 5
        5 6
          7
*/
void printSomaP(int l, int c) {
    for(int i=0; i<l; i++) {
        for(int j=0; j<c; j++) {
            if(i < j){
                printf("%d ", i+j);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return;
}

/* Exe 02 
    Imagine que você está desenvolvendo um sistema de gestão de filmes para um serviço de streaming em linguagem C.
    Você já tem a definição de uma struct como a struct Filme definida no início desde arquivo.
    Agora você precisa implementar mais algumas demandas:
*/

/* A
    A função void imprimeFilme(Filme *f), que deve imprimir na tela os dados de um filme passado como parâmetro, no seguinte formato:
    42, Imitation Game, 2014, Morten Tyldum, 8.0

    Obs.: Escreva na folha resposta o programa completo para demonstrar a funcionalidade da função, criando uma variável do tipo Filme 
    com os dados indicados acima. Considere que no main(), já há uma variável Filme f1;
*/
void imprimeFilme(Filme *f){
    if(f != NULL)
    printf("%d, %s, %d, %s, %.1f \n", 
        f->id,
        f->titulo,
        f->anoLancamento,
        f->diretor,
        f->notaIMDB
    );
}

/* B
    Complete as lacunas da função abaixo. O objetivo é retornar o número de filmes de um dado ano, cadastrados na base de dados.
    Reescreva todo o código na folha resposta, incluindo a função main() e demonstre a impressão do retorno da função.
*/
int filmesPorAno(Filme f[], int tam, int ano) {
    int contador = 0;

    for(int i=0; i<tam; i++) {
        if(f[i].anoLancamento == ano) {
            contador++;
        }
    }

    return contador;
}
 
/* C
    Considere o trecho de código a seguir. Complete as partes indicadas para implementar corretamente a função melhorClassificacao.
    O objetivo dessa função é retornar o filme com a melhor avaliação no IMDB dentro do conjunto informado.
    No local indicado na função main(), redija o código para exibir o resultado da função melhorClassificacao, no seguinte formato:
    Título: Interestelar, ano: 2014.
*/
Filme melhorClassificacao(Filme f[] , int tam){
    int maiorIndex=0;
    float maiorNota=0;

    for(int i=0; i<tam; i++) {
        if(f[i].notaIMDB > maiorNota) {
            maiorIndex = i;
            maiorNota = f[i].notaIMDB;
        }
    }

    return f[maiorIndex];
}

/* Exe 03
    Um aplicativo gerou um vetor composto por vários inteiros. 
    Agora é necessário criar uma lista simples para armazenar este vetor.
    Então você terá que implementar uma função que receba um vetor de inteiros e a quantidade de elementos do vetor.
    Esta função deverá criar uma lista encadeada simples e retornar o sentinela da lista.
    A assinatura (ou cabeçalho) da função é sents *getList (int *v, int tam).
*/
sents *getList (int *v, int tam) {
    simples *new, *first=NULL, *aux;

    for (int i=0; i<tam; i++) {
        new = (simples*)malloc(sizeof(simples));
        new->next = NULL;
        new->info = v[i];

        if (first == NULL) {
            first = new;
            aux = new;
        } else {
            aux->next = new;
            aux = new;
        }
    }

    sents *resp=NULL;
    resp = (sents*)malloc(sizeof(sents));
    resp->first = first;
    return resp;
}

/* Exe 04
    Intersecção é uma operação entre dois conjuntos que resulta em um terceiro conjunto com os elementos existentes em ambos os conjuntos.
    Por exemplo, A = {1,2,3,4} e B = {3,4,5}, A ∩ B resulta {3,4}. Crie uma função que receba duas listas simples (seus sentinelas) e crie 
    uma lista encadeada contendo os elementos da intersecção das listas simples (as listas são compostas por valores únicos). 
    O cabeçalho (ou assinatura) da função é sents *getInter (sents s1, sents s2).
*/
sents *getInter(sents s1, sents s2){
    simples *auxS1, *auxS2;
    simples *new, *aux, *first=NULL;

    for(auxS1=s1.first; auxS1!=NULL; auxS1=auxS1->next) {
        for(auxS2=s2.first; auxS2!=NULL; auxS2=auxS2->next) {
            if(auxS1->info == auxS2->info) {
                new = (simples*)malloc(sizeof(simples));
                new->next = NULL;
                new->info = auxS1->info;

                if(first==NULL) {
                    first = new;
                    aux = new;
                } else {
                    aux->next = new;
                    aux = new;
                }
            }
        }
    }

    sents *resp = (sents*)malloc(sizeof(sents));
    resp->first = first;
    return resp;
}
