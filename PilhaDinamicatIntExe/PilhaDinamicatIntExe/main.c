#include <stdio.h>
#include "PilhaDinamicaInt.h"

int main() {
    Pilha *p = criar_pilha();
    // Empilha alguns valores
    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);

    imprimir_pilha(p);

    int topo;
    if (retornar_topo(p, &topo)) {
        printf("\nTopo: %d\n", topo);
    }

    int rem;
    if (desempilhar(p, &rem)) {
        printf("\nDesempilhado: %d\n", rem);
    }

    imprimir_pilha(p);
    printf("\nTamanho após desempilhar: %d\n", tamanho_pilha(p));

    liberar_pilha(p);
    return 0;
}
