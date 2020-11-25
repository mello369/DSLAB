#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(NODE));
	if(x==NULL)
	{
		printf("memory full \n");
		exit(0);
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert(NODE first,int item)
{
	NODE temp=getnode(),cur,prev;
	temp->info=item;
	if(first==NULL)
	{
		first=getnode();
		first->info=item;
		return first;
	}
	if(item<first->info)
	{
		temp->link=first;
		return temp;
	}
	cur=first;
	prev=NULL;
	while(cur!=NULL&&item>cur->info)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=temp;
	temp->link=cur;
	return first;
}

void display(NODE first)
{
	if(first==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Elements of the list are : \n");
	for(NODE i=first;i!=NULL;i=i->link)
	printf("%d\n",i->info);
}

int main()
{
	int item,ch;
	NODE first=NULL;
	for(;;)
	{
		printf("\n1.Insert\n2.display\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				first = insert(first,item);
				break;
			
			case 2:
				display(first);
				break;
			default:return 0;
		}
	}
}
