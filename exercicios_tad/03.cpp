#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct Funcionario {
    char nome[50];
    char cargo[50];
    int salario_base;
    int beneficios;
    int descontos;

    int salarioLiquido() {
       int salario_liquido = (salario_base + beneficios) - descontos;
       return salario_liquido;

    }
};

struct Loja {
    struct Funcionario *funcionarios;
    int quantidade_funcionarios;

    void cadastrarFuncionario(int n) {
        quantidade_funcionarios = n;
        funcionarios = (Funcionario *) malloc(n * sizeof(Funcionario));
        for (int i = 0; i < n; i++){
            printf("Nome: \n");
            scanf("%s", funcionarios[i].nome);
            printf("Cargo: \n");
            scanf("%s", funcionarios[i].cargo);
            printf("Salario base: \n");
            scanf("%d", &funcionarios[i].salario_base);
            printf("Beneficios: \n");
            scanf("%d", &funcionarios[i].beneficios);
            printf("Descontos: \n");
            scanf("%d", &funcionarios[i].descontos);
        }

    }

    void imprimirFuncionario() {
        for (int i = 0; i < quantidade_funcionarios; i++){
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Salario: %d\n", funcionarios[i].salario_base);
            printf("Beneficios: %d\n", funcionarios[i].beneficios);
            printf("Descontos: %d\n", funcionarios[i].descontos);
            printf("Salario liquido: %d\n", funcionarios[i].salarioLiquido());
        }
    }

    void mediaSalarial() {
        int soma;
        for (int i = 0; i < quantidade_funcionarios; i++){
            soma = funcionarios[i].salario_base + funcionarios[i].salario_base;
        }
        int resultado = soma/quantidade_funcionarios;
        printf("Media Salarial: %d\n", resultado);

    }

    void maiorSalario() {
        int maior_salario = 0;
        char nome_funcionario[50];
        for (int i = 0; i < quantidade_funcionarios; i++) {
            if (funcionarios[i].salario_base > maior_salario) {
                maior_salario = funcionarios[i].salario_base;
                strcpy(nome_funcionario, funcionarios[i].nome);
            }
        }
        printf("O maior salario e: %s\n", nome_funcionario);


    }
};

int main(){
    struct Loja loja;
    int tam;

    printf("DIGITE A QUANTIDADE DE FUNCIONARIOS\n");
    scanf("%d", &tam);

    if (tam > 10){
        printf("O limite nao pode ser maior que 10");
        return 0;
    }

    loja.cadastrarFuncionario(tam);
    loja.imprimirFuncionario();
    loja.mediaSalarial();
    loja.maiorSalario();


    return 0;
}
