#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Soma dos valores do Array

int main() {
    int c[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(c) / sizeof(c[0]);
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += c[i];
    }

    printf("Soma do Array: %d\n", soma);

    return 0;
}
