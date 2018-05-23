//Write a program of breadth first search for a binary search tree
//(level order traversal of tree)

#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right; 
}*root;
struct list{
    struct node* n;
    struct list *next;
}*front=NULL,*rear=NULL;
void inorder(struct node*);
struct node *insert(struct node*,int);
struct node*create(int);
void BFS(struct node*);
int empty();
void enqueue(struct node* );
struct node* dequeue();
void main()
{
    int value,n,i;
            printf("enter no.ofnodes\n");
            scanf("%d",&n);
            printf("enter values\n");
            for(i=0;i<n;i++){
            scanf("%d",&value);
            root=insert(root,value);}
            printf("inorder:\n");
            inorder(root);
            printf("\nbfs:\n");
            BFS(root);
}
struct node *insert(struct node* root,int v)
{
    if(root==NULL)
    return create(v);
    if(v>root->data)
    root->right=insert(root->right,v);
    else if(v<root->data)
    root->left=insert(root->left,v);
    return root;
}
struct node*create(int value)
{
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
void inorder(struct node*root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void BFS(struct node*root)
{
    enqueue(root);
    while(!empty())
    {
    root=dequeue();
     printf("%d ",root->data);
        if(root->left)
        enqueue(root->left);
        if(root->right)
        enqueue(root->right);
        }
}
void enqueue(struct node* v)
{
    struct list *t=(struct list*)malloc(sizeof(struct list));
    t->n=v;
    t->next =NULL;
    if(front==NULL){
    front=t;
    rear=t;}
    else{
    rear->next=t;
    rear=t;
    }
}
int empty()
{
    if(front==NULL)
    return 1;
    else
    return 0;
}
struct node* dequeue()
{   struct node*tm=front->n;
    front=front->next;
    return tm;
}
