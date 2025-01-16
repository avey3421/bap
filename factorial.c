#include <stdio.h>

long fact(int k);

int power(int a, int b);


int main (){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",power(x,y));


    return 0;
}

long fact(int k)
{
    if (k==0)
        return 1;

    return k*fact(k-1);
}

int power(int a, int b)
{
    if (b==1)
        return a;
    return a*power(a,b-1);    // 2^3= 2*power(2,2) -> 2*2*power(2,1) ->  2*2*2
}


