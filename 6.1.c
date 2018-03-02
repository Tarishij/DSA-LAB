//write a program to implement tower of Hanoi without recursion

#include<stdio.h>
int IsEmpty(int[],int);
int popa(int[]);
void pusha(int,int[]);
int popd(int[]);
void pushd(int,int[]);
int pops(int[]);
void pushs(int,int[]);
int s[10],d[10],a[10];
int tops=2,topd=-1,topa=-1;
void main()
{
int i,n,r,moves=1;
char dest='D',src='S',aux='A';
printf("enter no. of disc\n");
scanf("%d",&n);
for(i=0;i<n;i++)
s[i]=n-i;
for(i=1;i<=n;i++)
moves=moves*2;
moves=moves-1;
if(n%2==0){
dest='A';
aux='D';}
for(i=1;i<=moves;i++)
{
if(i%3==1)
{
if(IsEmpty(d,topd))
{
r=pops(s);
pushd(r,d);
printf("transfer disc from %c to %c\n",src,dest);
}
else if(IsEmpty(s,tops))
{
r=popd(d);
pushs(r,s);
printf("transfer disc from %c to %c\n",dest,src);
}
else if(s[tops]>d[topd])
{
r=popd(d);
pushs(r,s);
printf("transfer disc from %c to %c\n",dest,src);
}
else
{
r=pops(s);
pushd(r,d);
printf("transfer disc from %c to %c\n",src,dest);
}
}
if(i%3==2)
{
if(IsEmpty(a,topa))
{
r=pops(s);
pusha(r,a);
printf("transfer disc from %c to %c\n",src,aux);
}
else if(IsEmpty(s,tops))
{
r=popa(a);
pushs(r,s);
printf("transfer disc from %c to %c\n",aux,src);
}
else if(s[tops]>a[topa])
{
r=popa(a);
pushs(r,s);
printf("transfer disc from %c to %c\n",aux,src);
}
else
{
r=pops(s);
pusha(r,a);
printf("transfer disc from %c to %c\n",src,aux);
}
}
if(i%3==0)
{
if(IsEmpty(a,topa))
{
r=popd(d);
pusha(r,a);
printf("transfer disc from %c to %c\n",dest,aux);
}
else if(IsEmpty(d,topd))
{
r=popa(a);
pushd(r,d);
printf("transfer disc from %c to %c\n",aux,dest);
}
else if(d[topd]>a[topa])
{
r=popa(a);
pushd(r,d);
printf("transfer disc from %c to %c\n",aux,dest);
}
else
{
r=popd(d);
pusha(r,a);
printf("transfer disc from %c to %c\n",dest,aux);
}
}
}
}
int IsEmpty(int stack[],int top)
{
if(top==-1)
return 1;
else
return 0;
}
int pops(int stack[])
{
tops=tops-1;
return(stack[tops+1]);
}
void pushs(int value,int stack[])
{
tops=tops+1;
stack[tops]=value;
}
int popa(int stack[])
{
topa=topa-1;
return(stack[topa+1]);
}
void pusha(int value,int stack[])
{
topa=topa+1;
stack[topa]=value;
}
int popd(int stack[])
{
topd=topd-1;
return(stack[topd+1]);
}
void pushd(int value,int stack[])
{
topd=topd+1;
stack[topd]=value;
}
