#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Protótipos

//Definição do tipo Pilha
struct pilha{
    int topo;
    int dados[MAX];
};

Pilha* cria_Pilha(){
    pilha *p;
    p = (pilha*) malloc(sizeof(pilha));
    if (pi == NULL){
        return 0;
    }
    p->topo = -1; // Pilha vazia
    return p;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int consulta_topo_Pilha(Pilha* pi, int *num){
   // implementar aqui
}

int insere_Pilha(Pilha* pi, int num){
    // implementar aqui
}

int remove_Pilha(Pilha* pi){
    // implementar aqui
}

int tamanho_Pilha(Pilha* pi){
    // implementar aqui
}

int pilha_cheia(Pilha* pi){
    // implementar aqui
}

int pilha_vazia(Pilha* pi){
   // implementar aqui
}

void imprime_Pilha(Pilha* pi){
    if (pi == NULL){
        return 0;
    }
    while (pi->topo >= 0){
        printf("%d", pi->dados[pi->topo]);
        pi->topo--;
    }
    printf("\n");
}
