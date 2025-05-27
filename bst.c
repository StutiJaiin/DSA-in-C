#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_bst(struct node* root, int data) 
{
    if (root == NULL) 
    {
        return create_node(data);
    }

    if (data <= root->info)
    {
        root->left = insert_bst(root->left, data);
    } else if (data > root->info) 
    {
        root->right = insert_bst(root->right, data);
    }

    return root;  
}

void preorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->info);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ",root->info);
    }
}

void inorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ",root->info);
        inorder_traversal(root->right);
    }
}

int main() 
{
    struct node* root = NULL; 
    int n, choice, m;

    printf("Enter the first value:\n");
    scanf("%d", &n);
    root = insert_bst(root, n); 
    do {
        printf("Do you want to continue? Enter 1 for yes and 0 for no:\n");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            printf("Enter data to be inserted:\n");
            scanf("%d", &m);
            root = insert_bst(root, m);
        }
    } while (choice == 1);

    printf("Preorder traversal of the BST:\n");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal of the BST:\n");
    postorder_traversal(root);
    printf("\n");

    printf("Inorder traversal of the BST:\n");
    inorder_traversal(root);
    printf("\n");

    return 0;
}