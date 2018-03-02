//write a program to implement selection sort


#include <stdio.h>
void main()
{
int i,j,n;
scanf("%d",&n);
int a[n],min,index;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{
min=a[i];
for(j=i+1;j<n;j++)
{
if(a[j]<min){
min=a[j];
index=j;}
}
if(min!=a[i]){
a[i]=a[i]+a[index];
a[index]=a[i]-a[index];
a[i]=a[i]-a[index];}
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
