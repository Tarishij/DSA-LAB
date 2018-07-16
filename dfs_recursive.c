#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
 struct node*adj[10];
int visited[10]={0};
void DFS(int);
void create(int);
void main()
{
   
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    adj[i]=NULL;
    create(n);
    for(i=0;i<n;i++)
    if(visited[i]!=1)
    DFS(adj[i]->v);
    
}
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
void DFS(int i)
{
    struct node *p;
   
    printf("%d",i);
    p=adj[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->v;
       
       if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
