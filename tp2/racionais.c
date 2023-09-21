#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int aleat(int min, int max) {
    return min + rand() % (max - min + 1);
}

int mdc(int a, int b) {
    int aux;

    if (b == 0)
        return a;

   while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int mmc(int a, int b) {
    if (a == 0 || b == 0)
        return (0);

    return ((a * b) / mdc(a, b));
}

int valido_r(struct racional r) {
    if (r.den != 0)
        return 1;

    return 0;
}

struct racional sorteia_r(int max) {

    int numerador = aleat(0, max);
    int denominador = aleat(0, max);

    return (cria_r(numerador, denominador));
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

int numerador_r(struct racional r) {
    return r.num;
}

int denominador_r(struct racional r) {
    return r.den;
}

void imprime_r(struct racional r) {
    if (valido_r(r) == 0) {
        printf("INVALIDO ");
        return;
    }
        if (r.num == 0) {
            printf("0 ");
        } else if (r.den == 1) {
            printf("%d ", r.num);
        } else if (r.num == r.den) {
            printf("1 ");
        } else if (r.num < 0 || r.den < 0) {
            printf("-");
            printf("%d/%d ", abs(r.num), abs(r.den));
        } else {
            printf("%d/%d ", r.num, r.den);
        }
    }   

// compara os racionais para poder retornar um valor e conseguir ordenar o vetor.
int compara_r(struct racional r1, struct racional r2) {
    if (!valido_r(r1) || !valido_r(r2)) {
        return 0;
    }

    // criação de denominador comum 
    int den_aux = mmc(r1.den, r2.den);

    // cria resultado localmente 
    int res1 = (den_aux / r1.den) * r1.num;
    int res2 = (den_aux / r2.den) * r2.num;

    if (res1 < res2) {
        return -1;
    }

    if (res1 > res2) {
        return 1;
    }

    return 0;
}

int simplifica_r(struct racional *r) {
    if (!r->valido)
        return 0;

  
    int mdc_numeros = mdc(r->num, r->den);

  
    r->num = r->num / mdc_numeros;
    r->den = r->den / mdc_numeros;

    
    if (r->den < 0) {
        r->num = r->num * -1;
        r->den = r->den * -1;
    }

    if (r->den < 0 && r->num < 0) {
        r->den = r->den * -1;
        r->num = r->num * -1;
    }

    return 1;
}

int soma_r(struct racional r1, struct racional r2, struct racional *r3) {
    
    if (!valido_r(r1) || !valido_r(r2)) {
        r3->valido = 0;
        r3->num = 0;
        r3->den = 0;

        return 0;
    }
    else {

        
        int den_aux = mmc(r1.den, r2.den);
        int num = r1.num * (den_aux / r1.den) + r2.num * (den_aux / r2.den);

       
        r3->valido = 1;
        r3->num = num;
        r3->den = den_aux;

        simplifica_r(r3);

        return 1;
    }
}

int subtrai_r(struct racional r1, struct racional r2, struct racional *r3) {

    if (!valido_r(r1) || !valido_r(r2)) {

        r3->valido = 0;
        r3->num = 0;
        r3->den = 0;

        return 0;
    }
    else {

        
        r3->valido = 1;
        r3->num = (r1.num * r2.den) - (r2.num * r1.den);
        r3->den = r1.den * r2.den;

        simplifica_r(r3);

        return (1);
    }
}

int multiplica_r(struct racional r1, struct racional r2, struct racional *r3) {
   
    if (!valido_r(r1) || !valido_r(r2)) {
        r3->valido = 0;
        r3->num = 0;
        r3->den = 0;

        return 0;
    }
    else {

        r3->valido = 1;
        r3->num = r1.num * r2.num;
        r3->den = r1.den * r2.den;

        simplifica_r(r3);

        return 1;
    }
}

int divide_r(struct racional r1, struct racional r2, struct racional *r3) {
    
    if (!valido_r(r1) || !valido_r(r2)) {
        r3->valido = 0;
        r3->num = 0;
        r3->den = 0;

        return 0;
    }
    else {

        r3->valido = 1;
        r3->num = r1.num * r2.den;
        r3->den = r1.den * r2.num;

        simplifica_r(r3);

        return 1;
    }
}
