
//MULTIPLY 2 NO.S WITHOUT USING * OPERATOR

#include<stdio.h>
void main()
{
int s=0,a,b,i;
printf("enter 2 numbers\n");
scanf("%d %d",&a,&b);
for(i=1;i<=b;i++)
s=s+a;
printf("multiplication=%d",s);
}
