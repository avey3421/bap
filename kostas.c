#include <stdio.h>

int main()
{
    int x5=0,x3=0,x2=0;
    int goal=22500;

    while (goal%5==0){
        x5++;
        goal/=5;

    }
    //printf("%d\n",goal%3);
    while (goal%3==0){
        x3++;
        goal/=3;
    }
    while (goal%2==0){
        x2++;
        goal/=2;
    }
    printf("%d %d %d",x5,x3,x2);
}
