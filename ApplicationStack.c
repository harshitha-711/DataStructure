#include<stdio.h>
#include<ctype.h>
//isalnum()
#define MAX 50
char stack[MAX];
int top=-1;
void push(char x){
    if(top==MAX-1)
       printf("StackOverFlow");
    stack[++top]=x;
}
char pop(){
    if(top==-1)
      printf("StackUnderFlow");
    return stack[top--];
}
int precedence(char x){
    if(x=='^')
       return 3;
    else if ( x=='*' || x=='/' || x=='%')
       return 2;
    else if ( x=='+' || x=='-')
       return 1;
    else
       return 0;
}
void main(){
    char infix[100],postfix[100];
    int i=0,j=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    push('(');
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isalnum(ch))
           postfix[j++]=ch;
        else if(ch=='(')
           push(ch);
        else if(ch==')'){
            while(stack[top]!='(')
               postfix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch))
               postfix[j++]=pop();
            push(ch);
        }
        i++;
    }
    while(stack[top]!='(')
        postfix[j++]=pop();
    pop();
    postfix[j]='\0';
    printf("Postfix Expression:%s\n",postfix);
}