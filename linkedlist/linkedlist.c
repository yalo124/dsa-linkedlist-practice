#include <stdio.h>
#include <stdlib.h>

struct node {
    char Value;
    struct node *nextNode;
};

int main(){
    struct node *current, *head, *tail;
    current = NULL;
    head = NULL;
    tail = NULL;   

    current = (struct node *)malloc(sizeof(struct node));
    current ->Value = 'A';
    current -> nextNode = NULL;
    head = current;
    tail = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> Value = 'B';
    current ->nextNode = NULL;
    head -> nextNode = current;
    tail = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> Value = 'C';
    current ->nextNode = NULL;
    tail -> nextNode = current;
    tail = current;

    struct node *p = head;
    while( p != NULL) {
        printf("%c -> ", p->Value);
        p = p->nextNode;
    }
    return 0;
}