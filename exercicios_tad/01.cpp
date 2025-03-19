#include<stdio.h>


struct Data {
    int dia;
    int mes;
    int ano;
    int data_atual_dia = 18;
    int data_atual_mes = 03;
    int data_atual_ano = 2025;


};

struct Cliente {
    char nome[50];
    int idade;
    char sexo[1];
    struct Data data;

    void calcularIdade(){
        int idade = data.ano - data.data_atual_ano;

        printf("%d/%d/%d", data.dia, data.mes, idade);
    }

};

int main() {
    struct Data d;
    struct Cliente c;

    int i;
    char n[50];
    char s[1];

    scanf("%d %d %d", d.dia, d.mes, d.ano);



    return 0;
}
