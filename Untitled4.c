#include <stdio.h>

int min(int a)
{
    int d,m;
    while (a/10>0)
    {
        d++;
        a=a/10;
    }
    d++;
    m=9*d;
    return m;
}
