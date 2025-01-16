#include <stdio.h>

int main()
{
    long long x;
    int min,max,curr;

    scanf("%lli",&x);
    if (x<=0){
        printf("Wrong Input");
        return 0;
    }
    min = x%10;
    max = x%10;
    x/=10;
    while (x){
        curr = x%10;
        if (curr > max)
            max = curr;
        else if (curr < min)
            min = curr;
        x/=10;
    }
    printf("%d %d",min,max);

}
