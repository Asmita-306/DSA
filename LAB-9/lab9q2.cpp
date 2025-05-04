#include <stdio.h>
// Bubble sort(descending order)
void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//Logic of the question
void solve() {
    int n;
    scanf("%d", &n); 

    int s[n], sorted[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        sorted[i] = s[i]; 
    }
    bubbleSortDescending(sorted, n);

    int max1 = sorted[0];     
    int max2 = sorted[1];     
    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            printf("%d ", s[i] - max2);
        } else {
            printf("%d ", s[i] - max1);
        }
    }
    printf("\n");
}
int main() {
    int test_cases;
    scanf("%d", &test_cases); 

    while (test_cases--) {
        solve();
    }

    return 0;
}