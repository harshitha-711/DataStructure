#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create(){
    struct node *newnode, *temp;
    int n, i;
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}
void insertFirst(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void insertPosition(){
    struct node *newnode, *temp;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if(pos == 1) {
        insertFirst();
        return;
    }
    temp = head;
    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}
void insertEnd(){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else  {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void display()
{
    struct node *temp;
    if(head == NULL)  {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Linked List: ");
    while(temp != NULL)  {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main(){
    int ch;
    create();
    printf("\n---Insertion Menu---\n 1. Insert at First\n 2. Insert at Position\n 3. Insert at End\n 4. Display\n 5. Exit");
    while(true)  {      
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertFirst(); break;
            case 2: insertPosition(); break;
            case 3: insertEnd(); break;
            case 4: display(); break;
            case 5: printf("Exiting Program.\n");exit(0);
            default: printf("Invalid choice\n");
        }
    } 
}