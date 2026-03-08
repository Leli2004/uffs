#include <stdio.h>

/******************************************/
// Gerar build: gcc -Wall aula1.c -o aula1
// Buildar: ./aula1
/******************************************/

void exe01();
void exe02();
void exe03();
void exe04();
void exe05();
void exe06();
void exe07();
void exe08();
void exe09();
void exe10();

int main() {
    int opcao;

    printf("Escolha o exercício (1 a 10): ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            exe01();
            break;
        case 2:
            exe02();
            break;
        case 3:
            exe03();
            break;
        case 4:
            exe04();
            break;
        case 5:
            exe05();
            break;
        case 6:
            exe06();
            break;
        case 7:
            exe07();
            break;
        case 8:
            exe08();
            break;
        case 9:
            exe09();
            break;
        case 10:
            exe10();
            break;
        default:
            printf("Exercício inválido.\n");
    }

    return 0;
}

/* EXERCÍCIO 1 */
/* Faça um programa que peça o número de horas trabalhadas e o valor da hora de um
determinado funcionário. Em seguida, calcule o salário do funcionário. 
Caso horas trabalhadas for maior que 200 horas, o salário final é acrescido de 5%.
*/
void exe01() {
    float valorHora, horas = 0;

    printf("\nInforme...\n");

    printf("Valor da hora: R$");
    scanf("%f", &valorHora);
    
    printf("Horas trabalhadas: ");
    scanf("%f", &horas);

    float salario = valorHora * horas;

    if (horas > 200) {
        salario += (salario/100)*5;
    } 
    printf("Salário: R$%.2f \n\n", salario);
}

/* EXERCÍCIO 2 */
/* Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem
um desconto de 5% e a prazo um acréscimo de 10%. Faça um programa em C que peça o preço
do produto e a forma de pagamento: 1 para à vista e 2 para a prazo. Depois apresente o preço
final do produto */
void exe02() {
    float preco = 0;
    int tPag;

    printf("\nInforme...\n");

    printf("Preço do produto: R$");
    scanf("%f", &preco);

    printf("Tipo pagamento (1 para à vista e 2 para a prazo): ");
    scanf("%d", &tPag);

    float result;
    
    if (tPag == 1) {
        result = preco - (preco/100*5);
        printf("Preço final do produto: R$%.2f \n\n", result);
    } else if (tPag == 2) {
        result = preco + (preco/100*10);
        printf("Preço final do produto: R$%.2f \n\n", result);
    } else {
        printf("Tipo de pagamento é inválido.");
    }
}

/* EXERCÍCIO 3 */
/* Faça um programa que calcule a duração de um evento qualquer. Para tal, o programa pede a
hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23. Perceba que
um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais
de 24 horas.*/
void exe03() {
    int horaIni, horaFim = 0;
    int horasTotais = 0;

    printf("\nInício: ");
    scanf("%d", &horaIni);

    printf("Fim: ");
    scanf("%d", &horaFim);

    if (horaFim >= horaIni) {
        horasTotais = horaFim - horaIni;
    } else {
        horasTotais = (24 - horaIni) + horaFim;
    }

    
    printf("Duração: %d\n" , horasTotais);
}

/* EXERCÍCIO 4 */
/* Faça um programa que peça 4 números inteiros. Em seguida, apresente quantos números
informados são negativos e quantos são positivos (considere o 0 como positivo).*/
void exe04() {
    int n = 0;
    int positivos, negativos = 0;

    printf("\nInforme 4 números inteiros:\n");

    for(int i=0; i<4; i++) {
        scanf("%d", &n);
        if (n >= 0) {
            positivos++;
        } else {
            negativos++;
        }
    }

    printf("%d (+) e %d (-) \n", positivos, negativos);
}

/* EXERCÍCIO 5 */
/* Faça um programa que simule a multiplicação por meio de adições. Para tal serão pedidos os dois
operandos. Por exemplo se for informado 3 e 4, deverá ser calculado, usando a soma, 3∗4, ou seja, 12.
Este cálculo é feito somando o primeiro valor informado por ele mesmo o número de vezes representada
pelo segundo número. Nesse exemplo, o três seria somado quatro vezes: 3+3+3+3, resultando 12.*/
void exe05() {
    int n1, n2 = 0;
    int resultado = 0;

    printf("Primeiro número: ");
    scanf("%d", &n1);

    printf("Segundo número: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        resultado += n1;
    }

    printf("Resultado: %d \n", resultado);
}

/* EXERCÍCIO 6 */
/* Faça um programa que peça uma valor e imprima a soma de todos os números de 1 até o valor
informado.*/
void exe06() {
    int n = 0;
    int soma = 0;

    printf("Informe um número: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma: %d \n", soma);
}

/* EXERCÍCIO 7 */
/* Dada uma sequência de n números (um número menor ou igual à 0 finaliza a sequência), apresentar o
percentual de números informados que são maiores ou igual a 10 e menores ou igual a 20.*/
void exe07() {
    int numero = 0;
    int total = 0;
    int result = 0;

    while (1) {
        printf("Número: ");
        scanf("%d", &numero);

        if (numero <= 0) {
            break;
        }

        total++;

        if (numero >= 10 && numero <= 20) {
            result++;
        }
    }

    if (total > 0) {
        float perc = (result * 100.0) / total;
        printf("%% entre 10 e 20: %.2f%% \n", perc);
    }
}

/* EXERCÍCIO 8 */
/* Faça um programa que peça o salário e o número de filhos dos habitantes de uma região. Quando o
salário informado for menor que zero, as entradas são finalizadas e serão apresentadas as médias salarial
e de filhos informados. */
void exe08() {
    float salario = 0;
    int filhos = 0;

    float somaSalario = 0;
    int somaFilhos, total = 0;

    while (1) {
        printf("Salário: ");
        scanf("%f", &salario);

        if (salario < 0) {
            break;
        }

        printf("Filhos: ");
        scanf("%d", &filhos);

        somaSalario += salario;
        somaFilhos += filhos;
        total++;
    }

    if (total > 0) {
        printf("Média salários: %.2f \n", somaSalario / total);
        printf("Média filhos: %.2f \n", (float)somaFilhos / total);
    }
}

/* EXERCÍCIO 9 */
/* Um professor gostaria de ter um programa para calcular a média final de seus alunos. Para isso, ele
informa a matrícula e as 5 notas que o alunos teve durante o semestre. Após informar as 5 notas, o
programa imprime a matrícula do aluno e a média que obteve (média aritmética simples). Quando o
professor digitar 0 na matrícula, o programa finaliza e apresenta a média geral da turma. Proibido colocar
5 scanf para pedir as notas.*/
void exe09() {
    int matricula;
    float nota;
    float somaNotas;
    float mediaAluno;

    float somaMedias = 0;
    int totalAlunos = 0;

    while (1) {
        printf("\nMatrícula: ");
        scanf("%d", &matricula);

        if (matricula == 0) {
            break;
        }

        somaNotas = 0;

        for (int i = 1; i <= 5; i++) {
            printf("Nota %d: ", i);
            scanf("%f", &nota);
            somaNotas += nota;
        }

        mediaAluno = somaNotas / 5;

        printf("Aluno: %d Média: %.2f \n", matricula, mediaAluno);

        somaMedias += mediaAluno;
        totalAlunos++;
    }

    if (totalAlunos > 0) {
        printf("Média geral da turma: %.2f \n", somaMedias / totalAlunos);
    }
}

/* EXERCÍCIO 10 */
/* Faça um programa para calcular o fatorial de um número dado. O fatorial de um número n é n × (n − 1)
× (n − 2) × . . . × 1, por definição o fatorial de 0 e 1 é 1. Por exemplo, o fatorial de 5 é 120, ou seja, 5 × 4 ×
3 × 2 × 1 (perceba que não seria necessário fazer a última multiplicação já que 1 é o elemento neutro da
multiplicação).*/
void exe10() {
    int n;
    int fatorial = 1;

    printf("Número: ");
    scanf("%d", &n);

    for (int i = n; i > 1; i--) {
        fatorial *= i;
    }

    printf("Fatorial: %d \n", fatorial);
}
