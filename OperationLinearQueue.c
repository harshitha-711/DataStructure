#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void main(){
   int item,ch;
   printf("--- QUEUE MENU ---\n");
   printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
   while(1){
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch){
           case 1:
              if (rear==MAX-1)
                 printf("Queue OverFlow");
              else{
                 printf("Enter element to be inserted:");
                 scanf("%d",&item);
                 if (front==-1)
                    front=0;
                 rear++;
                 queue[rear]=item;
                 printf("ELEMENT ADDED");
              }
              break;
           case 2:
              if (front==-1||front>rear)
                 printf("Queue UnderFlow");
              else{
                 front++;
                 printf("ELEMENT REMOVED");
                 if (front>rear){
                   front=-1;
                   rear=-1;
                 }
              }
              break;
           case 3:
              if (front==-1||front>rear)
                 printf("Queue Empty");
              else{
                 printf("Queue Elements: ");
                 for(int i =front;i<=rear;i++)
                    printf("%d\t",queue[i]);
              }
              break;
           case 4:
              printf("Exiting Program.\n");
              exit(0);
           default:
              printf("Invalid choice!!");
        }
    }
}