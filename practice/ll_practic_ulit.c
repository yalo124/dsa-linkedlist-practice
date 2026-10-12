#include <stdio.h>
#include <stdlib.h>

struct node {
    double number;
    struct node *nextNode;
};

int main(){
    struct node *current, *start, *end;
    current = NULL;
    start = NULL;
    end = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    current -> number = 1.23;
    current -> nextNode = NULL;
    start = current;
    end = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> number = 2.17;
    current -> nextNode = NULL;
    start ->nextNode = current;
    end = current;

    current = (struct node *)malloc(sizeof(struct node));
    current -> number = 3.12;
    current -> nextNode = NULL;
    end ->nextNode = current;
    end = current;

    struct node *o = start;
    while(o !=NULL){
        printf("%.2lf ", o->number);
        o = o->nextNode;
    }

    return 0;

}