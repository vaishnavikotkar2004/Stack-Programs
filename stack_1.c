// Menu driven program using stack function.
#include<stdio.h>
#define MAX 5
struct stack
{
 int a[MAX];
 int top;
}s1;
void init()
{
 s1.top=-1;
}
int isempty()
{
 if(s1.top==-1)
    return 1;
 else
    return 0;
}
int isfull()
{
 if(s1.top==MAX-1)
    return 1;
 else
    return 0;
}
void push(int num)
{
 if(isfull())
 {
   printf("stack is full dont push");
  }
 else
 {
   s1.top++;
   s1.a[s1.top]=num;
   printf("\n push successfully");
 }
}
void pop()
{
 int value;
 if(isempty())
 {
   printf("\n stack is empty ..so dont pop");
 }
 else
 {
   value=s1.a[s1.top];
   s1.top--;
   printf("\n poped values=%d",value);
 }
}
void disp()
{
 int i;
 for(i=s1.top;i>=0;i--)
 {
   printf("%d\n",s1.a[i]);
 }
}
int main()
{
  int ch,num;
  init();
  do
  {
    printf("\n1-push \n2-pop \n3-display \n enter choice");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("enter number");
            scanf("%d",&num);
            push(num);
            break;
     case 2:pop();
            break;
     case 3:disp();
             break;
     default:printf("invalid choice");
             break;
    }
  }while(ch<4);
}
