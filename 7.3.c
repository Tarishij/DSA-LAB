////non recursive preorder traversal of tree

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node  *left,*right;
};
struct stack
{
    struct node *t;
    struct stack *next;
};
struct stack *top;
void create();
struct node* newnode(int);
struct node* pop();
void push(struct node*);
void preorder(struct node *);
int isempty();
void main()
{
    struct node *root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(17);
    root->left->right=newnode(9);
    root->left->right->left=newnode(7);
    root->right->left=newnode(12);
    root->right->left->left=newnode(11);
    root->right->right=newnode(19);
    root->right->right->left=newnode(18);
    create();
    preorder(root);
}
void create()
{
    top = NULL;
}
struct node* newnode(int value)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}
void preorder(struct node *root)
{
   struct node *curr=root;
  while(1)
  {
      while(curr!=NULL)
      {
          printf("%d ",curr->data);
          push(curr);
          curr=curr->left;
      }
    if(isempty())
    return;
        curr=pop();
        curr=curr->right;
    
    
  }
}
void push(struct node *n)
{
    if(top==NULL)
    {   top=(struct stack*)malloc(sizeof(struct stack));
        top->t=n;
        top->next=NULL;
        
    }
    else
    {
    struct stack *tmp;
    tmp=(struct stack*)malloc(sizeof(struct stack));
    tmp->t=n;
    tmp->next=top;
    top=tmp;
    }
}
struct node* pop()
{
    if(top!=NULL)
    {
        struct stack *tmp;
        tmp=top;
        top=tmp->next;
        return (tmp->t);
    }
}
int isempty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}
