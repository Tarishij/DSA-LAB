
#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
 struct node*adj[20];
int visited[20]={0};
void create(int);
void BFS(int);
int empty();
void enqueue(int);
int dequeue();
int a[20],front=-1,rear=-1;
void main()
{
   
    int i,n,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    adj[i]=NULL;
    create(n);
   printf("enter value with which you want to start bfs\n");
   scanf("%d",&s);
     BFS(s);
     for(i=0;i<n;i++)
     if(visited[i]==0)
     BFS(i);
}
void create(int n)
{
    int n1,j,i,val;
    struct node*last,*tmp;
    for(i=0;i<n;i++){
    last=NULL;
    printf("enter no.of elements in %d list\n",i+1);
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
void BFS(int i)
{
    struct node *p;
    int va;
    visited[i]=1;
    enqueue(i);
    while(!empty())
    {
        va=dequeue();
        p=adj[va];
        printf("%d",va);
        while(p->next!=NULL)
        {   p=p->next;
            if(visited[p->v]!=1){
            enqueue(p->v);
            visited[p->v]=1;}
        }
    }
}
void enqueue(int v)
{
    if(rear==-1)
    front=0;
    rear=rear+1;
    a[rear]=v;
}
int dequeue()
{ 
    int r;
    r=a[front];
    if(front==rear)
    front=rear=-1;
    else
    front++;
    return r;
}
int empty()
{
    if(rear==-1&&front==-1)
    return 1;
    else 
    return 0;
}
