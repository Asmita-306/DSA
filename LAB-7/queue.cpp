#include <stdio.h>
#include <stdlib.h>
#define N 5
class Queue {
private:
    int arr[N];
    int front;
    int rear;
public:
    Queue() {
        front = rear = -1;
    }
    void enqueue(int value);
    int dequeue();
    int peek();
};
int main() {
    int value, choice, result;
    Queue q;
    do {
        printf("\nMenu\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            q.enqueue(value);
            break;
        case 2:
            result = q.dequeue();
            if (result != -1) {
                printf("The value deleted is: %d\n", result);
            }
            break;
        case 3:
            result = q.peek();
            if (result != -1) {
                printf("The value at the front is: %d\n", result);
            }
            break;
        case 4:
            printf("EXITING\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
void Queue::enqueue(int value) {
    if (rear == N - 1) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        arr[rear] = value;
    } else {
        rear += 1;
        arr[rear] = value;
    }
}
int Queue::dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else if (front == rear) {
        int temp = arr[front];
        front = rear = -1;
        return temp;
    } else {
        int temp = arr[front];
        front += 1;
        return temp;
    }
}
int Queue::peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return arr[front];
    }
}