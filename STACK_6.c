//write a c program which accept the string and reverse each word of the following using static implementation of stack...
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
struct stack
{
  char a[MAX];
  int top;
}s;
void init()
{
 s.top=-1;
}
int isfull()
{
 if(s.top==MAX-1)
    return 1;
 else 
    return 0;
}
int isempty()
{
 if(s.top==-1)
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
    s.top++;
    s.a[s.top]=x;
   }
}
void disp()
{
 int i;
 for(i=s.top;i>=0;i--)
 printf("%c",s.a[i]);
}
int main()
{
 char s1[100];
 int i;
 init();
 printf("enter string");
 fgets(s1,100,stdin);
 for(i=0;s1[i]!='\0';i++)
 {
  if(s1[i]==' ')
    {
     disp();
     init();
     }
     else
     push(s1[i]);
  }
  disp();
}
