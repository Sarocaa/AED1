#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila (Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void exibirFila (Fila *f) {
    No *aux = f->inicio;
    
    if(f->inicio==NULL)
    {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: \n");
    while (aux != NULL){
        printf("%d\t", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void enfileirar (Fila *f, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if(novo==NULL) {
        printf("Erro de alocação!\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL;
    
    if(f->inicio==NULL){ //fila vazia
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar (Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    
    No *temp = f->inicio;
    int valor = temp->dado;
    
    f->inicio = temp->prox;
    if (f->inicio == NULL) { // fila ficou vazia
        f->fim = NULL;
    }
    return valor;
}

int main() {

    Fila f;
    int n;
    inicializarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    exibirFila(&f);
    
    n = desenfileirar(&f);
    if(n!=-1) printf("Valor %d removido da fila\n", n);
    exibirFila(&f);
    
    n = desenfileirar(&f);
    if(n!=-1) printf("Valor %d removido da fila\n", n);
    exibirFila(&f);
    
    n = desenfileirar(&f);
    if(n!=-1) printf("Valor %d removido da fila\n", n);
    exibirFila(&f);
    
    
    
    return 0;
}
