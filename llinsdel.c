#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node* next;
};

struct node *head=NULL,*temp,*newNode;

void display()
{
    if (head == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}

void insert_Begin()
{
    int data1;
    if(head == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        printf("Enter element to be inserted at first: ");
        scanf("%d",&data1);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=data1;
        newNode->next=head;
        head=newNode;
    }
}

void insert_End()
{
    int data2;
    if(head == NULL)
    {
        printf("List not found");
    }
    else
    {
        printf("Enter element to be inserted at last: ");
        scanf("%d",&data2);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=data2;
        newNode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void insert_Specific()
{
    int data3,n;
    if(head == NULL)
    {
        printf("List not found");
    }
    else
    {
        printf("Enter element to be inserted: ");
        scanf("%d",&data3);
        printf("enter element to be inserted after: ");
        scanf("%d",&n);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=data3;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->info == n)
            {
                newNode->next=temp->next;
                temp->next=newNode;
            }
            temp=temp->next;
        }

    }
}

void delete_first()
{
     if(head == NULL)
    {
        printf("list not found\n");
    }
    else
    {
        temp=head;
        head=head->next;
        printf("deleted element = %d\n",temp->info);
        free(temp);
    }
}

void delete_last()
{
    
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    
    else if (head->next == NULL)
    {
        printf("Deleted element = %d\n", head->info);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->next != NULL)
        {
            temp = temp->next;
        }

        printf("Deleted element = %d\n", temp->next->info);
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_Specific_Position()
{
    int pos, x;
    if (head == NULL)
    {
        printf("List not found\n");
        return;
    }
    else
    {
        printf("Enter the position to delete: ");
        scanf("%d", &pos);

        if (pos < 1)
        {
            printf("Invalid position!\n");
            return;
        }

        temp = head;
        for (x = 1; temp != NULL && x < pos - 1; x++)
        {
            temp = temp->next;
        }
        newNode = temp->next;
        temp->next = temp->next->next;

        printf("Deleted element = %d\n", newNode->info);
        free(newNode);
    }
}



void main()
{
    int data;
    printf("enter an element:\n");
    scanf("%d",&data);

    head=(struct node*)malloc(sizeof(struct node));
    head->info=data;
    head->next=NULL;
    temp=head;

    int choice;
    do
    {
        printf("enter 1 for display, 2 to insert at first, 3 to insert at last, 4 to insert in middle, 5 for deleting the first element, 6 for deleting the last element, 7 for deleting element at a specific position\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display();
                    break;
            case 2: insert_Begin();
                    break;
            case 3: insert_End();
                    break;
            case 4: insert_Specific();
                    break;      
            case 5: delete_first();
                    break;  
            case 6: delete_last();
                    break;
            case 7: delete_Specific_Position();
                    break;
            default: printf("invalid choice\n");
        }

     } while(choice != 8);
}