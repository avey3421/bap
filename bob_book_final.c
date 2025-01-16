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
    //printf("%d %d'th day\n",sum,days);
    while (curr_speed <= n1 && sum<c){
        curr_speed += a;
        sum+=curr_speed-i;
        days++;
        //printf("%d %d'th day\n",sum,days);
    }
    if (sum<c){
       sum = sum - curr_speed + i;
       days--;    // undo the last wrong addition since speed was > n1  (therefore decrease days by 1 too)
       //printf("%d corrected at %dth day\n",sum,days);
    }
    while (sum<c){
        sum += n1-i;
        days++;
        //printf("%d %d'th day\n",sum,days);
       }
    printf("%d",days);
    return 0;
}
