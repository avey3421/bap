#include <stdio.h>
#include <stdlib.h>

int *findDivisors(int k);

int main(){
    int k;
    scanf("%d",&k);
    int *div = findDivisors(k);
    for (int i = 0; div[i]!=0;i++)
        printf("%d\n",div[i]);
    return 0;
}

int *findDivisors(int k){
    int *arr = malloc(0);
    int pl = 0;
    for (int i = 1;i<=k;i++){
        if (k%i==0){
            pl++;
            realloc(arr,pl*sizeof(int));
            arr[pl-1]=i;
        }
    }
    pl++;
    realloc(arr,pl*sizeof(int));
    arr[pl-1]=0;
    return arr;
}
