#include <stdio.h>
void tower(int n,int src,int temp,int dest)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c\n",src,dest);
		return;
	}
	tower(n-1,src,dest,temp);
	printf("move disc %d from %c to %c\n",n,src,dest);
	tower(n-1,temp,src,dest);
}
int main()
{
	int n;
	printf("Enter the number of discs\n");
	scanf("%d",&n);
	tower(n,'S','T','D');
}
	
