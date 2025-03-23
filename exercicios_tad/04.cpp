#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int numero_paginas;

    void lerLivro() {
        printf("Titulo do livro: \n");
        scanf("%s", titulo);

        printf("Autor do livro: \n");
        scanf("%s", autor);

        printf("Numero de paginas do livro: \n");
        scanf("%d", &numero_paginas);

    }

    void imprimirLivro() {
        printf("Titulo do livro: %s\n", titulo);

        printf("Autor do livro: %s\n", autor);

        printf("Numero de paginas do livro: %d\n", numero_paginas);

    }

};

struct Biblioteca {
    struct Livro *livros;
    int quantidade_livros;

    void lerNovoLivro(int n) {
        quantidade_livros = n;
        livros = (Livro *) malloc(n * sizeof(Livro));

        for (int i = 0; i < n; i++){
            livros[i].lerLivro();
        }
    }

    void imprimirLivrosBiblioteca() {
        for (int i = 0; i < quantidade_livros; i++){
            livros[i].imprimirLivro();
        }


    }

    void livroMaiorNumeroDePaginas() {
        int maior_numero_paginas = 0;
        char titulo_livro[50];
        for (int i = 0; i < quantidade_livros; i++) {
            if (livros[i].numero_paginas > maior_numero_paginas) {
                maior_numero_paginas = livros[i].numero_paginas;
                strcpy(titulo_livro, livros[i].titulo);
            }
        }
        printf("O livro com maior numero de paginas e: %s\n", titulo_livro);


    }



};


int main() {
    struct Livro livro;
    struct Biblioteca biblioteca;
    int tam;

    printf("DIGITE A QUANTIDADE DE LiVROS\n");
    scanf("%d", &tam);

    if (tam > 10){
        printf("O limite nao pode ser maior que 10");
        return 0;
    }


    biblioteca.lerNovoLivro(tam);
    biblioteca.imprimirLivrosBiblioteca();
    biblioteca.livroMaiorNumeroDePaginas();

    return 0;
}
