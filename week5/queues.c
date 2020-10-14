#include <stdio.h>
#define Q_SIZE 3
int item,front=0,rear=-1,q[10];
void insertrear()
{
	if(rear==Q_SIZE-1)
	{
		printf("\nqueue overflow\n");
		return;
	}
	q[++rear]=item;
}

int deletefront()
{
	if(front>rear)
	{
		front =0;
		rear=-1;
		return -1;
	}
	return q[front++];
}

void displayQ()
{
	if(front>rear)
	{
		printf("\nqueue is empty\n");
		return;
	}
	printf("\ncontents of queue : \n");
	for(int i = front;i<=rear;i++)
	printf("%d\n",q[i]);
}

int main()
{
	int choice;
	for(;;)
	{
		printf("\n1.insert rear\n2.delete front\n3.display\n4.exit\n");
		printf("enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nenter the item to be inserted\n");
			scanf("%d",&item);
			insertrear();
			break;
			case 2: item=deletefront();
			if(item==-1)
			printf("\nqueue is empty\n");
			else
			printf("\nitem deleted = %d\n",item);
			break;
			case 3 : displayQ();
			break;
			default : return 0;
		}
	}
	return 0;
}			
	
