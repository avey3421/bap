#include <stdio.h>

void printrow(int a,int b,int c,int c_1);


int main(){

    int side,thickness;

    scanf("%d %d",&side,&thickness);

    if (side<2 || side>13 || thickness<1 || 2*thickness > side){
        printf("Wrong Input");
        return 0;
    }
    //printf("%d\n",side/thickness);
    printrow(side,thickness,42,1);
    for (int i = 1; i<=side-2*thickness;i++){
            printrow(thickness,1,42,0);
            printrow(side-2*thickness,1,32,0);
            printrow(thickness,1,42,0);
            printf("\n");
    }
    printrow(side,thickness,42,1);

    return 0;
}

void printrow(int side,int times,int output,int changeline){

    for (int i = 1; i<=times; i++)
    {
        for (int j = 1; j<=side; j++)
            printf("%c",output);
        if (changeline)
            printf("\n");
    }
}
