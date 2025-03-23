#include<stdio.h>
#include <stdlib.h>


struct Data {
    int dia;
    int mes;
    int ano;
    int data_atual_dia = 22;
    int data_atual_mes = 03;
    int data_atual_ano = 2025;


};

struct Cliente {
    char nome[50];
    int idade;
    char sexo[1];
    struct Data data;

    void calcularIdade(){
        int idade_cliente = data.data_atual_ano - data.ano;
        if (data.mes > data.data_atual_mes) {
            idade = idade_cliente - 1;
        }
        else if (data.mes < data.data_atual_mes) {
            idade = idade_cliente;
        }
        else {
            if (data.dia <= data.data_atual_dia){
                idade = idade_cliente;
            }
            else if (data.dia > data.data_atual_dia){
                idade = idade_cliente - 1;
            }
        }
    }

};

int main() {
    struct Data d;
    struct Cliente c[50];

    int i;
    char n[50];
    char s[1];
    int opcao;


    while (opcao != 3){
        printf("BEM-VINDO\n");
        printf("OPCAO 1: CADASTRAR CLIENTE\n");
        printf("OPCAO 2: LISTAR CLIENTE\n");
        printf("OPCAO 3: SAIR\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            for (i = 0; i < 50; i ++){
                printf("NOME:\n");
                scanf("%s", c[i].nome);

                printf("SEXO:\n");
                scanf("%s", c[i].sexo);

                printf("DATA DE NASCIMENTO:\n");
                scanf("%d %d %d", &c[i].data.dia, &c[i].data.mes, &c[i].data.ano);

                c[i].calcularIdade();

                printf("DIGITE 1 PARA CONTINUAR\n");
                printf("DIGITE 0 PARA VOLTAR\n");
                scanf("%d", &opcao);
                if (opcao == 0){
                    break;
                }
            }
        }
        else if (opcao == 2){
            for (i = 0; i < sizeof(c) / sizeof(c[0]); i++){
                printf("NOME: %s\n", c[i].nome);

                printf("SEXO: %s\n", c[i].sexo);

                printf("DATA DE NASCIMENTO: %d %d %d\n", c[i].data.dia, c[i].data.mes, c[i].data.ano);

                printf("IDADE: %d\n", c[i].idade);
            }
        }
        else if (opcao == 3){
            return 0;
        }
    }


    return 0;
}
