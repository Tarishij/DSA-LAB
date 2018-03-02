//LINEAR SEARCH IN 2D array


#include<stdio.h>
void main()
{
int row,column,b,num;
printf("enter rows and column\n");
scanf("%d %d",&row,&column);
int a[row][column],i,j;
printf("enter elements\n");
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)
scanf("%d",&a[i][j]);
}
printf("enter the number to be searched\n");
scanf("%d",&num);
for(i=0;i<row;i++)
{
for(j=0;j<column;j++)
{
if(a[i][j]==num)
{b=1;
printf("first occurence of %d is in %d row and %d column",num,i+1,j+1);
break;
}
else if(i==row-1&&j==column-1)
printf("%d does not exist in array",num);
}
if(b==1)
break;
}
}


