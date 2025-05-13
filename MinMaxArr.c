#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Maior Menor do Array

int main() {
  int arr[10] = {1, 5, 2, 8, 12, 3, 9, 4, 10, 7};
  int tamanho = 10;
  int maior = INT_MIN;  // Inicialize o maior com o menor valor inteiro possível
  int menor = INT_MAX; // Inicialize o menor com o maior valor inteiro possível

  for (int i = 0; i < tamanho; i++) {
    if (arr[i] > maior) {
      maior = arr[i];
    }
    if (arr[i] < menor) {
      menor = arr[i];
    }
  }

  printf("Maior elemento: %d\n", maior);
  printf("Menor elemento: %d\n", menor);

  return 0;
}