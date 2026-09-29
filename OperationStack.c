#include<stdio.h>
#include<stdlib.h>
//exit()
#define MAX 5
void main(){
    int stack[MAX],ch,item,top=-1;
    printf("--- STACK MENU ---\n");
    printf(" 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              if (top==MAX-1)
                printf("Stack OverFlow");
              else{
                printf("Entter element to be inserted:");
                scanf("%d",&item);
                top++;
                stack[top]=item;
                printf("ELEMENT ADDED");
             }
              break;
            case 2:
              if(top==-1)
                printf("Stack Underflow");
              else{
                printf("ELEMENT REMOVED");
                top--;
              }
              break;
            case 3:
              if (top==-1)
                 printf("Stack Empty");
              else{
                 printf("Stack Elements (from top to bottom) :\n");
                 for(int i=top;i>=0;i--)
                     printf("%d\n",stack[i]);
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