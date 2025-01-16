#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {

    srand(time(NULL));

    char string[100]="abcefg",newstring[100];
    //fgets(string,100,stdin);
    //string[strcspn(string,"\n\r")]='\0';
    int test = strcmp(string,"quit");
    unsigned long long tries = 0;
    while (test!=0){
        int len = strlen(string),a=0;
        do {
            int i = rand()%len,temp=0,a_temp=0;   // no +1 because we dont want \0
            newstring[a++]=string[i];
            for (int j = 0; j < len; j++) {
                if (i!=j)
                    string[a_temp++] = string[j];
            }
            string[--len]='\0';
        } while (len!=0);
        newstring[a]='\0';
        printf("scrambled: (%s)\n",newstring);
        //scanf(" ");
        //fgets(string,100,stdin);
        //string[strcspn(string,"\n\r")]='\0';
        strcpy(string,"abcdefg");
        test = strcmp(newstring,"abcdefg");
        tries++;
      //  printf("(%s)\n",string);
        //system("pause");
    }
    printf("done!! found it in %llu th tries",tries);

}


