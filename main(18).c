#include <stdio.h>

int main()
{
	int resta,n,i;
	float money;
	int money1[7]={0,0,0,0,0,0,0},ValueOfMoney[7]={200,100,50,20,10,5,1};

	scanf("%d%f",&n,&money);

	if (0.75*n<=money && n>=1 && n<=5)
	{
		resta = (money-0.75*n)*100 + 0.5;
		for (i=0; i<=7; i++)
		{
			money1[i]=resta/ValueOfMoney[i];
			if (money1[i])
			{
				if (i<=1)
				{
					printf("%d * %d euros\n",money1[i],ValueOfMoney[i]/100);
				}  else
				{
					printf("%d * %d cents\n",money1[i],ValueOfMoney[i]);
				}
			}
			resta = resta % ValueOfMoney[i];
		}
	} else
	{
		printf("Wrong input");
		return 1;

	}
	return 0;
}
