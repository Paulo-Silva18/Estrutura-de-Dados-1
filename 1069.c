#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ========================================
// ESTRUTURA DA PILHA DINÂMICA
// ========================================
typedef struct {
    char* data;           // Ponteiro para o array de dados (alocado dinamicamente)
    int top_index;       // Índice do elemento do topo (-1 = vazia)
    int capacity;        // Capacidade atual da pilha
} DynamicStack;

// Capacidade inicial da pilha (pequena para demonstrar o crescimento)
#define INITIAL_CAPACITY 2

// ========================================
// 1. INICIALIZAR PILHA DINÂMICA
// ========================================
bool init_dynamic_stack(DynamicStack* s) {
    // Tentamos alocar memória para a capacidade inicial
    s->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));

    // Verificamos se a alocação foi bem-sucedida
    if (s->data == NULL) {
        printf("ERRO: Não foi possível alocar memória para a pilha!\n");
        return false;
    }

    // Inicializamos os outros campos
    s->top_index = -1;                    // Pilha começa vazia
    s->capacity = INITIAL_CAPACITY;       // Capacidade inicial

    printf("Pilha dinâmica inicializada com capacidade %d!\n", s->capacity);
    return true;
}

// ========================================
// 2. LIBERAR MEMÓRIA DA PILHA
// ========================================
void destroy_stack(DynamicStack* s) {
    // Liberamos a memória alocada
    if (s->data != NULL) {
        free(s->data);
        s->data = NULL;  // Evita usar ponteiro inválido
    }

    // Resetamos os valores
    s->top_index = -1;
    s->capacity = 0;

    printf("Pilha destruída e memória liberada!\n");
}

// ========================================
// 3. FUNÇÃO PARA CRESCER A PILHA
// ========================================
bool resize_stack(DynamicStack* s) {
    // Calculamos a nova capacidade (dobramos o tamanho atual)
    int new_capacity = s->capacity * 2;

    printf("Redimensionando pilha de %d para %d elementos...\n",
           s->capacity, new_capacity);

    // Tentamos realocar a memória com o novo tamanho
    int* new_data = (int*)realloc(s->data, new_capacity * sizeof(int));

    // Verificamos se a realocação foi bem-sucedida
    if (new_data == NULL) {
        printf("ERRO: Não foi possível redimensionar a pilha!\n");
        return false;
    }

    // Atualizamos os ponteiros e capacidade
    s->data = new_data;
    s->capacity = new_capacity;

    printf("Pilha redimensionada com sucesso! Nova capacidade: %d\n", s->capacity);
    return true;
}

// ========================================
// 4. VERIFICAR SE ESTÁ VAZIA
// ========================================
bool empty(DynamicStack* s) {
    return s->top_index == -1;
}

// ========================================
// 5. OBTER TAMANHO
// ========================================
int size(DynamicStack* s) {
    return s->top_index + 1;
}

// ========================================
// 6. OBTER CAPACIDADE ATUAL
// ========================================
int capacity(DynamicStack* s) {
    return s->capacity;
}

// ========================================
// 7. VERIFICAR ELEMENTO DO TOPO
// ========================================
int top(DynamicStack* s) {
    if (empty(s)) {
        printf("ERRO: Pilha vazia - sem elemento no topo!\n");
        return -1;
    }

    return s->data[s->top_index];
}

// ========================================
// 8. ADICIONAR ELEMENTO (PUSH DINÂMICO)
// ========================================
bool push(DynamicStack* s, const char *value) {
    // Verificamos se precisamos redimensionar a pilha
    if (s->top_index + 1 >= s->capacity) {
        printf("Pilha cheia! Capacidade atual: %d, elementos: %d\n",
               s->capacity, size(s));

        // Tentamos redimensionar
        if (!resize_stack(s)) {
            printf("ERRO: Não foi possível adicionar elemento %d\n", value);
            return false;
        }
    }

    // Adicionamos o elemento
    s->top_index++;
    s->data[s->top_index] = value;

    printf("Elemento %d adicionado! Posição: %d, Uso: %d/%d\n",
           value, s->top_index, size(s), s->capacity);

    return true;
}

// ========================================
// 9. REMOVER ELEMENTO (POP)
// ========================================
int pop(DynamicStack* s) {
    if (empty(s)) {
        printf("ERRO: Pilha vazia - nada para remover!\n");
        return -1;
    }

    // Guardamos o valor do topo
    int removed_value = s->data[s->top_index];

    // "Removemos" decrementando o índice
    s->top_index--;

    printf("Elemento %d removido! Uso atual: %d/%d\n",
           removed_value, size(s), s->capacity);

    // OPCIONAL: Reduzir capacidade se a pilha ficar muito vazia
    // (não implementado aqui para simplicidade)

    return removed_value;
}

// ========================================
// 10. IMPRIMIR STATUS DA PILHA
// ========================================
void print_stack_status(DynamicStack* s) {
    printf("\n=== STATUS DA PILHA ===\n");
    printf("Elementos: %d\n", size(s));
    printf("Capacidade: %d\n", s->capacity);
    printf("Uso: %.1f%%\n", (float)size(s) / s->capacity * 100);

    if (empty(s)) {
        printf("Conteúdo: [vazia]\n");
    } else {
        printf("Conteúdo (topo->base): [");
        for (int i = s->top_index; i >= 0; i--) {
            printf("%d", s->data[i]);
            if (i > 0) printf(", ");
        }
        printf("]\n");
    }
    printf("========================\n\n");
}

// ========================================
// 11. FUNÇÃO PARA DEMONSTRAR CRESCIMENTO
// ========================================
void demonstrar_crescimento(DynamicStack* s) {
    printf("=== DEMONSTRAÇÃO DE CRESCIMENTO DINÂMICO ===\n");

    // Vamos adicionar elementos até forçar vários redimensionamentos
    printf("\nAdicionando elementos para demonstrar o crescimento...\n");

    for (int i = 1; i <= 10; i++) {
        printf("\n--- Adicionando elemento %d ---\n", i * 10);
        push(s, i * 10);

        // Mostramos o status após cada adição
        if (i == 1 || i == 2 || i == 3 || i == 5 || i == 10) {
            print_stack_status(s);
        }
    }
}

// ========================================
// 12. COPIAR PILHA DINÂMICA
// ========================================
bool copy_stack(DynamicStack* origem, DynamicStack* destino) {
    // Inicializamos a pilha de destino
    if (!init_dynamic_stack(destino)) {
        return false;
    }

    // Se a origem estiver vazia, não há nada para copiar
    if (empty(origem)) {
        printf("Pilha origem vazia - cópia finalizada.\n");
        return true;
    }

    // Garantimos que a pilha de destino tenha capacidade suficiente
    while (destino->capacity < origem->capacity) {
        if (!resize_stack(destino)) {
            destroy_stack(destino);
            return false;
        }
    }

    // Copiamos todos os elementos
    for (int i = 0; i <= origem->top_index; i++) {
        destino->data[i] = origem->data[i];
    }
    destino->top_index = origem->top_index;

    printf("Pilha copiada! %d elementos copiados.\n", size(destino));
    return true;
}

// ========================================
// 13. OTIMIZAÇÃO: REDUZIR CAPACIDADE
// ========================================
bool shrink_stack(DynamicStack* s) {
    // Só reduzimos se estivermos usando menos de 25% da capacidade
    // e se a capacidade for maior que a inicial
    if (s->capacity <= INITIAL_CAPACITY ||
        (float)size(s) / s->capacity > 0.25) {
        printf("Redução desnecessária no momento.\n");
        return true;
    }

    int new_capacity = s->capacity / 2;
    if (new_capacity < size(s)) {
        new_capacity = size(s) + 1;  // Garantimos espaço suficiente
    }

    printf("Reduzindo pilha de %d para %d elementos...\n",
           s->capacity, new_capacity);

    int* new_data = (int*)realloc(s->data, new_capacity * sizeof(int));

    if (new_data == NULL) {
        printf("ERRO: Não foi possível reduzir a pilha!\n");
        return false;
    }

    s->data = new_data;
    s->capacity = new_capacity;

    printf("Pilha reduzida! Nova capacidade: %d\n", s->capacity);
    return true;
}

// ========================================
// EXEMPLO PRÁTICO: PROCESSAMENTO DE GRANDES VOLUMES
// ========================================
void processar_sequencia_numeros() {
    printf("\n=== EXEMPLO PRÁTICO: PROCESSAMENTO DE SEQUÊNCIA ===\n");

    DynamicStack pilha;
    if (!init_dynamic_stack(&pilha)) {
        return;
    }

    // Simulamos o processamento de uma sequência de números
    // onde precisamos manter alguns em uma pilha temporária
    int sequencia[] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10, 15, 12, 20, 18, 25};
    int tamanho = sizeof(sequencia) / sizeof(sequencia[0]);

    printf("Processando sequência de %d números...\n", tamanho);
    printf("Regra: Empilhar números pares, desempilhar quando encontrar ímpar maior que 10\n\n");

    for (int i = 0; i < tamanho; i++) {
        int num = sequencia[i];
        printf("Processando número: %d\n", num);

        if (num % 2 == 0) {
            // Número par - empilha
            push(&pilha, num);
            printf("→ Número par empilhado\n");
        } else if (num > 10 && !empty(&pilha)) {
            // Número ímpar maior que 10 - desempilha
            int removido = pop(&pilha);
            printf("→ Número ímpar > 10: removendo %d da pilha\n", removido);
        } else {
            printf("→ Número ignorado\n");
        }

        printf("Estado atual: %d elementos na pilha\n\n", size(&pilha));
    }

    printf("Processamento finalizado!\n");
    print_stack_status(&pilha);

    // Limpamos a memória
    destroy_stack(&pilha);
}

// ========================================
// FUNÇÃO PRINCIPAL
// ========================================
int main() {
    printf("=== PILHA DINÂMICA COM CRESCIMENTO AUTOMÁTICO ===\n\n");

    // Criamos uma pilha dinâmica
    DynamicStack minha_pilha;

    // Inicializamos
    if (!init_dynamic_stack(&minha_pilha)) {
        printf("Falha ao inicializar pilha!\n");
        return 1;
    }

    int n;
    char[100] diamante;
    int contador_abre;
    int contador_fecha;

    scanf("%d", &n);

    for (int i; i < n; i++) {
        scanf("%s", diamante);
        for (int k; k < diamante; k++) {
            if (diamante[k] == '< ') {
                contador_abre++;
                push(minha_pilha, diamante[k]);
            }
            else if (diamante[k] == '>') {
                contador_fecha++;
                push(minha_pilha, diamante[k]);
            }
        }
        if (contador_abre == contador_fecha) {

        }

    }


    return 0;
}
