#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data,
                      int position)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL && position == 0) {
        *head = newNode;
        newNode->next = *head;
    }
    else if (position == 0) {
        free(newNode);                 // insertAtBeginning makes its own node
        insertAtBeginning(head, data);
    }
    else {
        struct Node* temp = *head;
        int i = 0;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head)
{
    if (*head == NULL) {
        return;
    }
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        struct Node* toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
    }
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head)
{
    if (*head == NULL) {
        return;
    }
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    else {
        struct Node* secondLast = *head;
        while (secondLast->next->next != *head) {
            secondLast = secondLast->next;
        }
        struct Node* last = secondLast->next;
        secondLast->next = *head;
        free(last);
    }
}

// Function to delete a node from a specific position
void deleteAtPosition(struct Node** head, int position)
{
    if (*head == NULL) {
        return;
    }
    else if (position == 0) {
        deleteFromBeginning(head);
    }
    else {
        struct Node* temp = *head;
        int i = 0;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// Function to traverse and print the circular linked list
void traverse(struct Node* head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Function to search for a node with a given key
int search(struct Node* head, int key)
{
    if (head == NULL) {
        return 0;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return 1; // Key found
        }
        temp = temp->next;
    } while (temp != head);
    return 0; // Key not found
}

// Driver program (menu-driven)
int main()
{
    struct Node* head = NULL;
    int choice, data, position, count;

    do {
        printf("\n===== Circular Linked List =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Search\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');   // clear the bad input
            choice = -1;
            continue;
        }

        // Count nodes so position-based operations can be validated
        count = 0;
        if (head != NULL) {
            struct Node* temp = head;
            do {
                count++;
                temp = temp->next;
            } while (temp != head);
        }

        switch (choice) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Inserted %d at beginning\n", data);
                break;

            case 2:
                printf("Enter a value: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Inserted %d at end\n", data);
                break;

            case 3:
                printf("Enter a value: ");
                scanf("%d", &data);
                printf("Enter position (0 to %d): ", count);
                scanf("%d", &position);
                if (position < 0 || position > count) {
                    printf("Position out of range\n");
                } else {
                    insertAtPosition(&head, data, position);
                    printf("Inserted %d at position %d\n", data, position);
                }
                break;

            case 4:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    deleteFromBeginning(&head);
                    printf("Deleted from beginning\n");
                }
                break;

            case 5:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    deleteFromEnd(&head);
                    printf("Deleted from end\n");
                }
                break;

            case 6:
                if (head == NULL) {
                    printf("List is empty\n");
                    break;
                }
                printf("Enter position (0 to %d): ", count - 1);
                scanf("%d", &position);
                if (position < 0 || position >= count) {
                    printf("Position out of range\n");
                } else {
                    deleteAtPosition(&head, position);
                    printf("Deleted node at position %d\n", position);
                }
                break;

            case 7:
                printf("Circular Linked List: ");
                traverse(head);
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Element %d is found in the linked list.\n", data);
                } else {
                    printf("Element %d is not found in the linked list.\n", data);
                }
                break;

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    // Free all remaining nodes before exiting
    while (head != NULL) {
        deleteFromBeginning(&head);
    }

    return 0;
}