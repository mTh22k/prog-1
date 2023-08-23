/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
    srand(time(NULL)); 

    struct racional r1 = sorteia_r(100);
    struct racional r2 = sorteia_r(100);

    printf("Numeros Racionais:\n");
    imprime_r(r1);
    imprime_r(r2);

    // Simplifique os racionais
    struct racional novo_r1 = simplifica_r(r1);
    struct racional novo_r2 = simplifica_r(r2);

    printf("Numeros Racionais Simplificados:\n");
    imprime_r(novo_r1);
    imprime_r(novo_r2);

    struct racional soma = soma_r(novo_r1, novo_r2);
    struct racional subtracao = subtrai_r(novo_r1, novo_r2);
    struct racional multiplicacao = multiplica_r(novo_r1, novo_r2);
    struct racional divisao = divide_r(novo_r1, novo_r2);

    printf("\nSoma:\n");
    imprime_r(soma);

    printf("\nSubtracao:\n");
    imprime_r(subtracao);

    printf("\nMultiplicacao:\n");
    imprime_r(multiplicacao);

    printf("\nDivisao:\n");
    imprime_r(divisao);

    return 0;
}