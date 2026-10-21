
/*
Name: Ausura Keshar
Enrollment No: 92500527109
Program: Doubly Linked List Operations
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void create() {
    int n, i, value;
    struct node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

void insertBeginning() {
    int value;
    struct node *newNode;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = createNode(value);
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Node inserted at beginning");
}

void insertEnd() {
    int value;
    struct node *newNode, *temp;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at end");
}

void insertAfter() {
    int key, value;
    struct node *temp, *newNode;

    printf("Enter node value after which to insert: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node inserted successfully");
}

void insertBefore() {
    int key, value;
    struct node *temp, *newNode;

    printf("Enter node value before which to insert: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Node inserted successfully");
}

void deleteBeginning() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    printf("First node deleted");
}

void deleteEnd() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    temp = head;

    if (head->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
    }

    free(temp);

    printf("Last node deleted");
}

void deleteSpecific() {
    int key;
    struct node *temp;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Specific node deleted");
}

int main() {
    int choice;

    do {
        printf("\n\n--- DOUBLY LINKED LIST ---");
        printf("\n1. Create Linked List");
        printf("\n2. Display Linked List");
        printf("\n3. Insert at Beginning");
        printf("\n4. Insert at End");
        printf("\n5. Insert After Specific Node");
        printf("\n6. Insert Before Specific Node");
        printf("\n7. Delete First Node");
        printf("\n8. Delete Last Node");
        printf("\n9. Delete Specific Node");
        printf("\n10. Exit");

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
                deleteBeginning();
                break;

            case 8:
                deleteEnd();
                break;

            case 9:
                deleteSpecific();
                break;

            case 10:
                printf("Program ended");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 10);

    return 0;
}
