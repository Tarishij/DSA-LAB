//PRODUCT OF 2 SQUARE MATRIX

#include<stdio.h>
void main()
{
int a[3][3],b[3][3],c[3][3],i,j,k=0,sum=0,l=0;
printf("enter first matrix\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
scanf("%d",&a[i][j]);
printf("\n");
}printf("enter second matrix\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
scanf("%d",&b[i][j]);
printf("\n");
}
for(i=0;i<9;i++)
{
for(j=0;j<3;j++)
{
sum=sum+(a[k][j]*b[j][l]);
}
c[k][l]=sum;
l++;
sum=0;
if(l==3)
{
l=0;
k++;
}
}
printf("required matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf("%d",c[i][j]);
printf("\n");
}
}

