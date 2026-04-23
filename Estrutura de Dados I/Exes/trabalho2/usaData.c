#include <stdio.h>
#include "data.h"

// gcc -Wall usaData.c data.c -lm -o data

// int main() {
//     data d1, d2;

//     setDate(&d1,10,10,2026);

//     setDate(&d2,1,11,2026);

//     showDate(d1);

//     printf("Ano: %d\n", getDate(d2,'Y')); // Y define ano

//     printf("Diferença: %d dias\n", getDiff(d1,d2));

//     return 0;
// }

int main() {
    data d1, d2;

    // Criar datas
    setDate(&d1, 10, 10, 2026);
    setDate(&d2, 1, 11, 2026);

    // Mostrar datas
    printf("Data 1: ");
    showDate(d1);

    printf("Data 2: ");
    showDate(d2);

    printf("\n");

    // Testar getDate
    printf("Ano da Data 2: %d\n", getDate(d2, 'Y'));
    printf("Mes da Data 1: %d\n", getDate(d1, 'M'));
    printf("Dia da Data 1: %d\n", getDate(d1, 'D'));

    printf("\n");

    // Comparar datas
    int comp = dataComp(d1, d2);

    if (comp == 1)
        printf("Data 1 é maior que Data 2\n");
    else if (comp == -1)
        printf("Data 2 e maior que Data 1\n");
    else
        printf("As datas são iguais\n");

    printf("\n");

    // Diferença entre datas
    int diff = getDiff(d1, d2);
    printf("Diferença entre datas é de %d dias\n", diff);

    printf("\n");

    // Verificar ano bissexto
    if (isLeapYear(getDate(d1, 'Y')))
        printf("Ano de d1 é bissexto\n");
    else
        printf("Ano de d1 nao é bissexto\n");

    printf("\n");

    // Dias transcorridos no ano
    int diasAno = getDayFromYear(d1);
    printf("Dias transcorridos no ano ate d1: %d\n", diasAno);

    return 0;
}
