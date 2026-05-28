#include <stdio.h>


void torreHanoi (int ndisco, char dehaste, char parahaste, char auxhaste)
{
    if(ndisco==1)
    {
        printf("Mover disco %d da haste %c para %c\n", ndisco, dehaste, parahaste);
        return;
    }
    
    torreHanoi(ndisco-1, dehaste, auxhaste, parahaste);
    printf("Mover disco %d da haste %c para %c\n", ndisco, dehaste, parahaste);
        
    torreHanoi(ndisco-1, auxhaste, parahaste, dehaste);
    //printf("Mover disco %d da haste %c para %c\n", ndisco, auxhaste, parahaste);
    
}
int main()
{
    int n;
    
    printf("Quantos discos deseja usar: ");
    scanf("%d", &n);
    printf("\n");
    
    torreHanoi(n, 'A', 'C', 'B');

    return 0;
}
