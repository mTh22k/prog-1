#include <stdio.h>

struct data {
    int dia, ano;
    char mes[10];
};

struct paciente {
    char nome[30];
    short idade;
    char sexo[10];
    char cpf[16];
    char cargo[20];
    int salario;
    short codigo;
    struct data dias;
};

int main() {
    struct paciente paciente_1;

    printf("digite o nome do paciente : ");
    scanf("%s", paciente_1.nome);

    printf("digite a idade do paciente : ");
    scanf("%hd", &paciente_1.idade);

    printf("digite o sexo do paciente : ");
    scanf("%s", paciente_1.sexo);

    printf("digite o cpf do paciente : ");
    scanf("%s", paciente_1.cpf);

    printf("digite o cargo do paciente : ");
    scanf("%s", paciente_1.cargo);

    printf("digite o salario do paciente : ");
    scanf("%d", &paciente_1.salario);

    printf("digite o codigo do setor do paciente : ");
    scanf("%hd", &paciente_1.codigo);

    printf("digite o dia do nascimento : ");
    scanf("%d", &paciente_1.dias.dia);

    printf("digite o mes do nascimento : ");
    scanf("%s", paciente_1.dias.mes);

    printf("digite o ano do nascimento : ");
    scanf("%d", &paciente_1.dias.ano);

    printf("o nome do paciente é : %s\n", paciente_1.nome);
    printf("a data de nascimento do paciente é : %d/%s/%d\n", paciente_1.dias.dia, paciente_1.dias.mes, paciente_1.dias.ano);

    return 0;
}
