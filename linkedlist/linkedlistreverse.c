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

    //reverse

    struct node *p, *q, *r;
    if (head == NULL)
    {
        printf("List is empty");
    }

    p = head;
    q = p->nextNode;
    p->nextNode=NULL;
    while(q!=NULL){
        r = q->nextNode;
        q->nextNode = p;
        p = q;
        q = r;
    }
    head = p;
    
    
    struct node *k = head;
    while( k != NULL) {
        if(k->nextNode == NULL){
            printf("%c", k->Value);
        } else {
             printf("%c -> ", k->Value);
        }
        k = k->nextNode;
    }

    return 0;
}
