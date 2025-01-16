#include <stdio.h>
#include <math.h>

int isPrime(int a);
int isAtomic(int a);
int digits(int a);

int main()
{

    int x;
    scanf("%d",&x);
    if (x<1)
        printf("Wrong Input");
    else if (isPrime(x) && isAtomic(x)==0){
        printf("Yes");
    }else
        printf("No");

    return 0;
}

int isPrime(int a)
{
    if (a%2==0)
        return 0;
    for (int i = 3;i*i<=a;i+=2){
        if (a%i==0)
            return 0;
    }
    return 1;
}

int digits(int a)
{
    int pl=0;
    int y=a;
    while (y){
        pl++;
        y/=10;
    }
    return pl;
}

int isAtomic(int a)
{
    int curr;
    int sum,y,flag=0;
    y= digits(a);
    curr = a - y*9-1;
    do{
        curr++;
        sum=0;
        y=curr;
        while (y){
            sum+=y%10;
            y/=10;
        }
        if (curr+sum==a)
            flag = 1;
        //printf("%d+%d=%d\n",curr,sum,curr+sum);
    }while (curr+sum<a+y*9 && flag == 0);
    //printf("%d+%d=%d\n",curr,sum,curr+sum);
    if (flag){
        return 1;
    }
    else
        return 0;

}

