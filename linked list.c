#include<stdio.h>
#include<stdlib.h>                          //this header file is imp as we are using the malloc function

struct Node{                                 //this is the creation of a list or a node
    int data;                                    //we are storing a variable which is our data
    struct Node* next;                            //this is our pointer and next means it is pointing to the next node
}; 
                       //this is the creation of a self-referential node: a node that points towards itself or a node in a linked list
void LLTraversal(struct Node* ptr){           //we create a traversal function
while (ptr != NULL) {                         //while loop so that the linked list ends if the pointer points to null
    printf("element is %d\n", ptr->data);     //printing the elements of the node, now pointer pointing to the value stored in data 
    ptr=ptr->next;                            //this will make the pointer ptr point to every node of the linked list, until it gets null
    
}
}
int main() {
    struct Node* head;   
    struct Node* second;
    struct Node* third;                 //this is the naming of nodes in a linked list

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));           //this is memory allocation for these different nodes
    
    head->data=7;         //here, we are allocating the data
    head->next=second;    //this is the linking statement for first and second nodes

    second->data=9;
    second->next=third;     //this is the linking statement for second and third nodes

    third->data=11;
    third->next=NULL;       //this is the termination statement so the list gets ended after the third node

    LLTraversal(head);


    return 0;
}