#include <stdio.h>
#include <stdlib.h>

int obterDigito(int num, int exp) {
    return (num/exp) % 10;
}

void msdRadixSort(int* array, int esquerda, int direita, int exp) {
    if (esquerda >= direita || exp <= 0) return;

    int contagem[11] = {0}; 
    int* saida = (int*)malloc((direita - esquerda + 1) * sizeof(int));

    for (int i = esquerda; i <= direita; i++) {
        int d = obterDigito(array[i], exp);
        contagem[d + 1]++;
    }
    for (int i = 0; i < 10; i++) {
        contagem[i + 1] += contagem[i];
    }
    for (int i = esquerda; i <= direita; i++) {
        int d = obterDigito(array[i], exp);
        saida[contagem[d]++] = array[i];
    }
    for (int i = esquerda; i <= direita; i++) {
        array[i] = saida[i - esquerda];
    }
    msdRadixSort(array, esquerda, esquerda + contagem[0] - 1, exp / 10);
    for (int i = 0; i < 9; i++) {
        msdRadixSort(array, esquerda + contagem[i], esquerda + contagem[i+1] - 1, exp / 10);
    }

    free(saida);
}

int main() {
    int arr[] = {902, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    msdRadixSort(arr, 0, n-1, 100);

    printf("Array Ordenado: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    } 
    printf("\n");
    
    return 0;
}
