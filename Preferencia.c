#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int idade;
} Pessoa;

int main() {
    Pessoa preferencial[MAX_PESSOAS];
    Pessoa normal[MAX_PESSOAS];
    int totalPreferencial = 0, totalNormal = 0;
    int total, i;

    printf("Quantas pessoas na fila? ");
    scanf("%d", &total);

    for (i = 0; i < total; i++) {
        Pessoa p;
        printf("Digite o nome da %dª pessoa: ", i + 1);
        scanf(" %[^\n]", p.nome);  // Lê string com espaços
        printf("Digite a idade de %s: ", p.nome);
        scanf("%d", &p.idade);

        if (p.idade >= 60) {
            preferencial[totalPreferencial++] = p;
        } else {
            normal[totalNormal++] = p;
        }
    }

    printf("\n=== Ordem de Atendimento ===\n");

    // Atende preferenciais
    for (i = 0; i < totalPreferencial; i++) {
        printf("Preferencial - Nome: %s, Idade: %d\n", preferencial[i].nome, preferencial[i].idade);
    }

    // Atende demais
    for (i = 0; i < totalNormal; i++) {
        printf("Normal       - Nome: %s, Idade: %d\n", normal[i].nome, normal[i].idade);
    }

    return 0;
}