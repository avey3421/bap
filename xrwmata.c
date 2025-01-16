#include <stdio.h>

int main()
{

    int x,cost,needed9,needed3,lt1;
    float lt,spare;
    scanf("%d",&x);

    lt = ((float)x)/12;


    if (lt>9)
    {
        lt1 = lt*100+0.5;
        needed9 =lt1/9;
        lt1%=9;
        needed3 = lt/3;
        if (lt1%3)
            needed3++
    } else if (lt>3 && lt<9)
    {
        needed9 = 1;
        needed3 = 0;
    } else
    {
        needed9 = 0
        needed3 = 0;
    }
    cost = needed9*31 + needed3*16;
    spare = x - needed9*31 - needed3*16;


    printf("You need %d of paint",lt;
    printf("You should buy %d*9lt and %d*3lt for %d euro\n",needed9,needed3,cost);
    printf("You will have %dlt of spare paint",spare);


    return 0;
}
