#include <stdio.h>

int main()
{

    int x,y,z,max1,temp,max2,max3;

    scanf("%d %d %d",&x,&y,&z);

    max1 = x;
    if (y>max1)
        max1=y;
    if (z>max1)
        max1=z;

    if (max1==x)
    {
        if(y>z)
        {
            max2=y;
            max3=z;
        } else
        {
            max2=z;
            max3=y;
        }
    } else if (max2==y)
    {
        if(x>z)
        {
            max2=x;
            max3=z;
        } else
        {
            max2=z;
            max3=x;
        }
    } else
    {
        if(x>y)
        {
            max2=x;
            max3=y;
        } else
        {
            max2=y;
            max3=x;
        }
    }
    printf("%d %d %d\n",max1,max2,max3);
    printf("Press any key to continue");




    return 0;
}
