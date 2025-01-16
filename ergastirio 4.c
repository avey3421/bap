#include <stdio.h>

int main()
{

    int x,count,sum,n;
    scanf("%d",&x);
    if (x<=0)
        printf("Wrong Input");
    else
    {
        if (x%10==x)
        {
            printf("0 %d",x);
            return 0;
        }
        sum=0;
        do
        {
            if (count==0)
                n=x;
            else
                n=sum;
                sum=0;
            while(n!=0)
            {
                sum+=n%10;
                n/=10;
            }
            count++;
        }
        while (sum%10!=sum);
        printf("%d %d",count,sum);
    }


    return 0;
}
