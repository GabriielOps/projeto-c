#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Verificação de Parenteses

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

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um caractere
void empilha(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = c;
    }
}

// Desempilha e retorna o topo
char desempilha(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0'; // caso erro
}

// Função para verificar os parênteses
int verificaParenteses(const char *expr) {
    Pilha pilha;
    inicializa(&pilha);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilha(&pilha, '(');
        } else if (expr[i] == ')') {
            if (estaVazia(&pilha)) {
                return 0; // fechamento sem abertura
            }
            desempilha(&pilha);
        }
    }

    return estaVazia(&pilha); // se estiver vazia no final, está correto
}

int main() {
    char expressao[100];

    printf("Digite a expressao: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // remove newline

    if (verificaParenteses(expressao)) {
        printf("Parenteses balanceados!\n");
    } else {
        printf("Parenteses desbalanceados!\n");
    }

    return 0;
}