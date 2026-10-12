#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

struct node *create_node(int value) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    n->data = value;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

/* Insert at the beginning */
void insert_beginning(struct node **head, int value) {
    struct node *new_node = create_node(value);
    if (new_node == NULL) return;

    new_node->next = *head;
    if (*head != NULL)
        (*head)->previous = new_node;
    *head = new_node;
    printf("Node inserted at beginning\n");
}

/* Insert at the end */
void insert_end(struct node **head, int value) {
    struct node *new_node = create_node(value);
    if (new_node == NULL) return;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->previous = temp;
    }
    printf("Node inserted at end\n");
}

/* Insert at a particular position (1 = first node) */
void insert_position(struct node **head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insert_beginning(head, value);
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct node *new_node = create_node(value);
    if (new_node == NULL) return;

    new_node->next = temp->next;
    new_node->previous = temp;
    if (temp->next != NULL)
        temp->next->previous = new_node;
    temp->next = new_node;
    printf("Node inserted at position %d\n", pos);
}

/* Delete the first node (head) */
void delete_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->previous = NULL;
    free(temp);
    printf("Head node deleted\n");
}

/* Delete the last node (tail) */
void delete_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->previous != NULL)
        temp->previous->next = NULL;
    else
        *head = NULL;   /* it was the only node */
    free(temp);
    printf("Tail node deleted\n");
}

/* Delete the node at a particular position (1 = first node) */
void delete_position(struct node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        delete_beginning(head);
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    temp->previous->next = temp->next;
    if (temp->next != NULL)
        temp->next->previous = temp->previous;
    free(temp);
    printf("Node at position %d deleted\n", pos);
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    for (struct node *k = head; k != NULL; k = k->next)
        printf("%d ", k->data);
    printf("\n");
}

void free_list(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    struct node *head = NULL;
    int choice, value, pos;

    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Display\n5. Delete head\n6. Delete tail\n7. Delete at position\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_beginning(&head, value);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 3:
                printf("Enter a value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_position(&head, value, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                delete_beginning(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_position(&head, pos);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    free_list(head);
    return 0;
}