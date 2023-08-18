#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verifica_positivo (int n) {
    if (n >= 0) {

        return 1;

    } else {

        return 0;
    }
}

void verifica_nulo (int n) {
    if (n == 0) {
        printf("\na é nulo, nao foi possivel executar o programa.\n");
        exit(0);

    } else {

        return;
    }
}

void calc_equacao (double n1, double n2, double n3, double delta) {
    
    double x1;
    double x2;

    x1 = (-n2 + sqrt(delta))/(2*n1);
    x2 = (-n2 - sqrt(delta))/(2*n1);

    printf("\nas raizes da equação são : %f e %f\n", x1,x2);

    return;
}

void calc_complexa (double n1, double n2, double n3, double delta) {
    
    double aux;
    double aux2;

    aux = -n2/(2*n1);
    aux2 = sqrt(-delta)/(2*n1);

    printf("\nas raizes complexas são : x1 = %f + %f.i e x2 = %f - %f.i\n\n", aux,aux2,aux,aux2);

    return;
}

int calc_delta (int n1, int n2, int n3) {
    
    int aux;

    n2 = n2*n2;
    n1 = -4*n1;
    n3 = n1*n3;
    aux = n2 + n3;

    return aux;
}


int main () {

    int a;
    int b;
    int c;
    int res;
    int verifica;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    verifica_nulo (a);
    res = calc_delta (a,b,c);
    verifica = verifica_positivo (res);

    if (verifica == 1) {
        calc_equacao (a,b,c,res);
    } else {
        calc_complexa (a,b,c,res);
    }
    
    



    return 0;
}