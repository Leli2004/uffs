#include <stdio.h>

struct tData {
    int dia;
    int mes;
    int ano;
};
typedef struct tData Data;

struct tfraction {
    int numerador;
    int denominador;
};
typedef struct tfraction Fraction;

struct tAluno {
    int id;
    char *nome;
    float n1;
    float n2;
    float n3;
};
typedef struct tAluno Aluno;

Aluno alunos[100];
int total = 0;

int extraiDia(Data);
int comparaDatas(Data, Data);
Fraction setFraction(int, int);
Aluno setAluno(int, char *nome, float, float, float);
void printAluno(Aluno);
void appendAluno(Aluno);
void printAlunos(Aluno alunos[], int total);

int main() {
    Aluno novoAluno1 = setAluno(1, "Ana", 8, 9, 10);
    appendAluno(novoAluno1);

    Aluno novoAluno2 = setAluno(2, "Beatriz", 6, 7, 9);
    appendAluno(novoAluno2);

    printAlunos(alunos, total);

    return 0;
}

// Retorna o dia que compõe a data passada como parâmetro (data).
int extraiDia(Data data) {
    return data.dia;
}

// Retorna -1 se a data data1 é anterior à data data2, 1 se a data data1 é posterior à data data2 e 0 se as datas data1 e data2 são iguais.
int comparaDatas(Data data1, Data data2) {
    // Compara ano
    if (data1.ano < data2.ano) {
        return -1;
    } else if (data1.ano > data2.ano) {
        return 1;
    }

    // Se os anos são iguais, compara meses
    if (data1.mes < data2.mes) {
        return -1;
    } else if (data1.mes > data2.mes) {
        return 1;
    }

    // Se os meses também são iguais, compara dias
    if (data1.dia < data2.dia) {
        return -1;
    } else if (data1.dia > data2.dia) {
        return 1;
    }

    // Se tudo é igual
    return 0;
}

// Exemplo -> Fraction
Fraction setFraction(int n, int d) {
    Fraction f;
    f.numerador = n;
    f.denominador = d;
    return f;
}

// Exemplo -> estudantes
Aluno setAluno(int id, char *nome, float n1, float n2, float n3) {
    Aluno a;
    a.id = id;
    a.nome = nome;
    a.n1 = n1;
    a.n2 = n2;
    a.n3 = n3;
    return a;
}

void printAluno(Aluno a) {
    printf("Aluno Id=%d, nome=%s \n", a.id, a.nome);
}

void appendAluno(Aluno a) {
    alunos[total++] = a;
}

void printAlunos(Aluno alunos[], int total) {
    for (int i=0; i<total; i++) {
        printf("Aluno Id=%d, nome=%s \n", alunos[i].id, alunos[i].nome);
    }
}
