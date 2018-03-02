//write a program to find a^b recursively

#include<stdio.h>
void rec(int,int);
int a=1;
void main()
{
int n,k;
printf("enter values of n and k\n");
scanf("%d %d",&n,&k);
rec(n,k);
}
void rec(int n,int k)
{
a=a*n;
if(k>1)
rec(n,k-1);
else
printf("%d\n",a);
}
