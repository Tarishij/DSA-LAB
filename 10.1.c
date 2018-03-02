//write a program to find whether a graph has a cycle or not

#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
 struct node*adj[10];
int visited[10]={0},top=-1,sd=0,s[10];
int DFS(int);
void create(int);
int instack(int);
void push(int);
void pop();
int empty();
void main()
{
   
    int i,n,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    adj[i]=NULL;
    create(n);
    for(i=0;i<n;i++)
    if(visited[i]!=1)
   flag= DFS(i);
    if(flag==1)
    printf("cycle is present\n");
    else
    printf("no cycle in graph\n");
}
//values of nodes in graph are starting from 0
void create(int n)
{
    int n1,j,i,val;
    struct node*last,*tmp;
    for(i=0;i<n;i++){
    last=NULL;
    printf("enter no.of elements in list\n");
    scanf("%d",&n1);
    for(j=1;j<=n1;j++)
    {
        printf("enter value\n");
        scanf("%d",&val);
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->v=val;
        tmp->next=NULL;
        if(adj[i]==NULL)
        adj[i]=tmp;
        else
        last->next=tmp;
        last=tmp;
    }}
}
int DFS(int i)
{
    struct node *p;
   push(i);
    p=adj[i];
    visited[i]=1;
    p=p->next;
    while(p!=NULL)
    {
       i=p->v;
       
       if(!visited[i])
       {
            DFS(i);
       }
       else
       {
           if(instack(i))
           {
               sd=1;
               return 1;
           }
       }
     if(sd!=1)
        p=p->next;
    }
    if(sd==1)
    return 1;
    pop();
    if(empty())
    return 0;
    
}
void push(int i)
{
    top=top+1;
    s[top]=i;
}
void pop()
{
    int r;
    r=s[top];
    top--;
}
int empty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
int instack(int i)
{
    int r;
    for(r=0;r<=top;r++)
    {
        if(s[r]==i)
        return 1;
    }
    return 0;
}
