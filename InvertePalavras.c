#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Inverte Palavras

#define MAX 100

// Estrutura da pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// Empilha um caractere
void empilha(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = c;
    }
}

// Desempilha um caractere
char desempilha(Pilha *p) {
    if (p->topo >= 0) {
        return p->itens[(p->topo)--];
    }
    return '\0'; // erro
}

// Função para inverter palavra
void invertePalavra(char *palavra) {
    Pilha pilha;
    inicializa(&pilha);

    int i;
    for (i = 0; palavra[i] != '\0'; i++) {
        empilha(&pilha, palavra[i]);
    }

    printf("Palavra invertida: ");
    while (pilha.topo >= 0) {
        printf("%c", desempilha(&pilha));
    }
    printf("\n");
}

int main() {
    char palavra[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    invertePalavra(palavra);

    return 0;
}