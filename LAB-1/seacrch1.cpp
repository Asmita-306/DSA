#include <stdio.h>
void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            }

        }
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, choice, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n1. Linear Search\n2. Binary Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = linearSearch(arr, n, key);
                if (index != -1) {
                    printf("Key found at position %d\n", index + 1);
                } else {
                    printf("Key not found!\n");
                }
                break;
            case 2:
                bubble_sort(arr, n); // Binary search requires a sorted array
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = binarySearch(arr, n, key);
                if (index != -1) {
                    printf("Key found at position %d\n", index + 1);
                } else {
                    printf("Key not found!\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
