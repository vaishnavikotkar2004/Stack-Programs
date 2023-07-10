// infix expression to postfix expression using stach.....(while loop)...
#include<stdio.h>
#include<string.h>
#define MAX 100
struct stack
{
  char a[MAX];
  int top;
}s1;
void init()
{
 s1.top=-1;
}
int isfull()
{
  if(s1.top==MAX-1)
     return 1;
  else
     return 0;
}
int isempty()
{
  if(s1.top==-1)
     return 1;
  else
     return 0;
}
void push(char x)
{
  if(isfull())
     printf("stack is full");
  else
  {
    s1.top++;
    s1.a[s1.top]=x;
  }
}
char pop()
{
  char y;
  if(isempty())
    return -1;
  else
  {
    y=s1.a[s1.top];
     s1.top--;
     return y;
  }
}
int priority(char x)
{
  if(x=='(')
     return 0;
  if(x=='-'||x=='+')
     return 1;
  if(x=='*'||x=='/')
     return 2;
  if(x=='$'||x=='^')
     return 3;
     return 0;
}
int main()
{
  char exp[100],*e,x;
  printf("enter expression");
  scanf("%s",exp);
  e=exp;
  init();
  while(*e!='\0')
  {
    if(isalnum(*e))
       printf("%c",*e);
   else if(*e=='(')
       push(*e);
   else if(*e==')')
   {
     while((x=pop())!='(')
     printf("%c",x);
   }
   else
   {
     while(priority(s1.a[s1.top]>=priority(*e)))
           printf("%c",pop());
           push(*e);
   }
   e++;
  }
  while(!isempty())
  {
    printf("%c",pop());
  }
}
