#include <stdio.h>
#include <math.h>

int prime(int a)
{
    int i;
    for (i=2;i<=sqrt(a);i++)
    {
        if (a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
