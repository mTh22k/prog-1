#include <stdio.h>

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

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    res = calc_delta(a,b,c);
    printf("%d\n", res);



    return 0;
}
