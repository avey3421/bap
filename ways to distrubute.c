#include <stdio.h>
int ways(int x,int b);

int main()
{

    int x,alt,res;
    scanf("%d %d",&x,&alt);
    res = ways(x,alt);
    //printf("%d",res);


    return 0;
}


int ways(int x,int b)
{
    if (x<1)
        return 0;
    if (x<=2)
        return x;
    printf("%d\n",x);

    return ways(x-1,b) + b*(-1) + ways(x-2,b);  // w(5) -> w(3) + w(4) -1 -> w(4) + w(3) -1 + w(4) + w(3) -1 - 1 ->  w(2)+w(3)-1-1+w(2)+w(3)-2 ->
    // 2 +w(1)+w(2)-1-2+2+w(1)+w(2)-1-2  =  2+1+2-3+2+1+2-3 =  -6
}
