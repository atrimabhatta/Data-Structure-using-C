#include <stdio.h>
#include <stdlib.h>

// Define the structure of a single linked list node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function prototypes
void createLinkedList(int n);
void displayLinkedList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertBeforeNode(int data, int key);
void insertAfterNode(int data, int key);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAfterNode(int key);
void deleteEntireList();

int main() {
    int choice, data, n, key;

    while (1) {
        printf("\n--- Single Linked List Menu ---\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createLinkedList(n);
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the key before which to insert: ");
                scanf("%d", &key);
                insertBeforeNode(data, key);
                break;
            case 6:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                insertAfterNode(data, key);
                break;
            case 7:
                deleteAtBeginning();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 10:
                deleteEntireList();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Create a single linked list of n nodes
void createLinkedList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = NULL;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
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

// Display the elements of the linked list
void displayLinkedList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end of the linked list
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert a node before a given node
void insertBeforeNode(int data, int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    struct Node *prev = NULL;

    newNode->data = data;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

// Insert a node after a given node
void insertAfterNode(int data, int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = data;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node from the beginning
void deleteAtBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// Delete a node from the end
void deleteAtEnd() {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete a node after a given node
void deleteAfterNode(int key) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Key or next node not found\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Delete the entire linked list
void deleteEntireList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Linked list deleted successfully\n");
}
