#include <stdio.h>
#include <math.h>

int main(){


    int c,n0,n1,a,i,x;


    scanf("%d %d %d %d %d",c,n0,n1,a,i);

    x = (i+n1+n0)/a-1;
    printf("%d",x);

    if (n0+(x-1)*a-i<=n1)
    {
        printf("%d",x);
    }else
    {
        int sum = n0;
        int curr_pages = n0;
        x = 1;
        while (curr_pages < n1){
            curr_pages+=a;
            sum+=curr_pages;
            x++;
        }
        x += c/n1-x/2;
        printf("%d",x);
    }



    return 0;

}
