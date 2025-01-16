#include <stdio.h>
#include <math.h>

int main()
{

    for (int a = 0; a<20;a++){
        for(int b=0;b<20;b++){
            for(int c=0;c<20;c++){
                if (pow(2,a)*pow(3,b)*pow(5,c)==22500)
                    printf("%d %d %d",a,b,c);
            }
        }
    }
    return 0;
}
