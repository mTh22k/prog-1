#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int max = 0;
    int i = 0;
    int j = 0;

    srand(0);

    do {
        printf("digite um valor para n entre 0 e 100 : ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100); 

    do {
        printf("digite um valor para max ate 30 : ");
        scanf("%d", &max);
    } while (max <= 0 || max > 30);

    struct racional v[n];

    for (i = 0; i <= n; i++) {
        v[i] = sorteia_r(max);
    } 

    for (i = 0; i <= n; i++) {
        imprime_r(v[i]);
    }
    printf("\n");

    for (i = 0; i <= n; i++) {
        if (valido_r(v[i]) != 0) {
            v[j] = v[i];
            j++;
        }
    } 

    n = j - 1; // atualiza o tamanho do vetor a partir de n

    for (i = 0; i <= n; i++) {
        imprime_r(v[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            if (compara_r(v[j], v[j + 1]) == 1) {
                struct racional temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            } 
        }
    }

    for (i = 0; i <= n; i++)
    {
        imprime_r(v[i]);
    }
    printf("\n");

    struct racional somat = cria_r(0, 1);

    for (i = 0; i <= n; i++)
    {
        struct racional resultado; 

        if (soma_r(somat, v[i], &resultado) && valido_r(resultado)) 
            somat = resultado;                                      
    }                         

    printf("a soma de todos os elementos e: ");
    imprime_r(somat);
    printf("\n");

    return 0;
}
