#include <stdio.h>

void verifica_positivo (int n) {
    if (n >= 0) {

        printf("positivo\n");

    } else {

        printf("negativo\n");
    }

    return;
}

int main () {

    int num;

    scanf("%d",&num);

    verifica_positivo(num);



    return 0;
}
