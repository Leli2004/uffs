#include <stdio.h>

struct tfrac {
    int numerador;
    int denominador;
};
typedef struct tfrac Frac;

void printFrac(Frac);
Frac setFrac(int, int);
Frac multFrac(Frac, Frac);
Frac divFrac(Frac, Frac);
