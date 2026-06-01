#include <stdio.h>

struct funcionario {
    int id;
    int idade;
    float salario;
    struct funcionario *next;
    struct funcionario *prev;
};
typedef struct funcionario Func;

Func *inserePrimeiroElemento(Func *first, int id, int idade, float salario);
Func *insereElementoNoInicio(Func *first, int id, int idade, float salario);
Func *insereElementoNoFim(Func *last, int id, int idade, float salario);
Func *insereElementoNoMeio(Func *first, int idReferencia, int id, int idade, float salario);
Func *deletaElemento(Func *first, int idDelete);
void listaElementos(Func *first);
void listaElementoPorId(Func *first, int id);

typedef struct listaInt {
    int valor;
    struct listaInt *prev;
    struct listaInt *next;

} ListaInt;

ListaInt *constroiLista (int n, int *v);
void printListaInt(ListaInt *first);
