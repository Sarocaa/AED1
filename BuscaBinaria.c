#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void exibirVetor(int n, int vetor[]){
    printf("Exibindo os elementos do Vetor:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaBinária(int vetor[TAM], int valorBuscado)
{
    int inicio, fim, meio;
    inicio = 0;
    fim = TAM-1;
    int resultado;
    
    while(1)
    {
        meio = (fim + inicio)/2;
        
        if(vetor[meio]==valorBuscado)
        {
            resultado = meio+1;
            return resultado;
        }
        else if(vetor[meio]>valorBuscado) fim = meio;
        else if(vetor[meio]<valorBuscado) inicio = meio;
        
        if(meio<=0)
        {
            resultado = -1;
            return resultado;
        }
    }
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

    // Ordenando o vetor
     for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    exibirVetor(TAM, vetor);
    // Solicita ao usuário o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorBuscado);

    resultado = buscaBinária(vetor, valorBuscado);

    // Exibição do resultado
    if (resultado != -1) {
        printf("Valor encontrado na posição %d do vetor.\n", resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }

    return 0;
}
