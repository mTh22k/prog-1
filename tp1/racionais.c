#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* acrescente demais includes que voce queira ou precise */

int aleat(int min, int max) {
    srand(time(NULL));

    int numAleatorio = min + rand() % (max - min + 1);

    return numAleatorio;
}

int mdc (int a, int b) {

    int aux;

    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int mmc (int a, int b) {
     return (a * b) / mdc(a, b);
}

