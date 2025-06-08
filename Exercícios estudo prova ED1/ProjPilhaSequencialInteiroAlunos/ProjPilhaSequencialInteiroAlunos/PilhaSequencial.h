//Arquivo PilhaSequencial.h
#define MAX 100
typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, int num);
int insere_Pilha(Pilha* pi, int num);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);
