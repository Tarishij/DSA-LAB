

#include<stdio.h>
#include<stdlib.h>
struct vertex{
    int v;
    int visited;
}*vert[10];
void insert(int,int);
void create();
int a[10][10]={0};
int front=-1,n,rear=-1;
int q[10];
int empty();
void bfs(int);
void enqueue(int);
int dequeue();
void main()
{
    int i,e,f;
    int t;
    printf("enter no. of vertices\n");
    scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("enter\n");
       scanf("%d",&t);
       insert(t,i);
   }
   printf("enter no of edges\n");
   scanf("%d",&e);
   printf("enter edges\n");
   for(i=0;i<e;i++)
   {
       create();
   }
   printf("enter vertex with which traversal would be started\n");
   scanf("%d",&f);
   bfs(f);
}
void insert(int t,int i)
{
    struct vertex *tmp;
    tmp=(struct vertex*)malloc(sizeof(struct vertex));
    tmp->v=t;
    tmp->visited=0;
    vert[i]=tmp;
}
void create()
{int x,y;
    scanf("%d %d",&x,&y);
    a[x][y]=1;
}
void bfs(int j)
{int t,i;
    vert[j]->visited=1;
    enqueue(j);
    while(!empty())
    {
        t=dequeue();
        printf("%d",t);
        for(i=0;i<n;i++)
        {
            if(a[t][i]==1)
            {
                if(vert[i]->visited==0)
                {
                    enqueue(i);
                    vert[i]->visited=1;
                }
            }
        }
    }
}
void enqueue(int v)
{
    if(rear==-1)
    front=0;
    rear=rear+1;
    q[rear]=v;
}
int dequeue()
{ 
    int r;
    r=q[front];
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
