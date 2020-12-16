#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  return NULL;
 }
 return x;
}

void freenode(NODE x)
{
free(x);
}

NODE insert_rear(NODE head,int item)
{
NODE temp,cur;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
cur=head->llink;
temp->llink=cur;
cur->rlink=temp;
head->llink=temp;
temp->rlink=head;
head->info=head->info+1;
return head;
}
NODE insert_leftpos(int item,NODE head)
{
NODE temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->llink;
 printf("enter element to be inserted ");
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}

void display(NODE head)
{
NODE temp;
if(head->rlink==head)
{
printf("list empty\n");
return;
}
printf("\nList : \n");
for(temp=head->rlink;temp!=head;temp=temp->rlink)
printf("%d\n",temp->info);
}

NODE dinsert_front(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->rlink;
head->rlink=temp;
temp->llink=head;
temp->rlink=cur;
cur->llink=temp;
return head;
}

NODE ddelete_front(NODE head)
{
NODE cur,next;
if(head->rlink==head)
{
printf("dq empty\n");
return head;
}
cur=head->rlink;
next=cur->rlink;
head->rlink=next;
next->llink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}

NODE ddelete_rear(NODE head)
{
NODE cur,prev;
if(head->rlink==head)
{
printf("dq empty\n");
return head;
}
cur=head->llink;
prev=cur->llink;
head->llink=prev;
prev->rlink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}

NODE delete_all_keys(NODE head,int key)
{
	int count =0;
	if(head->rlink==head)
	{
		printf("List empty \n");
		return head;
	}
	NODE cur = head->rlink;
	NODE prev;
	NODE next;
	while(cur!=head)
	{
		if(cur->info==key)
		{
			if(count!=0)
			{
			prev=cur->llink;
			next=cur->rlink;
			prev->rlink=next;
			next->llink=prev;
			freenode(cur);
			count++;
			cur=next;
			}
			else
			{
				count++;
				cur=cur->rlink;
			}
		}
		else
		cur=cur->rlink;
	}
	if(count==0)
	{
		printf("Element not found\n");
		return head;
	}
	if(count==1)
	{
		printf("\nno duplicates\n");
	}
	printf("Element deleted in %d positions",(count-1));
	return head;
}

void search(NODE head,int item)
{
	NODE cur;
	if(head->rlink==head)
	{
		printf("List empty\n");
		return;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(cur->info==item)
		{
			printf("Element found\n");
			return;
		}
		cur = cur->rlink;
	}
	printf("Element not found \n");
	return ;
}
	
	
int main()
{
int item,choice;
NODE head;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;)
{
printf("\n1.insert rear\n2.insert front\n3.delete rear\n4.delete front\n5.insert left\n6.display\n7.Delete duplicates\n8.Search\n9.Exit\nEnter choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item\n");
		 scanf("%d",&item);
		 head=insert_rear(head,item);
		 break;
  case 2:printf("enter the item at front end\n");
		 scanf("%d",&item);
		 head=dinsert_front(item,head);
		 break;
  case 3:head=ddelete_rear(head);
		 break;
  case 4:head=ddelete_front(head);
		 break;
  case 5:printf("enter the key item\n");
		 scanf("%d",&item);
		 head=insert_leftpos(item,head);
		 break;
  case 6:display(head);
		 break;
  case 7:printf("Enter item \n");
		 scanf("%d",&item);
		 head = delete_all_keys(head,item);
		 break;
  case 8:printf("Enter item \n");
		 scanf("%d",&item);
		 search(head,item);
		 break;
  default:exit(0);
		  break;
  }
 }
}
