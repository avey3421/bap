#include <stdio.h>
#include "min.h"

int atomic(int a)
{
    int i,k,t,m;
    m=a-min(a);
    if (m<1)
    {
        m=1;
    }
    for (i=m;i<a;i++)
    {
        t=i;
        k=t;
        while (t>0)
        {
            k+=t%10;
            t=t/10;
        }
        if (k==a)
        {
            return 0;
        }
    }
    return 1;
}
