#include <stdio.h>

int main()
{
    int n,goal=1,low=1,high=-1;

    scanf("%d",&n);

    if (n<=0 || n>=11)
        printf("Wrong Input");
    else
    {

        for (int i=1;i<n;i++)
            goal+=2;
        //printf("%d\n",goal);
        low = goal/2+1;
        high = goal/2-1;
        for (int i = 1;i<=n;i++)
        {
            low -= 1;
            high += 1;
            for (int j=1;j<=low;j++)
                printf(" ");
            for (int j=low;j<=high;j++)
                printf("*");
            printf("\n");
        }
    }


    return 0;
}
