#include <stdio.h>
#include "prime.h"
#include "atomic.h"

int main()
{
    int n;
    scanf("%d",&n);
    if (n<1)
    {
        printf("Wrong Input");
        return 1;
    }
    if (prime(n) && atomic(n))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
