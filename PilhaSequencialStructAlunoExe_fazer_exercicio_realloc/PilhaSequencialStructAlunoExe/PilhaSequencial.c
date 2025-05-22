#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Prot�tipos

//Definicao do tipo Pilha
struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha* pi;
    pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->qtd = 0;
    }
    return pi;
}
void libera_Pilha(Pilha* pi){
    free(pi);
}
int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL){
        return -1;
    }
    *al = pi->dados[pi->qtd-1];
    return 1;

}
int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL){
        return -1;
    }
    if(pi->qtd == MAX){
        return 0;
    }
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;

}
int remove_Pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    pi->qtd--;
    return 1;

}
int tamanho_Pilha(Pilha* pi){

}
int Pilha_vazia(Pilha* pi){

}
int Pilha_cheia(Pilha* pi){

}
void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i=pi->qtd-1; i >=0; i--){
        printf("Matricula: %d\n", pi->dados[i].matricula);
        printf("Nome: %s\n", pi->dados[i].nome);
        printf("Notas: %f %f %f\n", pi->dados[i].n1, pi->dados[i].n2, pi->dados[i].n3);
    }
    printf("------------------\n");

}
void imprime_aluno(struct aluno* al){
    //imprimi apenas um aluno, pois só recebi apenas um aluno como parametro
}
