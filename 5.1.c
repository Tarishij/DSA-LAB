//Write a program to convert an infix expression into prefix expression

#include <stdio.h>
int top=-1;
void push(char[],char);
int IsFull(int);
void pop();
int IsEmpty();
char Top(char []);
int isp(char);
int icp(char);
void main()
{
  int n,i,j=0;
  printf("enter elements in string\n");
  scanf("%d",&n);
  char a[n],s[n],o[n],b[n],stack[n],t;
  printf("enter string\n");
  scanf("%s",a);
  for(i=n-1;i>=0;i--)
  {
      if(a[i]=='(')
      s[n-1-i]=')';
      else if(a[i]==')')
      s[n-1-i]='(';
      else
      s[n-1-i]=a[i];
  }
 
  for(i=0;i<n;i++)
  {
      if(s[i]>=97&&s[i]<=122)
      {
          o[j]=s[i];
          j++;
      }
      else if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='(')
      {
          while(!IsEmpty())
          {
              t=Top(stack);
              if(isp(t)>icp(s[i])){
              o[j]=t;
              j++;
              pop();
              }else
              break;
              
          }
          push(stack,s[i]);
    
      }
      else if(s[i]==')')
      {
          t=Top(stack);
          while(t!='(')
          {
              o[j]=t;
              j++;
              pop();
              t=Top(stack);
          }pop();
      }
      if(i==n-1)
      { while(!IsEmpty()){
          t=Top(stack);
           o[j]=t;
              j++;
              pop();
                 }
      }
  }
printf("%s\n",o);
  for(i=j-1;i>=0;i--)
      b[j-1-i]=o[i];
      printf("%s",b);
}
void push(char stack[],char val)
{
    
        top=top+1;
        stack[top]=val;
       
    
}

void pop()
{
    if(IsEmpty())
    printf("no element");
    else
    top=top-1;
}
int IsEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
char Top(char stack[])
{
    return(stack[top]);
}
int isp(char t)
{
    if(t=='^')
    return 5;
    else if(t=='*'||t=='/')
    return 4;
    else if(t=='+'||t=='-')
    return 2;
    else if(t=='(')
    return 0;
}
int icp(char c)
{
    if(c=='^')
    return 6;
    else if(c=='*'||c=='/')
    return 3;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='(')
    return 100;
}
