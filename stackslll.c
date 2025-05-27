#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x);
void pop();
void peek();
void display();

int main() {
    int choice, value;

    do {
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit\n");
                break;  
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void push(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("Element pushed: %d\n", x);
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack underflow\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
