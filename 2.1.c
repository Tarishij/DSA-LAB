//to FIND MAJOR ELEMENT IN  AN ARRAY
(to find the most occurring element in an array. (i.e.
Frequency of that element > size/2)

#include<stdio.h>
void main()
{/*major numbers*/
int n;
scanf("%d",&n);
int a[n],i,f=0,j;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(j=0;j<n;j++)
{
for(i=j;i<n;i++)
{
if(a[i]==a[j])
f++;
}
if(f>=n/2)
printf("%d ",a[j]);
f=0;
}
}
