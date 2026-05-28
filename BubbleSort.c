#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 15

void bubbleSort(int *v, int n) {

    int aux, flag=0;
    
    for(int fim=(n-1); fim>0; --fim){
        flag=0;
        for(int i=0; i<fim; ++i){
            if(v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                flag=1;
            }
        }
        if(flag==0) //nao houve troca
        {
        return;
        }
    }
}

int main()
{
    int v[max];
    int i;
    
    
    srand(time(NULL));
    for(i=0; i<max; i++)
    {
        v[i] = rand() %100;
    }
    
    printf("Vetor não ordenado: \n");
    for(i=0; i<max; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    bubbleSort(v, max);
    
    printf("Vetor ordenado: \n");
    for(i=0; i<max; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}
