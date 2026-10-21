
/*
Name: Ausura Keshar
Enrollment No: 92500527109
Program: Singly Linked List Operations
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertBeginning() {
    struct node *newNode;
    int value;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning");
}

void insertEnd() {
    struct node *newNode, *temp;
    int value;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node inserted at end");
}

void insertAfter() {
    struct node *newNode, *temp;
    int key, value;

    printf("Enter the node value after which to insert: ");
    scanf("%d", &key);

    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Specified node not found");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted after specified node");
}

void insertBefore() {
    struct node *newNode, *temp;
    int key, value;

    printf("Enter the node value before which to insert: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    if (head->data == key) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        printf("Node inserted before specified node");
        return;
    }

    temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Specified node not found");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted before specified node");
}

int main() {
    int choice;

    do {
        printf("\n\n1. Create Linked List");
        printf("\n2. Display Linked List");
        printf("\n3. Insert at Beginning");
        printf("\n4. Insert at End");
        printf("\n5. Insert After Specific Node");
        printf("\n6. Insert Before Specific Node");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertBeginning();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                insertAfter();
                break;

            case 6:
                insertBefore();
                break;

            case 7:
                printf("Program ended");
                break;

            default:
                printf("Invalid choice");
        }
    } while (choice != 7);

    return 0;
}
