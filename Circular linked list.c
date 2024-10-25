#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function prototypes
void createCircularList(int n);
void displayCircularList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAfterNode(int key);
void deleteEntireList();

int main() {
    int choice, data, n, key;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createCircularList(n);
                break;
            case 2:
                displayCircularList();
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
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 8:
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

// Create a circular linked list with n nodes
void createCircularList(int n) {
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
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

// Display the elements of the circular linked list
void displayCircularList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert a node at the beginning of the circular linked list
void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Insert a node at the end of the circular linked list
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete a node from the beginning of the circular linked list
void deleteAtBeginning() {
    struct Node *temp = head, *last = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
}

// Delete a node from the end of the circular linked list
void deleteAtEnd() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

// Delete a node after a given node in the circular linked list
void deleteAfterNode(int key) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (temp->data == key) {
            struct Node *delNode = temp->next;
            if (delNode == head) {
                printf("Cannot delete head using deleteAfterNode\n");
                return;
            }
            temp->next = delNode->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key not found\n");
}

// Delete the entire circular linked list
void deleteEntireList() {
    struct Node *temp = head, *nextNode;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != head) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(temp);  // Free the last node
    head = NULL;
    printf("Circular linked list deleted successfully\n");
}
