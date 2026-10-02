#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

struct node *start = NULL;   // shared head of the list

struct node *create_node(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    p->previous = NULL;
    return p;
}

void insert_beg(struct node *p) {
    p->next = start;
    p->previous = NULL;
    if (start != NULL)
        start->previous = p;
    start = p;
    printf("Inserted at the beginning\n");
}

void insert_end(struct node *p) {
    if (start == NULL) {
        start = p;
    } else {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->previous = temp;
    }
    printf("Inserted at the end\n");
}

// insert p after node number c (1 = first node)
void insert_after(int c, struct node *p) {
    struct node *temp = start;
    for (int i = 1; i < c && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        free(p);
        return;
    }
    p->next = temp->next;
    p->previous = temp;
    if (temp->next != NULL)
        temp->next->previous = p;
    temp->next = p;
    printf("Inserted after node %d\n", c);
}

// delete node number c (1 = first node)
void delete_at(int c) {
    struct node *temp = start;
    for (int i = 1; i < c && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (temp->previous != NULL)
        temp->previous->next = temp->next;
    else
        start = temp->next;          // deleting the first node
    if (temp->next != NULL)
        temp->next->previous = temp->previous;
    free(temp);
    printf("Node %d deleted\n", c);
}

void display() {
    struct node *p = start;
    while (p != NULL) {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    insert_end(create_node(10));
    insert_end(create_node(20));
    insert_end(create_node(30));
    insert_beg(create_node(5));
    display();                       // 5 <-> 10 <-> 20 <-> 30 <-> NULL

    insert_after(2, create_node(15));
    display();                       // 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

    delete_at(1);
    display();                       // 10 <-> 15 <-> 20 <-> 30 <-> NULL
    return 0;
}