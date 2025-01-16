#include <stdio.h>
#include <math.h>

int main()
{

    int x,y,z,max1,x1=0,x2=0,x3=0;
    scanf("%d %d %d",&x,&y,&z);
    if (x>abs(y-z)&&x<y+z)
       x1=1;
    if (y>abs(x-z)&&y<x+z)
        x2=1;
    if (z>abs(x-y)&&z<x+y)
        x3=1;

    if (x1&&x2&&x3)
    {
        max1 = x;
        if (y>max1)
           max1 = y;
        if (z>max1)
           max1 = z;
        if (x*x+y*y+z*z==2*(max1*max1))
            printf("Right Triangle");
        else if (x*x+y*y+z*z > 2*(max1*max1))
          printf("oksygonio");
        else
          printf("Amblygonio");
    } else
     printf("Not A Triangle");

    return 0;
}
