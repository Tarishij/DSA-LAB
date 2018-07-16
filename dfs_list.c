#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
 struct node*adj[20];
int visited[20];
void create(int);
void DFS(int);
int empty();
void push(int);
int pop();
int Top();
int a[20],top=-1;
void main()
{
   
    int i,n,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    visited[i]=-1;
   //visited=-1 for unvisited,0 for waiting,1,for visited(all adjacents of that node are visited)
 for(i=0;i<n;i++)
    adj[i]=NULL;
    create(n);
   printf("enter value with which you want to start dfs\n");
   scanf("%d",&s);
     DFS(s);
     for(i=0;i<n;i++)
     if(visited[i]==-1)
     DFS(i);
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
void DFS(int i)
{
    struct node *p;
    int va;
    push(i);
    visited[i]=0;
    printf("%d",i);
    while(!empty())
    {
        va=Top();
        p=adj[va];
        while(p->next!=NULL)
        {   p=p->next;
            
            if(visited[p->v]==-1)
            {
            push(p->v);
            visited[p->v]=0;
            printf("%d",p->v);
            va=Top();
            p=adj[va];
            continue;
            }
        }
        va=pop();
        visited[va]=1;
    }
}
void push(int v)
{
    top=top+1;
    a[top]=v;
}
int pop()
{ 
    int r;
    r=a[top];
    top=top-1;
    return r;
}
int empty()
{
    if(top==-1)
    return 1;
    else 
    return 0;
}
int Top()
{
    return a[top];
}
