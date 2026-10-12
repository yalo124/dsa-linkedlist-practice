#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

void insert_element(struct node *head){
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &head->data);
    
    if(head == NULL){
        printf("Node inserted");
    } else {
        struct node *temp = head;
        temp->previous = head;
        head->next = temp;
        printf("node inserted");
    }
}

int main(){

    struct node *head = NULL;
    insert_element(head);

    while(head != NULL){
        struct node *k = head;
        
            printf("%d ", k->data);
            k = k->next;
        
    }
}