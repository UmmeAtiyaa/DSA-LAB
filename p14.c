#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || front == rear + 1;
}

int isEmpty() {
    return front == -1;
}

void insertFront(int data) {
    if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    deque[front] = data;
}

void insertRear(int data) {
    if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = data;
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int data = deque[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    return data;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int data = deque[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }

    return data;
}

int getFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot get front.\n");
        return -1;
    }
    return deque[front];
}

int getRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot get rear.\n");
        return -1;
    }
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d, ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the front: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2:
                printf("Enter the data to insert at the rear: ");
                scanf("%d", &data);
                insertRear(data);
                break;

            case 3:
                printf("Deleted from the front: %d\n", deleteFront());
                break;

            case 4:
                printf("Deleted from the rear: %d\n", deleteRear());
                break;

            case 5:
                printf("Deque elements: ");
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
