#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//LIFO - Pilhas

#define MAX_URL_LENGTH 256
#define MAX_HISTORY 5

typedef struct {
    char url[MAX_URL_LENGTH];
} Page;

typedef struct {
    Page data[MAX_HISTORY];
    int top;
} Stack;

// Funções para a pilha
void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isStackFull(Stack* stack) {
    return stack->top == MAX_HISTORY - 1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Page page) {
    if (isStackFull(stack)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top].url, page.url);
}

Page pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        Page emptyPage = {""};
        return emptyPage;
    }
    Page page = stack->data[stack->top];
    stack->top--;
    return page;
}

void displayStack(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Histórico de navegação:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d: %s\n", i + 1, stack->data[i].url);
    }
}

int main() {
    Stack historyStack;
    initializeStack(&historyStack);

    Page current;
    int i;

    // Simulando a entrada de 5 páginas visitadas
    printf("Entre com 5 URLs:\n");
    for (i = 0; i < MAX_HISTORY; i++) {
        printf("URL %d: ", i + 1);
        scanf(" %s", current.url);
        push(&historyStack, current);
    }

    // Exibindo o histórico
    displayStack(&historyStack);

    // Simulando a navegação (voltar)
    printf("\nSimulando navegação (voltar):\n");
    while (1) {
        Page visitedPage = pop(&historyStack);
        if (visitedPage.url[0] == '\0') break;
        printf("Voltando para: %s\n", visitedPage.url);
        displayStack(&historyStack);

        if (isStackEmpty(&historyStack)) break;
    }

    return 0;
}