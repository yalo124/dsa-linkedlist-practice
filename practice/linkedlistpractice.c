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

    struct element *display = first;
    while( display != NULL) {
        printf("%d", display->value );
        display = display->nextElement;
    }
}