#include<stdio.h>
#include<string.h>
void main(){
    char st[20],strev[20],stack[20],ch;
    int ind,top=-1;
    printf("Enter the String:");
    scanf("%s",st);
    int l=strlen(st);
    printf("Enter the character:");
    scanf(" %c",&ch);
    for(int i=0;i<=l;i++){
        if(st[i]==ch){
          ind=i;
          break;
        }
    }
    for(int i=l-1;i>=ind+1;i--)
        stack[++top]=st[i];
    for(int i=0;i<=ind;i++)
        stack[++top]=st[i];
    for(int i=0;i<l;i++)
        strev[i]=stack[top--];
    printf("Modified String:%s",strev);
}