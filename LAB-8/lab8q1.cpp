#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int x = a[0];

        // Create b[] (all elements except the first)
        int b[n - 1];
        for (int i = 1; i < n; i++) {
            b[i - 1] = a[i];
        }

        // Manually sort b[] using Bubble Sort
        bubbleSort(b, n - 1);

        // Process elements of b[]
        for (int i = 0; i < n - 1; i++) {
            if (b[i] > x) {
                x += (b[i] - x + 1) / 2;
            }
        }

        printf("%d\n", x);
    }

    return 0;
}