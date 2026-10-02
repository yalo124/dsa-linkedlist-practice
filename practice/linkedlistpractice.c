#include <stdio.h>
#include <stdlib.h>


struct element{
    int value;
    struct element *nextElement;
};

int main(){
    struct element *current, *first, *last, *newElement, *temporary;
    current = NULL;
    first = NULL;
    last = NULL;

    current = (struct element *)malloc(sizeof(struct element));
    current ->value = 1;
    current ->nextElement = NULL;
    first = current;
    last = current;

    current = (struct element *)malloc(sizeof(struct element));
    current ->nextElement = NULL;
    current ->value = 2;
    first ->nextElement = current;
    last = current;

    newElement = (struct element *)malloc(sizeof(struct element));
    printf("Enter a new element: ");
    scanf("%d", &newElement->value);
    newElement -> nextElement = first;
    first = newElement;

    newElement = (struct element *)malloc(sizeof(struct element));
    printf("Enter last number: ");
    scanf("%d", &newElement->value);
    newElement ->nextElement = 0;
    last->nextElement = newElement;
    last = newElement;


    int pos, count = 0, i = 1;

    struct element *c = first;

    while(c !=NULL){
        count++;
        c = c->nextElement;
    }

    printf("Enter position number: ");
    scanf("%d", &pos);

    if(pos > count || pos < 1){
        printf("Invalid position");
    } else {
        newElement = (struct element *)malloc (sizeof(struct element));
        temporary = first;
        while (i < pos){
            temporary = temporary->nextElement;
            i++;
        }

        printf("Enter the value: ");
        scanf("%d", &newElement ->value);

        newElement ->nextElement = temporary->nextElement;
        temporary->nextElement = newElement;
        if(temporary == last){
            last = newElement;
        }

        struct element *display = first;
        while( display != NULL) {
        printf("%d ", display->value );
        display = display->nextElement;
        }
    }
}