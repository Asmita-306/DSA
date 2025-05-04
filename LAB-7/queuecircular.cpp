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
    Queue q;
    int choice, value, result;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            q.enqueue(value);
            break;
        case 2:
            result = q.dequeue();
            if (result != -1) {
                printf("Dequeued value: %d\n", result);
            }
            break;
        case 3:
            result = q.peek();
            if (result != -1) {
                printf("Front value: %d\n", result);
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void Queue::enqueue(int val) {
    if (((rear + 1) % N) == front) {
        printf("Queue is full! Cannot enqueue %d\n", val);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % N;
        arr[rear] = val;
        printf("Enqueued: %d\n", val);
    }
}
int Queue::dequeue() {
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % N;
        }
        return val;
    }
}
int Queue::peek() {
    if (front == -1) {
        printf("Queue is empty! No front element.\n");
        return -1;
    } else {
        return arr[front];
    }
}
