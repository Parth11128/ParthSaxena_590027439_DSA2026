#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int largest, smallest;

    printf("Enter size: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = smallest = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    printf("Largest = %d\n", largest);
    printf("Smallest = %d\n", smallest);

    free(arr);

    return 0;
}
