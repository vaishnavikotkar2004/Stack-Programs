// Infix to postfix and Evaluation of postfix.....
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
struct stack
{
 int a[MAX];
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
void push(int num)
{
 if(isfull())
    printf("stack is full");
  else
  {
    s.top++;
    s.a[s.top]=num;
  }
}
int pop()
{
 int val;
 if(isempty())
    printf("stack is empty");
 else
 {
   val=s.a[s.top];
   s.top--;
   return val;
 }
}
int main()
{
  char s1[100];
  int p,q,r,s,i,value1,value2,result;
  printf("enter string");
  fgets(s1,100,stdin);
  printf("enter values P Q R S");
  scanf("%d%d%d%d",&p,&q,&r,&s);
  init();
  for(i=0;s1[i]!='\0';i++)
  {
    if(isalpha(s1[i]))
    {
     switch(s1[i])
     {
       case 'P':push(p);break;
       case 'Q':push(q);break;
       case 'R':push(r);break;
       case 'S':push(s);break;
     }
    }
    else
    {
      value1=pop();
      value2=pop();
      switch(s1[i])
      {
        case '+':result=value2+value1;break;
        case '-':result=value2-value1;break;
        case '*':result=value2*value1;break;
        case '/':result=value2/value1;break;
      }
      push(result);
    }
   }
    printf("\n result=%d",pop());
}
