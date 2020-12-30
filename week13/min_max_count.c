#include<stdio.h>
#include<stdlib.h>

struct node
 {
  int info;
  struct node *rlink;
  struct node *llink;
 };
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert(NODE root,int item)
{
NODE temp,cur,prev;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
if(root==NULL)
 return temp;
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
cur=(item<cur->info)?cur->llink:cur->rlink;
}
if(item<prev->info)
 prev->llink=temp;
else
 prev->rlink=temp;
return root;
}
void display(NODE root,int i)
{
int j;
if(root!=NULL)
 {
  display(root->rlink,i+1);
  for(j=0;j<i;j++)
	  printf("  ");
   printf("%d\n",root->info);
	 display(root->llink,i+1);
 }
}


void max(NODE root)
 {
	 NODE temp=root;
	 while(temp->rlink!=NULL)
	 temp=temp->rlink;
	 printf("\n Max Element is : %d\n",temp->info);
 }
 void min(NODE root)
 {
	 NODE temp=root;
	 while(temp->llink!=NULL)
	 temp=temp->llink;
	 printf("\n Min Element is : %d\n",temp->info);
 }
 int count;
 void Count(NODE root)
 {
	 if(root==NULL)
	 return;
	 count++;
	 Count(root->llink);
	 Count(root->rlink);
 }
int main()
{
int item,choice;
NODE root=NULL;
for(;;)
{
printf("\n1.insert\n2.display\n3.Max\n4.Min\n5.Count\n");
printf("enter choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item\n");
		 scanf("%d",&item);
		 root=insert(root,item);
		 break;
  case 2:display(root,0);
		 break;
  case 3:max(root);
		 break;
  case 4:min(root);
	break;
  case 5:count=0;
		 Count(root);
		 printf("\nCount  : %d",count);
		 break;
  default:return 0;
	  }
	}
 }
