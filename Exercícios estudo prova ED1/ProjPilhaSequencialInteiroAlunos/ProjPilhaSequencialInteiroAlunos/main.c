#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"
int main(){
    int a[4] = {10,11,12,13};
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Topo pilha: %d\n\n\n\n", consulta_topo_Pilha(pi, a));
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));


    for(i=0; i < 4; i++)
        remove_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i=3; i >= 0; i--)
        insere_Pilha(pi,a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    printf("Topo pilha: %d\n\n\n\n", consulta_topo_Pilha(pi, a));
    imprime_Pilha(pi);


    libera_Pilha(pi);
    system("pause");
    return 0;
}

