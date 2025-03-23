#include<stdio.h>
#include <stdlib.h>


struct Conjunto {
    int n;
    int *numeros;

    void criarConjuntoVazio(int tam) {
        n = tam;
        for (int i = 0; i < n; i++){
            numeros = (int *) malloc(n * sizeof(int));
            numeros[i] = 0;
        }

    }

    void lerConjunto() {
        for (int i = 0; i < n; i++){
            printf("DIGITE UM NUMERO: \n");
            scanf("%d", &numeros[i]);
        }

    }

    struct Conjunto uniao(struct Conjunto co2){
        struct Conjunto co3;
        co3.criarConjuntoVazio(n + co2.n);
        for (int i = 0; i < n; i++){
            co3.numeros[i] = numeros[i];
        }
        for (int i = 0; i < co2.n; i++){
            co3.numeros[i + n] = co2.numeros[i];
        }
        return co3;
    }

    struct Conjunto intersecao(struct Conjunto co2){
        int tamanho = 0;
        struct Conjunto co3;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < co2.n; j++){
                if (numeros[i] == co2.numeros[j]){
                    tamanho++;
                    break;
                }
            }
        }
        co3.criarConjuntoVazio(tamanho);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < co2.n; j++){
                if (numeros[i] == co2.numeros[j]){
                    co3.numeros[i] = numeros[i];
                    break;
                }
            }
        }
        return co3;
    }

    void imprimirConjunto(){
        printf("imprimindo conjunto de tamanho %d\n", n);
        for (int i = 0; i < n; i++){
            printf("%d", numeros[i]);
        }
        printf("\n");


    }


};

int main() {
    struct Conjunto co;
    struct Conjunto co2;
    struct Conjunto uniao;
    struct Conjunto intersecao;

    int tam, tam2;

    printf("DIGITE O TAMANHO DOS DOIS CONJUNTOS\n");
    scanf("%d %d", &tam, &tam2);

    if (tam > 20 || tam2 > 20){
        printf("O limite nao pode ser maior que 20");
        return 0;
    }

    co.criarConjuntoVazio(tam);
    co.lerConjunto();
    co.imprimirConjunto();

    co2.criarConjuntoVazio(tam2);
    co2.lerConjunto();
    co2.imprimirConjunto();

    uniao = co.uniao(co2);
    printf("imprimindo conjunto de uniao: \n");
    uniao.imprimirConjunto();

    intersecao = co.intersecao(co2);
    printf("imprimindo conjunto de intersecao: \n");
    intersecao.imprimirConjunto();

    return 0;
}
