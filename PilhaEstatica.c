#include <stdio.h>
#include <stdlib.h>

#define sucesso 1 
#define falha -1 
#define chave_invalida 0
#define tamanho_max 5

typedef struct {
    unsigned int chave;
    unsigned int dado;
} Elemento;

typedef struct {
    Elemento elementos[tamanho_max];
    unsigned int tamanho;
} Pilha;

void mostrarPilha (Pilha pilha)
{
    if(pilha.tamanho==0)
    {
        printf("Pilha vazia!\n");
    }
    else{
        printf("Exibindo pilha:\n");
        for(int i=0; i<pilha.tamanho; i++)
        {
            printf("|\t%d\t|\n", pilha.elementos[i].dado);
        }
    }
}

int criarPilha (Pilha *pilha)
{
    pilha->tamanho = 0;
    return sucesso;
}

int tamanhoPilha (Pilha pilha)
{
    if(pilha.tamanho==0)
    {
        return pilha.tamanho;
    }
    else return falha;
}

int push(Pilha *pilha, Elemento elemento)
{
    if(pilha->tamanho==tamanho_max) return falha;
    else
    {
        pilha->elementos[pilha->tamanho] = elemento;
        pilha->tamanho++;
        return sucesso;
    }
}

Elemento pop (Pilha *pilha, Elemento elemento)
{
    Elemento retorno;
	if(pilha->tamanho==0) {
	    retorno.chave = chave_invalida;
	    return retorno; //erro
	}
	else {
		pilha->tamanho--;
        retorno = pilha->elementos[pilha->tamanho];
        return retorno;
	}
}

int main()
{
    Pilha pilha;
    criarPilha(&pilha);
    mostrarPilha(pilha);
    Elemento elemento;
    int retorno;
    Elemento elem_retorno;
    
    elemento.dado=5;
    retorno = push(&pilha, elemento);
    if(retorno==1) printf("Elemento inserido com sucessso!\n");
    else printf("Elemento não inserido.\n");
    
    elemento.dado=7;
    retorno = push(&pilha, elemento);
    if(retorno==1) printf("Elemento inserido com sucessso!\n");
    else printf("Elemento não inserido.\n");
    
    elemento.dado=3;
    retorno = push(&pilha, elemento);
    if(retorno==1) printf("Elemento inserido com sucessso!\n");
    else printf("Elemento não inserido.\n");
    
    elemento.dado=8;
    retorno = push(&pilha, elemento);
    if(retorno==1) printf("Elemento inserido com sucessso!\n");
    else printf("Elemento não inserido.\n");
    
    elemento.dado=2;
    retorno = push(&pilha, elemento);
    if(retorno==1) printf("Elemento inserido com sucessso!\n");
    else printf("Elemento não inserido.\n");
    
    mostrarPilha(pilha);
    
    elemento.dado=2;
    elem_retorno = pop(&pilha, elemento);
    if(elem_retorno.chave!=chave_invalida) printf("Elemento removido com sucessso!\n");
    else printf("Falha ao remover elemento.\n");
    
    mostrarPilha(pilha);

    return 0;
}
