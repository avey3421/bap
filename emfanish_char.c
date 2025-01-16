#include <stdio.h>

int main()
{

    int n;
    char x;

    scanf("%d %c",&n,&x);

    if (n<=0 || x<97 || x>122)
      printf("Wrong Input");
    else
    {
        for (int i=1;i<=n;i++)
        {
            printf("%c",x);
            if(i%5==0 && i!=n)
                printf(" ");
            if (i%100==0)
                printf("\n");
        }
        printf(".");
    }

    return 0;
}
