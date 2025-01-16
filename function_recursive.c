#include <stdio.h>
unsigned long long f(int x);

int main()
{
    int x;
    scanf("%d",&x);
    if (x<0){
        printf("Wrong Input");
        return 0;
    }
    printf("%llu",f(x));

    return 0;
}

unsigned long long f(int x)
{
    if (x==0)
        return 1;
    if (x==1)
        return 2;
    return f(x-1)*f(x-1)+f(x-2)*f(x-2);

}
