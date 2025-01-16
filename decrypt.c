#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
char *decryptString(char s[]);
int main()
{
char s[30];
char *s2;
scanf ("%s",s);
s2 = decryptString(s);
printf("%s\n",s2);
printf ("Total Allocated size is %ld bytes\n",malloc_usable_size(s2));
return 0;
}

char *decryptString(char s[]){
    char *decrypted = malloc(0);
    int len = strlen(s);
    int j = 0;
    int sum = 0,d = 0;
    for (int i = 0; i<len/2; i++){
        sum+=(int)s[d]-48;
        realloc(decrypted,sum*sizeof(char));
        for (int k = 1;k<=(int)s[d]-48;k++){
            decrypted[j]=s[d+1];
            j++;
        }
        d+=2;
    }
    realloc(decrypted,(sum+1)*sizeof(char));
    decrypted[j]='\0';
    return decrypted;
}
