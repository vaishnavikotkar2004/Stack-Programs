// infix expression to postfix expressio...using for loop.....
#include<stdio.h>
#include<ctype.h>
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
 char ch;
 if(isempty())
   return -1;
 else
 {
  ch=s1.a[s1.top];
   s1.top--;
   return ch;
  }
}
int priority(char x)
{
  if(x=='(')
    return 0;
  if(x=='+'||x=='-')
    return 1;
  if(x=='*'||x=='/')
    return 2;
   if(x=='$'||x=='^')
    return 3;
    return 0;
}
int main()
{
 char str[100],ch;
 int i;
 printf("enter string");
 scanf("%s",str);
 init();
 for(i=0;str[i]!='\0';i++)
 {
  if(isalpha(str[i]))
     printf("%c",str[i]);
  else if(str[i]=='(')
     push(str[i]);
  else if(str[i]==')')
  {
   while((ch=pop())!='(')
      {
        printf("%c",ch);
       }
   }
   else
   {
     while(priority(s1.a[s1.top])>=priority(str[i]))
     {
        printf("%c",pop());
      }
    push(str[i]);
    }
  }
  while(!isempty())
  printf("%c",pop());
}
