//Input an array with n elements. Find all pairs of elements of array having
//equal sum of elements a,b,c,d in array.using hash table.

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node*next;
}*head[50];
int k=0;
void create(int,int);
struct node* create_list(int);
void main()
{
    int i,j,n,l,flag=0;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int a[n];
    struct node*tmp,*ptr;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(k==0)
           create(a[i],a[j]);
           else
           {
               for(l=0;l<k;l++)
               {
                   if(head[l]->val==(a[i]+a[j]))
                   {
                       tmp=head[l]->next;
                       ptr=tmp->next;
                   printf("pairs:(%d %d),(%d %d)",a[i],a[j],tmp->val,ptr->val);
                   flag=1;
                   break;
                   }
               }
               create(a[i],a[j]);
           }
           if(flag==1)
           break;
        }
        if(flag==1)
        break;
    }
    if(flag==0)
    printf("no such pairs\n");
    
}
//function to store hash value(sum of two numbers) and the pairs in one entry of hash table(through chaining)
void create(int x,int y)
{ struct node* tmp;
    head[k]=(struct node*)malloc(sizeof(struct node));
    head[k]->val=x+y;
    head[k]->next=create_list(x);
    tmp=head[k]->next;
    tmp->next=create_list(y);
    k++;
}
//function to create new node of linked list
struct node *create_list(int x)
{
    struct node*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->val=x;
    tmp->next=NULL;
    return tmp;
}
