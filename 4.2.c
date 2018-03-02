//write a program to implement insertion sort

#include <stdio.h>
void main()
{
int i,j,n;
scanf("%d",&n);
int a[n],key;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(j=1;j<n;j++)
{
key=a[j];
i=j-1;
while(i>=0&&a[i]>key)
{
a[i+1]=a[i];
i-- ;
}
a[i+1]=key;
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
