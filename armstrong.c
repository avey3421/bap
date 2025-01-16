#include <stdio.h>
#include <math.h>
int main()
{

    long x,sum=0,temp,plithos=0;

    scanf("%li",&x);

    if (x<=0)
        printf("Wrong Input");
    else
    {
        temp = x;
        while (temp!=0)
        {
            plithos++;
            temp/=10;
        }
        temp=x;
        while (temp!=0)
        {
            //     printf("%d %d\n",temp,temp%10);
            sum+=pow((temp%10),plithos);
            temp/=10;

        }
        //   printf("%d",sum);
        if (sum==x)
            printf("yes");
        else
            printf("no");
    }


    return 0;
}
