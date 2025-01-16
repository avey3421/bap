#include <stdio.h>
#include <math.h>

int main()
{
    int year_start,year_end;
    float pi = 3.1415;
    scanf("%d %d",&year_start,&year_end);
    //printf("%d %d\n",year_start,year_end);
    int leap,inbetween;
    inbetween = year_end-year_start-1;
    if ((year_end % 4 || (year_end%4==0 && year_end%4)) || (year_start % 4 || (year_start%4==0 && year_start%4)))
        inbetween+=3;
    leap=inbetween/4;
    if (year_start%4==0 || (year_start%4 && year_start%4==0))
        leap++;
    if (year_end%4==0 || (year_end%4 && year_end%4==0))
        leap++;
    if (inbetween>=100)
    {
        int first_major = ceil((float)year_start/100)*100, last_major = floor((float)year_end/100)*100;
        printf("%d %d\n",first_major,last_major);
        for (int i = first_major; i<=last_major;i+=100)
        {
            if (i%400)
                leap--;
        }
    }


    printf("%d",leap);


    return 0;
}
