#include <stdio.h>

unsigned long int binomial(unsigned long int n, unsigned long int k)
{
    if ((n==k) || (k==0))
    {
        return 1;
    }
    else
    {
        return binomial(n-1, k) + binomial(n-1, k-1);
    }
}

int main ()
{
    int n, k;
    
    printf("Escolha os números pro binomial: ");
    scanf("%d %d", &n, &k);
    printf("\n");
    
    printf("Binomial entre %d e %d é %d\n", n, k, binomial(n, k));
    
    return 0;
}
