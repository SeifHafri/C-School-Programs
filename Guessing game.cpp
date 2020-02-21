#include<stdio.h>

int main()
{
	guess(7);
}
void guess(int i)
{
	int i,luck=0;
	while (luck==0)
	printf("guess niggaa !!/n");
	scanf("%d",&i);
	if (i>guess)
	{
		luck=0;
		printf("a lil too high/n ");
		
	}
	else if(i<guess)
	{
		luck=0;
		printf("q lil too low /n");
		
	}
	else
	{
	luck=1;
	printf("u got it nigg/n");
}
}

