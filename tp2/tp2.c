#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void imprime_vet(int n, struct racional vet[])
{

    for (int i = 0; i <= n; i++)
    {
        imprime_r(vet[i]);
    }
    printf("\n");
}

void verifica_valido(int n, struct racional vet[])
{
    int j = 0;

    for (int i = 0; i <= n; i++)
    {
        if (valido_r(vet[i]) != 0)
        {
            vet[j] = vet[i];
            j++;
        }
    }

    n = j - 1; // atualiza o tamanho do vetor a partir de n
}

void sorteia(int n, struct racional vet[], int max)
{

    for (int i = 0; i <= n; i++)
    {
        vet[i] = sorteia_r(max);
    }
}

struct racional *soma_racional(int n, struct racional vet[], struct racional *somat)
{

    for (int i = 0; i <= n; i++)
    {
        struct racional resultado;

        if (soma_r(*somat, vet[i], &resultado) && valido_r(resultado))
            *somat = resultado;
    }
    return somat;
}

void ordena(int n, struct racional vet[])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (compara_r(vet[j], vet[j + 1]) == 1)
            {
                struct racional temp;

                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 0;
    int max = 0;

    srand(0);

    do
    {
        printf("digite um valor para n entre 0 e 100 : ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    do
    {
        printf("digite um valor para max ate 30 : ");
        scanf("%d", &max);
    } while (max <= 0 || max > 30);

    struct racional v[n];

    sorteia(n, v, max);

    imprime_vet(n, v);

    verifica_valido(n, v);

    imprime_vet(n, v);

    ordena(n, v);

    imprime_vet(n, v);

    struct racional somat;

    somat = cria_r(0, 1);

    soma_racional(n, v, &somat);

    printf("a soma de todos os elementos e: ");
    imprime_r(somat);
    printf("\n");

    return 0;
}
