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
	x=(NODE)malloc(sizeof(NODE));//
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

NODE insert_front(NODE first,int item)
{
	NODE temp = getnode();
	temp->info = item;
	temp->link = NULL;
	if(first == NULL)
	return temp;
	temp->link=first;
	return temp;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("List is empty\n");
		return first;
	}
	printf("Item deleted %d",(first->info));
	temp = first;
	temp=temp->link;
	free(first);
	return temp;
}

NODE insert_rear(NODE first,int item)
{
	NODE temp = getnode(),cur;
	temp->info=item;
	temp->link = NULL;
	if(first==NULL)
	return temp;
	cur=first;
	while(cur->link!=NULL)
	cur=cur->link;
	cur->link=temp;
	return first;
}

NODE delete_rear(NODE first)
{
	NODE cur=first,prev=NULL;
	if(first==NULL)
	{
		printf("List empty\n");
		return NULL;
	}	
	if(first->link==NULL)
	{
		printf("item deleted is %d\n",first->info);
		free(first);
		return NULL;
	}
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("Item deleted is %d\n",(cur->info));
	free(cur);
	prev->link=NULL;
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
NODE insert_pos(NODE first,int item,int pos)
{
	int c=1;
	NODE temp = getnode(),cur,prev;
	temp->info=item;
	if(pos==1)
	{
		temp->link=first;
		return temp;
	}
	cur=first;
	prev=NULL;
	while(cur!=NULL)
	{
		if(pos==c)
		{
			prev->link=temp;
			temp->link=cur;
			return first;
		}
		c++;
		prev=cur;
		cur=cur->link;
	}
	printf("Invalid position\n");
	return first;
}

NODE delete_pos(NODE first,int pos)
{
	NODE cur,prev;
	int c=1;
	if(first==NULL||pos<0)
	{
		printf("Invalid position\n");
		return NULL;
	}
	if(pos==1)
	{
		free(first);
		return NULL;
	}
	cur=first;
	prev=NULL;
	while(cur!=NULL)
	{
		if(c==pos)
		{
			printf("Element deleted is %d",cur->info);
			prev->link=cur->link;
			free(cur);
			return first;
		}
		prev=cur;
		cur=cur->link;
		c++;
	}
	printf("Element not found\n");
	return first;
}
NODE delete_key(NODE first,int key)
{
	NODE prev,cur;
	if(first==NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(key==first->info)
	{
		cur=first;
		first=first->link;
		free(cur);
		printf("Element deleted successfully\n");
		return first;
	}
	cur=first;
	prev=NULL;
	while(cur!=NULL)
	{
		if(key==cur->info)
		{
			printf("Item deleted successfully\n");
			prev->link=cur->link;
			free(cur);
			return first;
		}
		prev=cur;
		cur=cur->link;
	}
	if(cur==NULL)
	printf("Element not found \n");
	return first;
}

NODE reverse_list(NODE first)
{
	NODE cur,temp;
	cur = NULL;
	while(first!=NULL)
	{
		temp = first;
		first=first->link;
		temp->link=cur;
		cur=temp;
	}
	printf("List has been reversed successfully\n");
	return cur;
}
		
		
int main()
{
	int item,ch,pos;
	NODE first=NULL;
	for(;;)
	{
		printf("\n1.Insert front\n2.Delete front\n3.Insert rear\n4.delete rear\n5.Insert_pos\n6.Delete_pos\n7.Delete key\n8.Display\n9.Reverse\n10.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				first = insert_front(first,item);
				break;
			case 2:
				first = delete_front(first);
				break;
			case 3:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				first = insert_rear(first,item);
				break;
			case 4:
				first = delete_rear(first);
				break;
			case 5:
				printf("Enter element to be inserted\n");
				scanf("%d",&item);
				printf("Enter position\n");
				scanf("%d",&pos);
				first = insert_pos(first,item,pos);
				break;
			case 6:
				printf("Enter position\n");
				scanf("%d",&pos);
				first = delete_pos(first,pos);
				break;
			case 7:
				printf("Enter element to be deleted\n");
				scanf("%d",&item);
				first = delete_key(first,item);
				break;
			case 8:
				display(first);
				break;
			case 9:
				first=reverse_list(first);
				break;
			default:return 0;
		}
	}
}
