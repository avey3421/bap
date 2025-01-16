#include <stdio.h>


int main(){

    for (int i = 1; i<128;i++){
        int sum=0,y=i;
        while(y){
            sum+=y%10;
            y/=10;
        }
        printf("%d+%d=%d\n",i,sum,i+sum);
        if (i%10==0)
            printf("\n");
    }


    return 0;



}
