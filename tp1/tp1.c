/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
    srand(time(NULL)); 

    int n;
    scanf("%d", &n);
    int max;
    scanf("%d", &max);


    for (int  i = 1; i <= n; i++)
    {

        struct racional r1 = sorteia_r(max);
        struct racional r2 = sorteia_r(max);

        printf("%d: ",i);

        imprime_r(r1);
        imprime_r(r2);

         if (!valido_r(r1) || !valido_r(r2)) 
                printf("NUMERO INVALIDO ");

        struct racional novo_r1 = simplifica_r(r1);
        struct racional novo_r2 = simplifica_r(r2);

        imprime_r(novo_r1);
        imprime_r(novo_r2);

        struct racional soma = soma_r(novo_r1, novo_r2);
        struct racional subtracao = subtrai_r(novo_r1, novo_r2);
        struct racional multiplicacao = multiplica_r(novo_r1, novo_r2);
        struct racional divisao = divide_r(novo_r1, novo_r2);

        imprime_r(soma);
        imprime_r(subtracao);
        imprime_r(multiplicacao);

        if (!valido_r(divisao)) { 
        printf("DIVISAO INVALIDA ");
        } else {
            imprime_r(divisao);
        }

        printf("\n");

    }
    


    return 0;
}