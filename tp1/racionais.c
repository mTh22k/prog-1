#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* acrescente demais includes que voce queira ou precise */



int aleat(int min, int max) {
    return min + rand() % (max - min + 1);
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

struct racional cria_r(int numerador, int denominador) {
    struct racional r;

    if (denominador == 0) {
        r.valido = 0; 
        r.num = 0;
        r.den = 0;
    } else {
        r.valido = 1; 
        r.num = numerador;
        r.den = denominador;
    }

    return r;
}

struct racional simplifica_r(struct racional r) {
    if (r.num == 0) {
        r.valido = 1; 
        r.den = 1;
        return r;

    }

    int res = mdc(r.num, r.den);
    r.num /= res;
    r.den /= res;

    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

    return r;
}


