#include <stdio.h>
#include "data.h"

// setDate atribui dia, mês e ano para o tipo Date criado
void setDate(data *d, int day, int month, int year) {
    d->day = day;
    d->month = month;
    d->year = year;
    return;
}

// getDate retorna o dia ou o mês ou o ano de uma data passada como parâmetro
// o tipo de retorno deve ser passado como parâmetro também
int getDate(data d, char type) {
    switch (type) {
        case 'Y':
        case 'y':
            return d.year;

        case 'M':
        case 'm':
            return d.month;

        case 'D':
        case 'd':
            return d.day;
    }

    printf("\nERRO em getData: type é inválido.");
    return 0;
}

// showDate mostra a data em um formato amigável para o usuário
void showDate(data d) {
    printf("\nData: %.2d/%.2d/%.4d \n", d.day, d.month, d.year);
}

// dataComp compara as duas datas dos parâmetros.
// retorna 1 se d1 é maior, -1 se d2 é maior e 0 se são iguais
int dataComp(data d1, data d2) {
    // Comparar ano
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    }

    // Se os anos são iguais, compara meses
    if (d1.month < d2.month) {
        return -1;
    } else if (d1.month > d2.month) {
        return 1;
    }

    // Se os meses também são iguais, compara dias
    if (d1.day < d2.day) {
        return -1;
    } else if (d1.day > d2.day) {
        return 1;
    }

    // Se tudo é igual
    return 0;
}

// getDiff retorna a diferença absoluta entre d1 e d2
int getDiff(data d1, data d2) {
    int result = 0;
    int total1 = calculaDiasByDate(d1);
    int total2 = calculaDiasByDate(d2);

    result = total1 - total2;
    if (result < 0) {
        result = -result;
    }

    return result;
}

int calculaDiasByDate(data d) {
    int total;
    int year = d.year - 1;

    // dias dos anos anteriores
    total = year * 365;

    // adicionar anos bissextos (mesma lógica de isLeapYear)
    total += year / 4;
    total -= year / 100;
    total += year / 400;

    // adicionar dias do ano atual
    total += getDayFromYear(d);

    return total;
}

// isLeapYear retorna 1 se o ano do parâmetro é bissexto, e 0 se não for
int isLeapYear(int y) {    
    // Regra para ano bissexto: 
    // divisível por 400 = bissexto
    // divisível por 4 e não por 100 = bissexto
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        return 1;
    }
    return 0;
}

// getDayFromYear retorna o número de dias trasncorridos desde o início do ano até a data do parâmetro
int getDayFromYear(data d) {
    int result = d.day;

    switch (d.month) {
        case 12: result += 31;
        case 11: result += 30;
        case 10: result += 31;
        case 9:  result += 30;
        case 8:  result += 31;
        case 7:  result += 31;
        case 6:  result += 30;
        case 5:  result += 31;
        case 4:  result += 30;
        case 3: result += 31;
        case 2:
            if (isLeapYear(d.year))
                result += 29;
            else
                result += 28;
    }

    return result;
}
