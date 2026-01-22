#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibirMatriz (int n, int matriz[n][n])
{
    printf("Exibir Matriz: \n");
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
         printf("%d\t", matriz[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}

void tridiagonal (int n, int matriz[n][n])
{
    int i, j;
    printf("Matriz tridiagonal: \n");
    
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           if (i == j) printf("%d\t", matriz[i][j]);
           else if (i == j+1) printf("%d\t", matriz[i][j]);
           else if (j == i+1) printf("%d\t", matriz[i][j]);
           else printf("0\t");
       }
       printf("\n");
   }
    printf("\n");
}

int main()
{
   int n;
   printf("Informe a dimensão da matriz: ");
   scanf("%d", &n);
   printf("\n");
   
   int matriz[n][n];
   srand(time(NULL));
   
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           matriz[i][j] = rand() % 100;
       }
   }
   
   exibirMatriz(n, matriz);
   tridiagonal(n, matriz);

   return 0;
}
