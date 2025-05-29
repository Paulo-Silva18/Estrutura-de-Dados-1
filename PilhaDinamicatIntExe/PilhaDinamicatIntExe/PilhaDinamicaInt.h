#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
    int dado;
    No *prox;
};

// Pilha com ponteiro para o topo
typedef struct pilha {
    No *topo;
} Pilha;

// Protótipos
Pilha* criar_pilha();
void liberar_pilha(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p, int *valor);
int retornar_topo(Pilha *p, int *valor);
int tamanho_pilha(Pilha *p);
void imprimir_pilha(Pilha *p);
