#include <stdio.h>

int isPrime(int a);
int closestPrime(int a,int b);

int main()
{
    int x,y,z,check,check1;
    scanf("%d",&x);
    if (x<=2 || x%2){
        printf("Wrong Input");
        return 0;
    }
    if (x==4){
        printf("2+2=4");
        return 0;
    }
    y=3;
    z=closestPrime(x,-1);
    while (y+z!=x){
        if(z+y>x)
           z=closestPrime(z,-2);
        else if (y+z<x)
           y=closestPrime(y,2);
    }
    printf("%d+%d=%d",y,z,x);
}

int isPrime(int a) {
    if (a%2==0)
        return 0;
	for (int i = 3; i*i <= a; i+=2) {
		if (a%i==0)
			return 0;
	}
	return 1;
}

int closestPrime(int a, int b){

    int check;
    do{
        a=a+b;
        check=isPrime(a);
    }while (check == 0);
    return a;
}

