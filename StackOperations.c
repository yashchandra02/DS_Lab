#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push() {
    int value;
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");
    } else {
        printf("Enter the element to be added: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d added into the stack.\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
    } else {
        int value;
        value=stack[top];
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}
void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");

        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nSelect the option\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
