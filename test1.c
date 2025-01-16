#include <stdio.h>

int main()
{

    int x,sides,shortsides;
    scanf("%d",&x);
    if (x<=0)
    {
        printf("Wrong Input");
        return 1;
    }
    sides = x/3;
    shortsides = sides;
    if (x%3){
        shortsides++;
    }
    printf("%d %d\n",sides,shortsides);
    for (int i = 1; i<=sides; i++){
        for (int j=1;j<=x;j++)
           printf("*");
        printf("\n");
    }
    for (int i = 1; i<=shortsides;i++)
    {
        for (int j=1;j<=sides;j++)
            printf("*");
        for (int j=1;j<=shortsides;j++)
            printf(" ");
        for (int j=1;j<=sides;j++)
            printf("*");
        printf("\n");
    }
    for (int i = 1; i<=sides; i++){
        for (int j=1;j<=x;j++)
           printf("*");
        printf("\n");
    }




    return 0;
}
