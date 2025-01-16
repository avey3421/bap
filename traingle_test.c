#include <stdio.h>

int main()
{
    int n,goal=1,curr=1,white;

    scanf("%d",&n);

    if (n<=0 || n>=11){
        printf("Wrong Input");
        return 0;
    }
    for (int i=1;i<n;i++)
        goal+=2;
    //printf("%d\n",goal);
    white = goal/2;
    for (int i = 1;i<=n;i++)
    {
        for (int j=1;j<=white;j++)
            printf(" ");
        for (int j = 1; j<=curr; j++)
            printf("*");
        printf("\n");
        curr+=2;
        white--;
    }


    return 0;
}
