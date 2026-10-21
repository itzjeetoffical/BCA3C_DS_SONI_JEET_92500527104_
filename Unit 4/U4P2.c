
/*
Name: Ausura Keshar
Enrollment No: 92500527109
Program: Binary Search Tree Operations
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int height(struct node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countNodes(struct node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Height of Tree");
        printf("\n4. Total Number of Nodes");
        printf("\n5. Display Tree");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deletion operation completed");
                break;

            case 3:
                printf("Height of Tree: %d", height(root));
                break;

            case 4:
                printf("Total Number of Nodes: %d", countNodes(root));
                break;

            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 6:
                printf("Program ended");
                break;

            default:
                printf("Invalid choice");
        }
    } while (choice != 6);

    return 0;
}
