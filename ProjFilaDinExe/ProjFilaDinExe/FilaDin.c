#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos
//Definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->final = NULL;
        f->qtd = 0;
    }
    return f;
}

void libera_Fila(Fila* fi){
    if(fi == NULL) {
        return;
    }
    Elem *aux = fi->inicio;
    while(fi->inicio != NULL) {
        aux = fi->inicio;
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
    free(fi);

}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL) {
        return 0;
    }
    if(fi->inicio == NULL) {
        return 0;
    }
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL) {
        return 0;
    }
    Elem *e = (Elem*) malloc(sizeof(Elem));
    if(e == NULL) {
        return 0;
    }
    e->dados = al;
    e->prox = NULL;
    if(fi->inicio == NULL) {
        fi->inicio = e;
    }
    else {
        fi->final->prox = e;
    }
    fi->final = e;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL) {
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    Elem *aux = fi->inicio;
    fi->inicio = aux->prox;
    if(fi->inicio == NULL) {
        fi->final == NULL;
    }
    fi->qtd--;
    free(aux);
    return 1;

}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) {
        return -1;
    }
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL) {
        return -1;
    }
    if(fi->inicio == NULL) { // fi->qtd == 0
        return 1;
    }
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL) {
        return;
    }
    Elem *aux = fi->inicio;
    while(aux != NULL) {
        printf("Nome: %s\nMat: %d\nNotas: %f %f %f\n",
           aux->dados.nome,aux->dados.matricula, aux->dados.n1,
           aux->dados.n2,aux->dados.n3);
        printf("************************************\n\n");
        aux = aux->prox;

    }

}

int busca_Fila(Fila*fi, int matricula, struct aluno* al) {
    if(fi == NULL) {
        return -1;
    }
    Elem *aux = fi->inicio;
    while(aux != NULL) {
        if (aux->dados.matricula == matricula) {
            *al = aux->dados;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;

}

