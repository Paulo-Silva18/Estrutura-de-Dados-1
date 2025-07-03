#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main(){
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Fila* fi = cria_Fila();
    int i;
    for(i=0; i < 4; i++)
        insere_Fila(fi,a[i]);
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    if(busca_Fila(fi, 9, &al)) {
        printf("Matricula de aluno encontrado\n");
        printf("Nome: %s\nMat: %d\nNotas: %f %f %f\n",
           al.nome,al.matricula, al.n1,
           al.n2,al.n3);
        printf("************************************\n\n");
    }
    else {
        printf("Matricula de aluno nao encontrado\n");
    }
    printf("A quantidade de alunos aprovados foram: %d\n", conta_aprovada(fi));
    remove_Fila(fi);
    consulta_Fila(fi, &al);


    remove_Fila(fi);
    printf("Depois da remocao:\n");
    imprime_Fila(fi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));

    libera_Fila(fi);

    system("pause");
    return 0;
}


