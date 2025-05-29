#include "PilhaDinamicaInt.h"

Pilha* criar_pilha() {
    Pilha *p = malloc(sizeof(Pilha));
    if (p != NULL){
        p->topo = NULL;
    }
    return p;

}

void liberar_pilha(Pilha *p) {
    if (p == NULL)
        return;
    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
    free(p);


}

int empilhar(Pilha *p, int valor) {
    if (p == NULL){
        return 0;
    }
    No *no = malloc(sizeof(No));
    if (no != NULL){
        no->dado = valor;
        no->prox = p->topo;
        p->topo = no;
        return 1;
    }
    else {
        return 0;
    }

}

int desempilhar(Pilha *p, int *valor) {
    if (p == NULL)
        return 0;
    if(p->topo == NULL)
        return 0;
    No* aux;
    aux = p->topo;
    p->topo = aux->prox;
    *valor = aux->dado;
    free(aux);
    return 1;

}

int retornar_topo(Pilha *p, int *valor) {
    if (p == NULL)
        return 0;
    if(p->topo == NULL)
        return 0;
    *valor = p->topo->dado;
    return 1;

}

int tamanho_pilha(Pilha *p) {
    if (p == NULL)
        return 0;
    No* aux = p->topo;
    int contador = 0;
    while(aux != NULL){
        aux = aux->prox;
        contador++;
    }
    return contador;
}

void imprimir_pilha(Pilha *p) {
    if (p == NULL)
        return;
    No* aux = p->topo;
    while(aux != NULL){
        printf("\nDado: %d\n", aux->dado);
        aux = aux->prox;
    }
}
