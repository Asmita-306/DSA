#include <iostream>
#include <stdio.h>

#define SIZE 5

class List {
private:
    int arr[SIZE];
    int count;

public:
    List() {
        count = 0;
    }

    int insertionBeg(int value);
    int insertionEnd(int value);
    int insertionpo(int value, int pos);
    int deleteBeg();
    int deleteEnd();
    int deletepo(int pos);
    int search(int key);
    void display();
    void rotate(int k);
    void reverse(int start, int end);
};

int main() {
    int choice, value, pos, key, result;
    List l;

    do {
        printf("\n MENU \n");
        printf("1. Insertion at Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at any position\n");
        printf("4. Deletion at Beginning\n");
        printf("5. Deletion at End\n");
        printf("6. Deletion at any position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Rotate\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                l.insertionBeg(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                l.insertionEnd(value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                l.insertionpo(value, pos);
                break;
            case 4:
                result = l.deleteBeg();
                if (result != -1) {
                    printf("The deleted value is %d\n", result);
                } else {
                    printf("List is empty!\n");
                }
                break;
            case 5:
                result = l.deleteEnd();
                if (result != -1) {
                    printf("The deleted value is %d\n", result);
                } else {
                    printf("List is empty!\n");
                }
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                result = l.deletepo(pos);
                if (result != -1) {
                    printf("The deleted value is %d\n", result);
                } else {
                    printf("List is empty!\n");
                }
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &key);
                pos = l.search(key);
                if (pos == -1)
                    printf("Element not found!\n");
                else
                    printf("Element found at position %d\n", pos);
                break;
            case 8:
                l.display();
                break;
            case 9:
                printf("Enter the number of times to rotate the array: ");
                scanf("%d", &value);
                l.rotate(value);
                l.display();
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 10);

    return 0;
}
int List::insertionBeg(int value) {
    if (count == SIZE)
        return -1;
    for (int i = count; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    count++;
    return 1;
}

int List::insertionEnd(int value) {
    if (count == SIZE)
        return -1;
    arr[count++] = value;
    return 1;
}

int List::insertionpo(int value, int pos) {
    if (count == SIZE || pos < 1 || pos > count + 1)
        return -1;
    for (int i = count; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    count++;
    return 1;
}

int List::deleteBeg() {
    if (count == 0)
        return -1;
    int deletedValue = arr[0];
    for (int i = 0; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return deletedValue;
}

int List::deleteEnd() {
    if (count == 0)
        return -1;
    int deletedValue = arr[count - 1];
    count--;
    return deletedValue;
}

int List::deletepo(int pos) {
    if (count == 0 || pos < 1 || pos > count)
        return -1;
    int deletedValue = arr[pos - 1];
    for (int i = pos - 1; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return deletedValue;
}

int List::search(int key) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == key)
            return i + 1;
    }
    return -1;
}

void List::display() {
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void List::reverse(int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void List::rotate(int k) {
    if (count == 0) { // Check if the list is empty
        printf("The list is empty, so it can't be rotated.\n");
        return;
    }
k = k % count; 
reverse(0, count - 1);
reverse(0, k - 1);
reverse(k, count - 1);
}

