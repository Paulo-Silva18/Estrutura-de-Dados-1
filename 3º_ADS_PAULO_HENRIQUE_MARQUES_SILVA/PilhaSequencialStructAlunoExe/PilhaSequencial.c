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
    if (pi == NULL) {
        return -1;
    }
    return pi->qtd;
}
int Pilha_vazia(Pilha* pi){
    if (pi == NULL) {
        return -1;
    }
    return (pi->qtd == 0) ? 1 : 0;
}
int Pilha_cheia(Pilha* pi){
    if (pi == NULL) {
        return -1;
    }
    return (pi->qtd == MAX) ? 1 : 0;

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
    if (al == NULL) {
        printf("Aluno inválido.\n");
        return;
    }
    printf("Matricula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("Notas: %.2f %.2f %.2f\n", al->n1, al->n2, al->n3);
    printf("------------------\n");
}
