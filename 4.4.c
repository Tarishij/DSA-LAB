//write a program to separate even and odd numbers in array via bubble
sort

#include<stdio.h>
void main()
{
int n,s2=0,i,j,s1=0,b;
scanf("%d",&n);
int a[n],e[n],o[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
if(a[i]%2==0)
{
e[s2]=a[i];
s2++;
}
else
{
o[s1]=a[i];
s1++;
}
}
for(i=0;i<=s1-2;i++)
{
b=1;
for(j=0;j<=s1-2- i;j++)
{
if(o[j]>o[j+1])
{
o[j]=o[j]+o[j+1];
o[j+1]=o[j]-o[j+1];
o[j]=o[j]-o[j+1];
b=2;
}
}
if(b==1)
break;
}
for(i=0;i<s1;i++)
printf("%d ",o[i]);
printf("\n");


for(i=0;i<=s2-2;i++)
{
b=1;
for(j=0;j<=s2-2- i;j++)
{
if(e[j]>e[j+1])
{
e[j]=e[j]+e[j+1];
e[j+1]=e[j]-e[j+1];
e[j]=e[j]-e[j+1];
b=2;
}
}
if(b==1)
break;
}
for(i=0;i<s2;i++)
printf("%d ",e[i]);
}
