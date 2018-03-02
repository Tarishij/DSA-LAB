//Write a program to implement queue using stack

#include <stdio.h>
int s1[50],s2[50],top1=-1,top2=-1,count=0;
void insert();
void delete();
int s1empty();
int s2empty();
void s1push(int);
void s2push(int);
int s1pop();
int s2pop();
void display();
void main()
{
int c;
int d;
do{
printf("enter :1 for insertion\n2:for deletion\n3:for display");
scanf("%d",&c);
switch(c)
{
case 1:
    insert();
    break;
case 2:
    delete();
    break;
case 3:
    display();
    break;
}
printf("want to perform more operations?1=yes,2=no");
scanf("%d",&d);
}while(d==1);
}
void insert()
{
int n;
printf("enter value\n");
scanf("%d",&n);
s1push(n);
count++;
}
void delete()
{
int r;
   while(!s1empty())
   {
   r=s1pop();
   s2push(r);
   }
s2pop();
count--;
   while(!s2empty())
   {
   r=s2pop();
   s1push(r); 
   }
}
void display()
{
int i=0;
for(;i<count;i++)
{
printf("%d ",s1[i]);
}
}
int s1empty()
{
if(top1==-1)
return 1;
else
return 0;
}
int s2empty()
{
if(top2==-1)
return 1;
else
return 0;
}
void s1push(int value)
{
top1=top1+1;
s1[top1]=value;
}
void s2push(int value)
{
top2=top2+1;
s2[top2]=value;
}
int s1pop()
{
int a;
a=s1[top1];
top1=top1-1;
return a;
}
int s2pop()
{
int a;
a=s2[top2];
top2=top2-1;
return a;
}
