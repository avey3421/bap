#include <stdio.h>

int main()
{
    int x,a,b,c,max1;

    scanf("%d",&x);
    if (x>99 && x<=999)
    {
        a=x/100;
        x%=100;
        b=x/10;
        c=x%10;
        max1=a;
        if (b>max1)
            max1=b;
        if (c>max1)
            max1=c;
        printf("%d",max1);
    }else
     printf("not a tripsifios");



    return 0;
}
