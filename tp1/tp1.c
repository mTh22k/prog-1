/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main (){

     srand(time(NULL)); 

     int numerador = aleat(1, 100); 
     int denominador = aleat(1, 100);

     struct racional r = cria_r(numerador, denominador);

    
    printf("Racional original: %d/%d\n", r.num, r.den);

    struct racional r_simplificado = simplifica_r(r);

    printf("Racional simplificado: %d/%d\n", r_simplificado.num, r_simplificado.den);


    

    return 0;
}
