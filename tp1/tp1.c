/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main (){

    struct racional r;

    r.num = aleat(1, 100);
    r.den = aleat(1, 100);
    
    printf("%d",r.den);

    return 0;
}
