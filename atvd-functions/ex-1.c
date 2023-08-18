#include <stdio.h>

void verifica_nulo (int n) {
    if (n == 0) {

        printf("nulo\n");

    } else {

        printf("nao nulo\n");
    }

    return;
}

int main () {

    int num;

    scanf("%d",&num);

    verifica_nulo(num);



    return 0;
}
