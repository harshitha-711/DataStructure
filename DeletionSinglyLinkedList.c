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
    printf(" \nEnter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
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
void deleteFirst(){
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}
void deletePosition(){
    struct node *temp, *prev;
    int pos, i;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }
    temp = head;
    if(pos == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }
    for(i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}
void deleteLast(){
    struct node *temp, *prev;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }
    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}
void display(){
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main()
{
    int ch;
    create();
    printf("\n---Deletion Menu---\n 1. Delete First\n 2. Delete at Specified Position\n 3. Delete Last\n 4. Display\n 5. Exit\n");
    while(true){
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: deleteFirst(); break;
            case 2: deletePosition(); break;
            case 3: deleteLast(); break;
            case 4: display(); break;
            case 5: printf("Exiting Program.\n");exit(0);
            default: printf("Invalid choice\n");
        }
    }    
}