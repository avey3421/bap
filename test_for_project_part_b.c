/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct hand{
    char arr[26+13];
};
void saveData(struct hand hand[],int n);
char *readString();
int readFromInput(struct hand hand[]);
int *fill_Index(char arr[]);
int readFromFile(struct hand hand[]);


int main()
{
    struct hand hand[10];
    printf("from which file to read?\n");
    int n = readFromFile(hand);
    //int n = readFromInput(hand);
    for (int i = 0; i<n;i++)
       printf("%d %s\n",i,hand[i].arr);
    printf("to what file to save?\n");
    saveData(hand,n);
    return 0;
}

void saveData(struct hand hand[],int n) {
    char cards[4][11] = {"SPADES:   \0","HEARTS:   \0","DIAMONDS: \0","CLUBS:    \0"};
    char *s = readString();
    FILE *file = fopen(s,"w");
    free(s);
    if (file != NULL) {
        for (int k = 0; k < n; k++) {
            int *index = fill_Index(hand[k].arr);
            for (int m = 0; m < 4; m++) {
                fprintf(file,"%s",cards[m]);
                for (int i = index[m]; index[m]!=-1 && hand[k].arr[i+1]==hand[k].arr[index[m]+1] && i<26+13; i+=3){  // != -1 so it isnt empty
                    fprintf(file,"%c ",hand[k].arr[i]);
                }
                fprintf(file,"\n");
            }
            free(index);
        }
    }
}

char *readString() {
    char *s = malloc(0);
    int count = 0;
    char input;
    scanf(" %c",&input);
    while (input != '\n'){    // scan the name of the file
        count++;
        char *test = realloc(s,count*sizeof(char)); // why is this error popping up here but when i do free test it does not run ?
        if (test != NULL) {
            s=test;
        }
        s[count-1]=input;
        //free(test); //  it is the same block of memory as s, so no point in freeing it
        scanf("%c",&input);
    }
    s[count] = '\0';
    //printf("%s",s);
    return s;
}

int readFromInput(struct hand hand[]) {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf(" ");
        fgets(hand[i].arr,26+13,stdin);
        hand[i].arr[strcspn(hand[i].arr,"\n\r")] = '\0';
    }
    return n;
}

int *fill_Index(char arr[]) {
    int i = 1;
    int *index = malloc(4*sizeof(int));
    for (int m = 0; m<4; m++) {
        index[m] = -1;
    }
    while(i<26+13 ) {
        int temp_index;
        if (arr[i] == 'S')
            temp_index=0;
        else if (arr[i] == 'H')
            temp_index=1;
        else if (arr[i] == 'D')
            temp_index=2;
        else if (arr[i] == 'C')
            temp_index=3;
        index[temp_index]=i-1;
        char temp = arr[i];
        do {
            i+=3;
        }while (i<26+13 && arr[i]==temp);
    }
    return index;
}

int readFromFile(struct hand hand[]) {
    char *s = readString();
    FILE *file = fopen(s,"r");
    free(s);
    if (file != NULL) {
        int n;
        fscanf(file,"%d",&n);
        for (int k = 0; k < n; k++) {
           fscanf(file," ");
           fgets(hand[k].arr,26+13,file);
           hand[k].arr[26+12]='\0'; // add the end of string manually
        }
        fclose(file);
        return n;
    }
        printf("couldn't open file\n");
    return 0;
}
