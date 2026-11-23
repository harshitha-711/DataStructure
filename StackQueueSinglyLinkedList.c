#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL,*rear=NULL,*front=NULL;

void push(int value){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}

void pop(){
    struct node *temp;
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    printf("Deleted element: %d\n",temp->data);
    top=top->next;
    free(temp);
}

void enqueue(int value){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(front==NULL){
        front=rear=newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}

void dequeue(){
    struct node *temp;
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    temp=front;
    printf("Deleted element: %d\n",temp->data);
    front=front->next;
    free(temp);
    if(front==NULL)
        rear=NULL;
}

void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,value;
    printf("\n--- STACK AND QUEUE MENU ---");
    printf("\n1. PUSH\n2. POP\n3. DISPLAY STACK\n4. ENQUEUE\n5. DEQUEUE\n6. DISPLAY QUEUE\n7. EXIT");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display(front);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}