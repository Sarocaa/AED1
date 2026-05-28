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

void countingSort(int A[], int n){
    int i, max = A[0];
    for(i=1; i<n; i++){
        if(max < A[i]){
            max = A[i];
        }
    }
    int C[max+1];
    for(i=0;i<max+1;i++){
        C[i] = 0;
    }
    for(i=0; i<n;i++){
        C[A[i]]++;
    }
    for(i=1; i<max+1;i++){
        C[i] = C[i] + C[i-1];
    }
    int B[n];
    for(i=n-1;i>=0;i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    for(i=0;i<n;i++){
        A[i] = B[i];
    }
}


void bucketSort (int V[], int n)
{
    int numBuckets = n%5==0 ? n/5 : n/5+1;
    int buckets[numBuckets][n];
    int bucketSize[numBuckets];
    int k=V[0], i;
    
    for(i=0; i<numBuckets; i++)
    {
        bucketSize[i]=0;
    }
    
    printf("\nContador dos buckets: ");
    printArray(bucketSize, numBuckets);
    
    for(i=0; i<n; i++)
    {
        if(k<V[i]) k=V[i];
    }
    printf("\nMaior valor: %d\n ", k);
    
    int intervalo = k%numBuckets ==0 ? k/numBuckets : k/numBuckets+1;
    printf("\nIntervalo: %d\n ", intervalo);
    printf("\nNumeros de baldes %d\n: ", numBuckets);
    
    int bucket;
    for(i=0; i<n; i++)
    {
        bucket=V[n]/intervalo;
        printf("\nValor %d no balde %d na posição: %d \n", V[i], bucket, bucketSize[bucket]);
        buckets[bucket][bucketSize[bucket]++] = V[i];
    }
    
    for(i=0; i<numBuckets; i++)
    {
        printf("\nImprimir bucket %d:\n", i);
        printArray(buckets[i], bucketSize[i]);
    }
    
    for(i=0;i<numBuckets; i++){
        countingSort(buckets[i], bucketSize[i]);
    }
    
    for(i=0;i<numBuckets; i++){
        printf("\nImprimir Buckets Ordenados: %d\n ", i);
        printArray(buckets[i], bucketSize[i]);
    }

    int cont = 0;
    for(i=0;i<numBuckets; i++){
       for(int j = 0; j < bucketSize[i]; j++){
           V[cont++] = buckets[i][j];
       }
    }
}

int main()
{
    int i, n=15;
    int V[n];
    srand(time(NULL));
    
    for(i=0; i<n; i++)
    {
        V[i] = rand()%100;
    }
    
    printf("Vetor original: \n");
    printArray(V, n);
    
    bucketSort(V, n);
    printf("Vetor ordenado: \n");
    printArray(V, n);
}
