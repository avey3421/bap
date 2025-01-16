#include <stdlib.h>

int *dividers(int k,int *n){
    int *arr = malloc(0);
    *n = 0;
    int pl = 0;
    for (int i = 1;i<=k;i++){
        if (k%i==0){
            pl++;
            realloc(arr,pl*sizeof(int));
            arr[pl-1]=i;
            (*n)++;
        }
    }
    return arr;
}
