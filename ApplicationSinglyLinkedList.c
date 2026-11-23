#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* createList(){
    struct node *head=NULL,*temp,*newnode;
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
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

struct node* sortList(struct node *head){
    struct node *temp,*ptr;
    int swap;
    for(temp=head;temp!=NULL;temp=temp->next){
        for(ptr=temp->next;ptr!=NULL;ptr=ptr->next){
            if(temp->data>ptr->data){
                swap=temp->data;
                temp->data=ptr->data;
                ptr->data=swap;
            }
        }
    }
    return head;
}

struct node* reverseList(struct node *head){
    struct node *prev=NULL,*current=head,*nextnode;
    while(current!=NULL){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    return prev;
}

struct node* concatenate(struct node *head1,struct node *head2){
    struct node *temp;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;
    return head1;
}

int main(){
    struct node *head1=NULL,*head2=NULL;
    printf("\nEnter FIRST linked list\n");
    head1=createList();
    printf("\nEnter SECOND linked list\n");
    head2=createList();

    printf("\nFirst list: ");
    display(head1);
    printf("Second list: ");
    display(head2);

    head1=sortList(head1);
    printf("\nSorted first list: ");
    display(head1);

    head1=reverseList(head1);
    printf("\nReversed first list: ");
    display(head1);

    head1=concatenate(head1,head2);
    printf("\nConcatenated list: ");
    display(head1);

    return 0;
}