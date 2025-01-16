#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char string1[100],string2[100];
    fgets(string1,100,stdin);
    string1[strcspn(string1,"\n\r")]='\0';
    fgets(string2,100,stdin);
    string2[strcspn(string2,"\n\r")]='\0';
    strcat(string1,string2); // append string2 to string1 where we will do the process
    //printf("%s\n",string1);
    int count[256]={0},len=strlen(string1),i=0;
    for (int i = 0;i<len;i++)
        count[string1[i]]++;
    while (string1[i]!='\0'){
        //printf("%d %c\n",count[string1[i]],string1[i]);
        if (count[string1[i]]>1){
            //printf("will delete %c from %s starting from %d position\n",string1[i],string1,i);
            count[string1[i]]=0;
            char temp = string1[i];
            int i_new=i+1;
            for (int j = i+1; j<len; j++){
                if (string1[j]!=temp)
                   string1[i_new++]=string1[j];
            }
            string1[i_new]='\0';
            i--;
        }
        i++;
        //printf("%s (%c) %d\n",string1,string1[i],i);
    }
    printf("%s",string1);





}
