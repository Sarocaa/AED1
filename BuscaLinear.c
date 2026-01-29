#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void exibirVetor (int n, int vetor[])
{
    printf("Exibindo elementos do Vetor:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaLinear (int vetor[], int valor)
{
    int i;
    
    for(i=0; i<TAM; i++)
    {
        if(vetor[i]==valor) return i+1;
    }
    return -1;
}

int main() {
    int vetor[TAM];
    int valorBuscado;
    int resultado;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Geração do vetor com valores aleatórios entre 0 e 99
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100;
    }

    exibirVetor(TAM, vetor);
    // Solicita ao usuário o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorBuscado);
    printf("\n");

    resultado = buscaLinear(vetor, valorBuscado);
    
    // Exibição do resultado
    if (resultado != -1) {
        printf("Valor encontrado na posição %d do vetor.\n", resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }

    return 0;
}
