#include <stdio.h>

int main()
{
    int x[100]={0};
    int i,max,n,sum=0;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    max = x[0];
    for (int i = 1; i<n;i++){
        if (x[i]>max)
          max = x[i];
    }
    for (int i = 0; i < n; i++){
        if (x[i]!=max){
            x[i]+=max-x[i];
            sum+=max-x[i];
        }
    }
    printf("%d",sum);
    return 0;
}
