#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray (int V[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void countSort (int A[], int n)
{
    int max=A[0], B[n], i;
    for(i=1; i<n; i++)
    {
        if(max<A[i]) max=A[i];
    }
    printf("Maior elemento do vetor: %d\n", max);
    
    int C[max+1];
    for(i=0; i<=max; i++)
    {
        C[i]=0;
    }
    printf("Vetor C original: \n");
    printArray(C, max+1);
    
    for(i=0; i<n; i++)
    {
        C[A[i]]++;
    }
    printf("Vetor C depois da contagem: \n");
    printArray(C, max+1);
    
    for(i=1; i<max+1; i++)
    {
        C[i] = C[i]+C[i-1];
    }
    printf("Vetor C com os valores acumulados: \n");
    printArray(C, max+1);
    
    for(i=0; i<n; i++)
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    printf("Vetor B final / A ordenado: \n");
    printArray(B, n);
}

int main()
{
    int i, n=15;
    int A[n];
    srand(time(NULL));
    
    for(i=0; i<n; i++)
    {
        A[i] = rand()%10;
    }
    
    printf("Vetor A original: \n");
    printArray(A, n);
    
    countSort(A, n);
}
