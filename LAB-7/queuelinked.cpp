#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Queue {
private:
    struct node {
        int data;
        struct node* next;
    };
    node* front;
    node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val);
    int dequeue();
    int peek();
};
int main() {
    int choice, result, val;
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
            printf("Enter the value to be enqueued: ");
            scanf("%d", &val);
            q.enqueue(val);
            break;

        case 2:
            result = q.dequeue();
            if (result != 0) {
                printf("The value deleted is: %d\n", result);
            } else {
                printf("Queue is empty!\n");
            }
            break;

        case 3:
            result = q.peek();
            if (result != 0) {
                printf("The value at the front is: %d\n", result);
            } else {
                printf("Queue is empty!\n");
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
void Queue::enqueue(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}
int Queue::dequeue() {
    if (front == NULL) { 
        return 0;
    }
    struct node* temp = front; 
    int data = temp->data;     
    front = front->next;       
    if (front == NULL) { 
        rear = NULL;
    }
    return data;
}
int Queue::peek() {
    if (front == NULL) { 
        return 0;
    }
    return front->data; 
}
