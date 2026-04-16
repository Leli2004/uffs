#include <stdio.h>
#include "frac.h"

void printFrac(Frac f) {
    printf("%d/%d \n", f.numerador, f.denominador);
    return;
}

Frac setFrac(int num, int dem) {
    Frac f;
    f.numerador = num;
    f.denominador = dem;
    // Frac f={n, d};
    return f;
}

Frac multFrac(Frac f1, Frac f2) {
    Frac result;
    result.numerador = f1.numerador * f2.numerador;
    result.denominador = f1.denominador * f2.denominador;
    return result;
}

Frac divFrac(Frac f1, Frac f2) {
    Frac result;
    result.numerador = f1.numerador * f2.denominador;
    result.denominador = f1.denominador * f2.numerador;
    return result;
}
