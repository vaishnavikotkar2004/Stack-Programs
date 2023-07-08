//Write a c program to check whether a given string is palindrome or not(use stack).
#include<stdio.h>
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
void push(char c)
{
  if(isfull())
    printf("stack is full....");
  else
  {
    s1.top++;
    s1.a[s1.top]=c;
  }
}
char pop()
{
  char ch;
  if(isempty())
    printf("stack is empty..");
  else
  {
    ch=s1.a[s1.top];
    s1.top--;
    return ch;
  }
}
int main()
{
  char str[100],c;
  int i;
  printf("enter string");
  scanf("%s",&str);
  init();
  for(i=0;str[i]!='\0';i++)
  {
    push(str[i]);
  }
  for(i=0;str[i]!='\0';i++)
  {
   if(str[i]!=pop())
    {
      break;
     }
   }
  if(isempty())
    printf("string is palindrome");
  else
    printf("string is not palindrome");
}
