#include <stdio.h>

int main()
{

    int x;

    scanf("%d",&x);

    if ((x/7500)%2)
    {
        printf("Next service in %dkm",((x/7500/2)+1)*15000-x);
    } else
    {
        printf("Next oil change in %dkm, Next service in %dkm",(x/7500+1)*7500-x,(x/15000+1)*15000-x);
    }


    return 0;
}
