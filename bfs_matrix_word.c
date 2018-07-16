#include<stdio.h>
#include<stdlib.h>
struct vertex{
    char v;
    int visited;
}*vert[10];
void insert(char,int);
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
    int i,e;
    char t,f,c;
    printf("enter no. of vertices\n");
    scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("enter\n");
       scanf("%c",&c);   //for clearing input buffer
       scanf("%c",&t);
       insert(t,i);
   }
   printf("enter no of edges\n");
   scanf("%d",&e);
   printf("enter edges\n");
   for(i=0;i<e;i++)
   {
       create();
   }
   scanf("%c",&c);
   printf("enter vertex with which traversal would be started\n");
   scanf("%c",&f);
   for(i=0;i<n;i++)
   {
       if(vert[i]->v==f){
       bfs(i);
       break;}
   }
}
void insert(char t,int i)
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
    a[y][x]=1;      //skip this in case of directed graph
}
void bfs(int j)
{int t,i;
    vert[j]->visited=1;
    enqueue(j);
    while(!empty())
    {
        t=dequeue();
        printf("%c",vert[t]->v);
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
