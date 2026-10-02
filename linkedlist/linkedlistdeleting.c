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


    /*
        current = head;
        head = head->nextNode;
        free(current);
    */

    /*
    struct node *prev;
    current = head;
    while(current->nextNode != 0){
        prev = current;
        current = current->nextNode;
    }

    if(current == head){
        head = NULL;
    } else {
        prev ->nextNode = NULL;
        tail = prev;
    }

    free(current);
    */
    
    /*
    struct node *nextNodee;
    int pos, i=1;

    current = head;
    printf("Enter the position: ");
    scanf("%d", &pos);

    while( i < pos - 1){
        current = current->nextNode;
        i++;
    }

    nextNodee = current->nextNode;
    current->nextNode = nextNodee->nextNode;
    free(nextNodee);
    */
    
    
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
