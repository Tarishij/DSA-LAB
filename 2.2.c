//Write a C program to convert the array into new array which contains new
element as multiplication of previous and next element of the old element.

#include<stdio.h>
void main()
{
int n;
scanf("%d",&n);
int a[n],i;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
a[0]=a[1];
for(i=1;i<n-1;i++)
a[i]=a[i-1]*a[i+1];
a[n-1]=a[n-2];
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
