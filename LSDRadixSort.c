#include <stdio.h>

int get_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void counting_sort_for_radix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;
        output[count[digito] - 1] = arr[i];
        count[digito]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void lsd_radix_sort(int arr[], int n) {
    int max = get_max(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_for_radix(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    lsd_radix_sort(arr, n);

    printf("Ordenado via LSD: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    } 
    printf("\n");
    return 0;
}
