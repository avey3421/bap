#include <stdio.h>

int main()
{
	int resta,duo=0,one=0,half=0,eikosi=0,deka=0,pente=0,OneCent=0,n,i;
	float money;
	int money1[7]= {0,0,0,0,0,0,0},ValueOfMoney[7]= {200,100,50,20,10,5};

	scanf("%d%f",&n,&money);

	if (0.75*n<=money && n>=1 && n<=5)
	{
		resta = (money-0.75*n)*100 + 0.5;
		for (i=1; i<=7; i++)
		{
			money1[i]=resta/ValueOfMoney[i];
			if (money1[i])
			{
				if (i<=2)
				{
					printf("%d * %d euros\n",money1[i],ValueOfMoney[i]);
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