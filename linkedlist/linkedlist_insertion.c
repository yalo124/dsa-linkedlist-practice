#include <stdio.h>
#include <stdlib.h>

struct node {
    char Value;
    struct node *nextNode;
};

int main(){
    struct node *current, *head, *tail, *newNode, *temp;
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

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf(" %c", &newNode->Value);
    newNode -> nextNode = head;
    head = newNode;

    struct node *p = head;
    while( p != NULL) {
        printf("%c -> ", p->Value);
        p = p->nextNode;
    }

    newNode =(struct node *)malloc (sizeof(struct node));
    printf("\nEnter last data: ");
    scanf(" %c", &newNode->Value);
    newNode->nextNode = 0;
    tail->nextNode = newNode;
    tail = newNode;

    struct node *k = head;
    while( k != NULL) {
        printf("%c -> ", k->Value);
        k = k->nextNode;
    }

    int pos, count = 0, i =1;

    return 0;
}