#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

int main() {
    struct node* tempNode = (struct node*)malloc(sizeof(struct node));
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* head = NULL;

    if (newNode == NULL) {
        printf("memory unavailable\n");
        return 1;
    }

    
    printf("Enter the data for the first Node: ");
    scanf("%d", &newNode->info);

    newNode->next = newNode; 
    head = newNode;

    printf("Data in first node: %d\n", newNode->info);

    int y, value, n;
    char x;

    do {
        printf("enter 1 for insertion at beg.\n");
        printf("enter 2 for insertion at end\n");
        printf("enter 3 for insertion at a specific element\n");
        printf("enter 4 for display circular linked list\n");
        printf("enter 5 to exit\n");
        printf("enter your choice- ");
        scanf("%d", &y);

        switch (y) {
            case 1: {
                printf("Enter the value to insert at the beginning-");
                scanf("%d", &value);

                tempNode = (struct node*)malloc(sizeof(struct node));
                if (tempNode == NULL) {
                    printf("memory unavailable\n");
                    break;
                }

                tempNode->info = value;
                tempNode->next = head;

                
                struct node* lastNode = head;
                while (lastNode->next != head) { 
                    lastNode = lastNode->next;
                }
                lastNode->next = tempNode; 

                head = tempNode; 
                printf("data inserted at begin-%d\n", value);
                break;
            }

            case 2: {
                printf("enter the value to insert at the end-");
                scanf("%d", &value);

                struct node* newEndNode = (struct node*)malloc(sizeof(struct node));
                if (newEndNode == NULL) {
                    printf("Memory unavailable\n");
                    break;
                }

                newEndNode->info = value;
                newEndNode->next = head;

                struct node* lastNode = head;
                while (lastNode->next != head) { 
                    lastNode = lastNode->next;
                }
                lastNode->next = newEndNode; 

                printf("data inserted at the end-%d\n", value);
                break;
            }

            case 3: {
                printf("enter the value after which to insert-");
                scanf("%d", &n);
                printf("enter value to insert: ");
                scanf("%d", &value);

                struct node* temp = (struct node*)malloc(sizeof(struct node));
                struct node* new = head;
                if (temp == NULL) {
                    printf("memory unavailable\n");
                    break;
                }

                temp->info = value;
                temp->next = NULL;

                while (new->next != head && new->info != n) {
                    new = new->next;
                }

                if (new->info != n) { 
                    printf("data not found \n");
                    free(temp);
                    break;
                }

                temp->next = new->next; 
                new->next = temp; 

                printf("data inserted after value %d- %d\n", n, value);
                break;
            }

            case 4: {
                printf("circular linked list: ");
                if (head == NULL) {
                    printf("list is empty\n");
                    break;
                }
                tempNode = head;
                do {
                    printf("%d -> ", tempNode->info); 
                    tempNode = tempNode->next; 
                } while (tempNode != head);
                printf("(head)\n");
                break;
            }

            case 5:
                return 0;

            default:
                printf("Invalid input\n");
                break;
        }

        printf("Press y to continue: ");
        scanf(" %c", &x);
    } while (x == 'y' || x == 'Y');

    printf("exit\n");
    return 0;
}