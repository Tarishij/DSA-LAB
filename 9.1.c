//write a program to find distance between two nodes in a tree 
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right,*par; 
}*root;
int a1[50]={0},a2[50]={0};
void inorder(struct node*);
struct node *insert(struct node*,int,struct node*);
struct node*create(int,struct node*);
struct node* search(struct node*,int );
int create_arr(struct node*,int[]);
int count=0;
void main()
{
    int value,n,i,a,b,size1,size2,j,flag=0,common_ancestor;
    struct node *r1,*r2,*common;
            printf("enter no.ofnodes\n");
            scanf("%d",&n);
            printf("enter values\n");
            for(i=0;i<n;i++){
            scanf("%d",&value);
            root=insert(root,value,NULL);}
            printf("inorder:\n");
            inorder(root);
            printf("enter values of 2 nodes\n");
            scanf("%d %d",&a,&b);
            if(a==root->data||b==root->data)
            printf("no node\n");
            else{
            r1=search(root,a);
           size1=create_arr(r1,a1);
           r2=search(root,b);
           size2=create_arr(r2,a2);
         
            if(size1<size2)
            {
             for(i=0;i<size1;i++)
             {
             for(j=0;j<size2;j++)
             {
              if(a1[i]==a2[j]){
              common_ancestor=a1[i];
              flag=1;
              break;
              }
              }
              if(flag==1)
              break;
              }
            }
            else
            {
            for(i=0;i<size2;i++)
             {
             for(j=0;j<size1;j++)
             {
              if(a2[i]==a1[j]){
              common_ancestor=a2[i];
              flag=1;
              break;
              }
              }
              if(flag==1)
              break;
              }
              }
              }
         
           common=search(root,common_ancestor);
          count=0;
           search(common,a);
          
          printf("%d",count);
          search(common,b);
         
           printf("%d",count);
}
struct node *insert(struct node* root,int v,struct node*parent)
{
    if(root==NULL)
    return create(v,parent);
    if(v>root->data)
    root->right=insert(root->right,v,root);
    else if(v<root->data)
    root->left=insert(root->left,v,root);
    root->par=parent;
    return root;
}
struct node*create(int value,struct node* parent)
{
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->par=parent;
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
struct node* search(struct node*root,int key)
{   
printf("%d\n",key);
    if(root->data==key)
    return root;
    if(root->data>key)
    {
    printf("my count=%d\n",count);
    count++;
    root=root->left;
    search(root,key);
    }
    else if(root->data<key)
    {
    count++;
    root=root->right;
    search(root,key);
    }
    
}

int create_arr(struct node*root,int a[])
{int i=0,size;
while(root->par)
{
a[i]=root->par->data;
i++;
root=root->par;
}
size=i;
return size;
}
