#include <stdio.h>
#define max 5
int f = -1;
int r = -1;
int cq[max];
int isFull() {
    if ((f == 0 && r == max - 1) || (f == r + 1)) {
        return 1;
    }
    return 0;
}
int isEmpty() {
    if (f == -1 && r == -1) {
        return 1;
    }
    return 0;
}
void enQueue(int x) {
    if (isFull()) {
        printf("Overflow\n");
    } else {
        if (f == -1) {
            f = 0;
        }
        r = (r + 1) % max;
        cq[r] = x;
        printf("Inserted %d successfully.\n", x);
    }
}
int deQueue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    } else {
        int x = cq[f];
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % max;
        }
        return x;
    }
}
void display() {
    if (isEmpty()) {
        printf("Empty Queue");
    } else {
        int i = f;
        while (i != r) {
            printf("%d ", cq[i]);
            i = (i + 1) % max;
        }
        printf("%d", cq[r]);
    }
}
int main() {
    int choice, item;
    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enQueue(item);
                break;
            case 2:
                item = deQueue();
                if (item != -1) {
                    printf("Deleted element: %d\n", item);
                }
                break;
            case 3:
                printf("Queue elements: ");
                display();
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
