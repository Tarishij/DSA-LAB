//Write a C program to check if the string is palindrome or not.

#include<stdio.h>
void main()
{
int n,i;
printf("enter size of string\n");
scanf("%d",&n);
char s[n],*p;
printf("enter the string\n");
scanf("%s",s);
p=&s[n-1];
for(i=0;i<=n/2;i++)
{
if(s[i]!=*p)
{
printf("not\n");
break;}
else if(i==n/2){
printf("yes\n");
break;}
p--;
}
}
