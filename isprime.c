#include <stdio.h>
#include <math.h>

int isPrime(int a);
int main(){

    int x;
    scanf("%d",&x);
    printf("%.0f\n",sqrt(x));
    printf("%d",isPrime(x));

    return 0;
}

int isPrime(int a) {

	for (int i = 2; i <= (int)sqrt(a); i++) {
		if (a%i==0)
			return 0;
	}
	return 1;
}
