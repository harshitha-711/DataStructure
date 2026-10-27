#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX], front=-1, rear=-1;
void enqueue(int val) {
    if ((front==0 && rear==MAX-1)||(front==rear+1)) {
        printf("Queue Full\n");
        return;
    }
    if (front==-1)
        front=rear = 0;
    else if (front!=0 && rear==MAX-1)
        rear=0;
    else
        rear=rear + 1;
    queue[rear] = val;
    printf("ELEMENT INSERTED\n");
}
void dequeue() {
    if (front==-1) {
        printf("Queue Empty\n");
        return;
    }
    printf("ELEMENT DELETED %d\n", queue[front]);
    if (front==rear)
        front=rear=-1;
    else if (front==MAX-1)
        front=0;
    else
        front=front+1;
}
void display() {
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = front; ; i=i+1) {
        printf("%d\t", queue[i]);
        if (i==rear) 
           break;
        if(i==MAX-1)
           i=-1;        
    }
    printf("\n");
}
void main() {
    int ch,val;
    printf("--- CIRCULAR QUEUE MENU ---\n");
    printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
              printf("Enter element to be inserted:");
              scanf("%d",&val);
              enqueue(val); 
              break;
            case 2:
              dequeue(); 
              break;
            case 3: 
              display();
              break;
            case 4:
              printf("Exiting Program.\n"); 
              exit(0);
            default:
              printf("Invalid choice!!\n");
        }
    }
}