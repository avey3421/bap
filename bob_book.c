#include <stdio.h>

int main()
{
    int c,n0,n1,i,a,curr_speed;
    int days=1;
    int sum=0;
    int done = 0;
    scanf("%d %d %d %d %d",&c,&n0,&n1,&a,&i);
    curr_speed=n0;
    sum = curr_speed;
    while (curr_speed < n1 && sum<c){
        curr_speed += a;
        sum+=curr_speed-i;
        days++;
    }
    if (sum<c){
       sum -= curr_speed + i;
       sum += n1-i;
       while (sum<c){
        sum += n1-i;
        days++;
       }
    }
    printf("%d",days);
    return 0;
}
