#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Protótipos

//Definição do tipo Pilha
struct pilha{
    int topo;
    int dados[MAX];
};

Pilha* cria_Pilha(){
   Pilha *pi;
   pi = (Pilha*) malloc(sizeof(Pilha));
   if (pi != NULL) {
        pi->topo = 0;
        return pi;
   }
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int consulta_topo_Pilha(Pilha* pi, int num){
   if (pilha_vazia(pi)) {
        return 0;
    }
    num = pi->dados[pi->topo - 1];
    return 1;
}

int insere_Pilha(Pilha* pi, int num){
    if (pilha_cheia(pi)) {
        return 0;
    }
    pi->topo++;
    pi->dados[pi->topo] = num;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if (pilha_vazia(pi)) {
        return 0;
    }
    int elemento;
    elemento = pi->dados[pi->topo];
    pi->topo--;
    return elemento;
}

int tamanho_Pilha(Pilha* pi){
    if (pilha_vazia(pi)) {
        return 0;
    }
    int contador;
    for (int i = 1; i <= pi->topo; i++) {
        contador = i;
    }
    return contador;

}

int pilha_cheia(Pilha* pi){
    return pi->topo == MAX;
}

int pilha_vazia(Pilha* pi){
    return pi->topo == NULL;
}

void imprime_Pilha(Pilha* pi){
    for (int i = 1; i <= pi->topo; i++) {
        printf("%d\n", pi->dados[i]);
    }
}
