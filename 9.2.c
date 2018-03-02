///In a graph implement by list, code for:
//1.Adding or removing vertices
//2. Adding or removing edges
//3.check whether there is a path from one given node to another.

#include <stdio.h>
#include<stdlib.h>
struct node{
int value;
struct node* next;
}*a[20];
int n,index=-1,k=0,b[20],visited[20]={0};
void edge(int,int);
struct node* create_vertex(int);
void remove_edge(int,int);
void remove_vertex(int);
int path(int,int);
void DFS(int);
void main()
{
int c,b,i,e,s,e1,y,t,flag;
struct node*ptr;
printf("enter no.of vertices\n");
scanf("%d",&n);
printf("enter values\n");
for(i=0;i<n;i++)
{
scanf("%d",&s);
a[i]=create_vertex(s);
}
printf("enter no of edges\n");
scanf("%d",&e);
printf("enter edges\n");
for(i=0;i<e;i++)
{
scanf("%d %d",&c,&b);
edge(c,b);
}
do{
printf("1:add vertex\t2:add edge in existing graph\t3:remove edge\t4:remove
vertex\n5:finding a path from one vertex to another\t6:display linked list
representation\n");
scanf("%d",&y);
switch(y)
{
case 1:
printf("enter vertex value\n");
scanf("%d",&s);
a[n]=create_vertex(s);
n++;
printf("enter total. of (outgoing+incoming) edges of new vertex\n");
scanf("%d",&e1);
printf("enter edge\n");
for(i=0;i<e1;i++)
{
scanf("%d %d",&c,&b);
edge(c,b);
}
break;
case 2:
printf("enter no. of edges you want to insert\n");
scanf("%d",&e);
printf("enter edges\n");
for(i=0;i<e;i++)
{
scanf("%d %d",&c,&b);
edge(c,b);
}
break;
case 3:
printf("enter the edge which is to be removed\n");
scanf("%d %d",&c,&b);
remove_edge(c,b);
break;
case 4:
printf("enter the vertex you want to remove\n");
scanf("%d",&b);
remove_vertex(b);
break;
case 5:
printf("enter the two values\n");
scanf("%d %d",&b,&c);
flag=path(b,c);
if(flag==1)
printf("yes\n");
else
printf("no\n");
break;
case 6:
for(i=0;i<n;i++)
{
if(i==index)
continue;
ptr=a[i];
while(ptr)
{
printf("%d ",ptr->value);
ptr=ptr->next;
}
printf("\n");
}
break;
}
printf("more:1\tstop:2");
scanf("%d",&t);
}while(t==1);

}
void edge(int v1,int v2)
{
struct node* tmp,*ptr;
tmp=(struct node*)malloc(sizeof(struct node));
tmp->value=v2;
tmp->next=NULL;
ptr=a[v1];
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=tmp;
ptr=a[v1];
}
struct node* create_vertex(int x)
{ struct node*head;
head=(struct node*)malloc(sizeof(struct node));
head->value=x;
head->next=NULL;
return head;
}
void remove_edge(int x,int y)
{
struct node*tmp,*ptr;
tmp=a[x];
while(tmp->next->value!=y&&tmp->next!=NULL)
tmp=tmp->next;
if(tmp->next==NULL)
return;
ptr=tmp->next;
tmp->next=ptr->next;
free (ptr);
}
void remove_vertex(int x)
{
int i;
struct node*tmp,*ptr;
//finding index of the vertex in array of head pointers to list
for(i=0;i<n;i++)
{
if(a[i]->value==x){
index=i;
break;
}
}
tmp=a[index];
//removing the respective list
while(tmp)
{
ptr=tmp->next;
free(tmp);
tmp=ptr;
}
//removing that node's edges
for(i=0;i<n;i++)
{
if(i!=index)
{
tmp=a[i];
while(tmp->next)
{
if(tmp->next->value==index)
{
ptr=tmp->next;
tmp->next=ptr->next;
free (ptr);
break;
}
tmp=tmp->next;
}
}
}
}
int path(int x,int y)
{
int i;
DFS(x);
for(i=0;i<k;i++)
{
if(b[i]==y)
return 1;
}
return 0;
}
void DFS(int i)
{
struct node *p;
b[k]=i;
k++;
p=a[i];
visited[i]=1;
while(p!=NULL)
{
i=p->value;
if(!visited[i])
DFS(i);
p=p->next;
}
}
