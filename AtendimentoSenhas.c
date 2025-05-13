#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Filas - LIFO

#define MAX 10

// Estrutura da fila
typedef struct {
    int itens[MAX];
    int inicio, fim;
} Fila;

// Inicializa a fila
void inicializa(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return f->fim == MAX;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Enfileira uma senha
void enfileira(Fila *f, int senha) {
    if (!estaCheia(f)) {
        f->itens[f->fim++] = senha;
    } else {
        printf("Fila cheia! Não é possível adicionar mais senhas.\n");
    }
}

// Desenfileira e retorna a senha
int desenfileira(Fila *f) {
    if (!estaVazia(f)) {
        return f->itens[f->inicio++];
    }
    return -1; // erro
}

int main() {
    Fila fila;
    inicializa(&fila);

    // Gerando 5 senhas
    printf("Gerando senhas:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Senha %d gerada.\n", i);
        enfileira(&fila, i);
    }

    printf("\nIniciando atendimento:\n");
    while (!estaVazia(&fila)) {
        int senha = desenfileira(&fila);
        printf("Atendendo senha %d\n", senha);
    }

    return 0;
}