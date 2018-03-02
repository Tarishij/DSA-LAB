//write a program to reverse a string using stack which must be
implemented using linked list

#include<stdio.h>
#include<stdlib.h>
void main()
{
struct node{
char value;
struct node *next;
};
typedef struct node list;
list *tmp,*top;
int n,i;
top=(list*)malloc(sizeof (list));
printf("enter size\n");
scanf("%d",&n);
scanf("%c",&top->value);
top->next=NULL;
for(i=1;i<=n;i++)
{
tmp=(list*)malloc(sizeof (list));
tmp->next=top;
scanf("%c",&tmp->value);
top=tmp;
}
while(top!=NULL)
{
printf("%c",top->value);
top=top->next;
}
}
