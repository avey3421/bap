#include <stdio.h>
#include <string.h>


int main(){

    char s[100],chars[100];
    fgets(chars,100,stdin);
    chars[strcspn(chars,"\n\r")]='\0';
    fgets(s,100,stdin);
    s[strcspn(s,"\n\r")]='\0';
    int count[256]={0},len = strlen(s);
    for (int i = 0; i<strlen(s);i++){
        count[s[i]]+= count[s[i]]<1?1:0;   // fill the positions of the count array with 1 for every char that exists there
        //but only ONCE so if it exists it has value 1
    }
    for (int i = 0; i < strlen(chars);i++){
        count[chars[i]]++;
    }
    int i = 0;
    while (s[i]!='\0'){
        //printf("%d (%c)\n",count[s[i]],s[i]);
        if (count[s[i]]==2){  // if it is 2 then it exists in the original string
            count[s[i]]==0;
            char temp = s[i];
            int temp_a=i;
            for (int j = i; s[j]!='\0';j++){
                if (s[j]!=temp){
                    s[temp_a++]=s[j];
                }else
                  i--;
            }
            s[temp_a]='\0'; // temp_a now is our new length of the array, therefore ending the string in the correct spot
            //printf("deleted %c and current  str is %s and its current len is %d\n",temp,s,strlen(s));
            }
        i++;
    }
    printf("%s",s);
}


