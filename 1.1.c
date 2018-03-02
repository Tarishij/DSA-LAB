//LINEAR SEARCH IN 1-D ARRAY

#include<stdio.h>;
void main()
{
int n,i,num;
printf("enter the size of array\n");
scanf("%d",&n);
int a[n];
printf("enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the number to be searched\n");
scanf("%d",&num);
for(i=0;i<n;i++)
{
if(a[i]==num)
{
printf("number is at %d position\n",i+1);
break;
}
else if(i==n-1)
printf("number does not exist\n");
}
}
