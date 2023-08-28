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

struct racional sorteia_r(int n) {

    int numerador = aleat(0,n);
    int denominador = aleat(0,n);
    return cria_r(numerador, denominador);
}

void imprime_r(struct racional r) {
    if (valido_r(r) == 0) {
        printf("INVALIDO ");
        return;
    }

      if (r.num == 0) {
        printf("0");
    } else if (r.den == 1) {
        printf("%d ", r.num);
    } else if (r.num == r.den) {
        printf("1 ");
    } else if (r.num == -r.den) {
        printf("-1 ");
    } else if (r.num < 0 && r.den < 0) {
        printf("%d/%d ", -r.num, -r.den);
    } else if (r.num < 0) {
        printf("-%d/%d ", -r.num, r.den);
    } else {
        printf("%d/%d ", r.num, r.den);
    }
}
int valido_r(struct racional r) {
    return r.valido == 1;
}

struct racional soma_r(struct racional r1, struct racional r2) {
    struct racional result;

    int mmc_den = mmc(r1.den, r2.den);

    int numerador1 = r1.num * (mmc_den / r1.den);
    int numerador2 = r2.num * (mmc_den / r2.den);

    result.num = numerador1 + numerador2;
    result.den = mmc_den;
    result.valido = 1;

    return simplifica_r(result);
}

struct racional subtrai_r(struct racional r1, struct racional r2) {
    struct racional resultado;

    int mmc_den = mmc(r1.den, r2.den);

    int num1 = r1.num * (mmc_den / r1.den);
    int num2 = r2.num * (mmc_den / r2.den);

    resultado.num = num1 - num2;
    resultado.den = mmc_den;
    resultado.valido = 1;

    return simplifica_r(resultado);
}

struct racional multiplica_r(struct racional r1, struct racional r2) {
    struct racional resultado;

    resultado.num = r1.num * r2.num;
    resultado.den = r1.den * r2.den;
    resultado.valido = 1;

    return simplifica_r(resultado);
}

struct racional divide_r(struct racional r1, struct racional r2) {
    struct racional resultado;

    resultado.num = r1.num * r2.den;
    resultado.den = r1.den * r2.num;

    if (resultado.den == 0) {
        resultado.valido = 0;
        resultado.num = 0;
        resultado.den = 0;
    } else {
        resultado.valido = 1;
    }

    return simplifica_r(resultado);
}


