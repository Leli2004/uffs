#include <stdio.h>
#include "frac.h"

// gcc -Wall usaFrac.c frac.c -lm -o frac

int main() {
    Frac f1, f2;

    f1 = setFrac(2, 3);
    f2 = setFrac(1, 4);

    printFrac(f1);
    printFrac(f2);

    Frac fMulti = multFrac(f1, f2);
    printFrac(fMulti);

    Frac fDiv = divFrac(f1, f2);
    printFrac(fDiv);

    return 0;
}
