//bubble sort

#include <stdio.h>
void main()
{
int i,j,n;
scanf("%d",&n);
int a[n],b;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<=n-2;i++)
{
b=1;
for(j=0;j<=n-2- i;j++)
{
if(a[j]>a[j+1])
{
a[j]=a[j]+a[j+1];
a[j+1]=a[j]-a[j+1];
a[j]=a[j]-a[j+1];
b=2;
}
}
if(b==1)
break;
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
