#include<stdio.h>
#define N 3
int queue[3][N];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};
int item,pr;
void pqinsert(int pr);
void pqdelete();
void display();
int main()
{
int ch;

while(1)
{
printf("PRIORITY QUEUE\n");
printf("*****************\n");
printf("\n\t1:PQinsert\n");
printf("\n\t2:PQdelete\n");
printf("\n\t3:PQdisplay\n");
printf("\n\t4:Exit\n");
printf("\nenter the choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:printf("\nenter the priority number\n");
		scanf("%d",&pr);
		if(pr>0 && pr<4)
		pqinsert(pr-1);
		else
		printf("\nonly 3 priority exists 1 2 3\n");
		break;
case 2:pqdelete();
	   break;
case 3:display();
	   break;
case 4:return 0;
}
}

}
void pqinsert(int pr)
{
 if(rear[pr]==N-1)
 printf("\n Queue overflow\n");
 else
 {
 printf("\nenter the item\n");
 scanf("%d",&item);
 rear[pr]++;
 queue[pr][rear[pr]]=item;
 }
 return;
}
void pqdelete()
{
int i;
for(i=0;i<3;i++)
{
  if(rear[i]==front[i]-1)
  printf("\nqueue empty\n");
  else
  {
  printf("deleted item is %d of queue %d\n",queue[i][front[i]],i+1);
  front[i]++;
  return;
  }
 }
}
void display()
{
int i,j;
for(i=0;i<3;i++)
{
if(rear[i]==front[i]-1)
 printf("\nqueue empty %d\n",i+1);
else
  {
  printf("\nQUEUE %d:",i+1);
  for(j=front[i];j<=rear[i];j++)
    printf("%d\t",queue[i][j]);
  }
}
  return;
}
