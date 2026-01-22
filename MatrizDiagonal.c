#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibeMatriz (int n, int matriz[n][n])
{
    int i, j;
    printf("Matriz criada: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void diagPrincipal (int n, int matriz[n][n])
{
    int i, j;
    printf("Diagonal principal da matriz: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j) printf("%d ", matriz[i][j]);
        }
    }
    printf("\n\n");
}

void diagSecund (int n, int matriz[n][n])
{
    int i, j;
    printf("Diagonal secundária da matriz: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i+j==(n-1)) printf("%d ", matriz[i][j]);
        }
    }
    printf("\n\n");
}

int main()
{
    int n, i, j; 
   
    printf("Informe a dimensão da matriz: ");
    scanf("%d", &n);
    printf("\n");
    int matriz[n][n];
   
    srand(time(NULL));
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
    
    exibeMatriz (n, matriz);
    diagPrincipal (n, matriz);
    diagSecund (n, matriz);
   
    return 0;
}
