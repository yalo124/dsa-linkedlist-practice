#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addFront(struct node **head){
   
    struct node *n = (struct node *)malloc(sizeof(struct node));
    printf("Enter a number: ");
    scanf("%d", &n->data);

    if(*head == NULL){
        n->next = n;
        *head = n;
    } else{
        struct node *t = *head;
        while(t->next!=*head)
            t = t->next;
        n->next = *head;
        t ->next = n;
        *head = n;
    }
}

void addLast(struct node **head){
    struct node *t = *head;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    printf("Enter a last data: ");
    scanf("%d", &n->data);
    if(*head == NULL){
        n->next = n;
        *head = n; 
    } else {
        n->next = *head;
        while(t->next!=*head)
            t = t->next;
        t->next = n;
        n->next = *head;
    }
}

void delFront(struct node **head){

    if(*head == NULL){
        printf("empty list");
    } else if ((*head)->next == *head){
        free(*head);
        *head = NULL;
    } else {
        struct node *old = *head;
        struct node *t = *head;
        while(t->next!=*head)
            t = t->next;
        *head = old->next;
        t->next=*head;
        free(old);
    }
}

void dellast(struct node **head){
    if(*head == NULL) {
        printf("ashdasa");
    } else if((*head)->next == *head){
        free(*head);
        *head = NULL;
    } else {
        struct node *t= *head;
        while(t->next->next!=*head)
            t = t->next;
        free(t->next);
        t->next = *head;
    }
}
int main(){

    struct node *head = NULL;


    addFront(&head);
    addFront(&head);
    addLast(&head);
    delFront(&head);
    dellast(&head);


    if(head !=NULL){
        struct node *p = head;

        do{
            printf("%d ", p->data);
            p = p->next;
        } while (p!=head);
        
    }

    
    return 0;
}