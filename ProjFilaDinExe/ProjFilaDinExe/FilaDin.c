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

}

int consulta_Fila(Fila* fi, struct aluno *al){

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

}

int tamanho_Fila(Fila* fi){

}

int Fila_vazia(Fila* fi){

}

int Fila_cheia(Fila* fi){

}

void imprime_Fila(Fila* fi){

}

