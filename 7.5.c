//Write a program to implement insertion and deletion in min heap tree.

#include <stdio.h>
int heap[30],n=0;
void insert(int);
void min_heapify(int);
int delete();
void main()
{
    int a,t,val,i,t1;
    do{
    printf("enter 1:insertion\t2:deletion\t3:display\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        printf("enter value\n");
        scanf("%d",&val);
        insert(val);
        break;
        case 2:
        t1=delete();
        printf("deleted value:%d\n",t1);
        break;
        case 3:
        printf("level order traversal\n");
        for(i=0;i<n;i++)
        printf("%d ",heap[i]);
        break;
    }
    printf("more:1\tstop:2\n");
    scanf("%d",&t);
    }while(t==1);
}
void insert(int value)
{
    heap[n]=value;
    n++;
    int i=n-1;
    int par=(i-1)/2;
    while(n-1!=0&&i>0&&heap[i]<heap[par])
    {
        heap[i]=heap[i]+heap[par];
        heap[par]=heap[i]-heap[par];
        heap[i]=heap[i]-heap[par];
        i=par;par=(i-1)/2;
    }
}
int delete()
{  
    if(n==1){
    n=0;return heap[0];}
    int t=heap[0];
    heap[0]=heap[n-1];
    n--;
    min_heapify(0);
    return t;
    
}
void min_heapify(int i)
{   
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left>=n&&right>=n)
    return 0;
    if(left<n&&heap[left]<heap[i])
    smallest=left;
    if(right<n&&heap[right]<heap[smallest])
    smallest=right;
    if(smallest!=i)
    {
        heap[i]=heap[i]+heap[smallest];
        heap[smallest]=heap[i]-heap[smallest];
        heap[i]=heap[i]-heap[smallest];
     min_heapify(smallest);
}}
