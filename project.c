#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct hand {
    char arr[26+13];   // 12 spaces + 1 for '\0'
};

int *num_of_cards(char arr[]) {
    int *num_of_cards=malloc(4*sizeof(int));
    for (int m = 0; m<4; m++) {
        num_of_cards[m] = 0;
    }
    int i = 1;
    while (i<26+13) {
        int index = 0;
        if (arr[i]=='S')
            index = 0;
        else if (arr[i]=='H')
            index = 1;
        else if (arr[i]=='D')
            index = 2;
        else if (arr[i]=='C')
            index = 3;
        num_of_cards[index]++;
        char temp = arr[i];
        i+=3;
        while (i<26+13 && arr[i]==temp) {
            i+=3;
            num_of_cards[index]++;
        }
    }
    return num_of_cards;
}

void fill_array(char **res,int *counts,struct hand hand) {
    int temp;
    for (int i = 0; i< 4; i++) {
        counts[i]=0;
        res[i]=malloc((26+12)*sizeof(char));
    }
    for (int m = 1; m < 26+13; m+=3) {
        if (hand.arr[m]=='S') {
            temp = 0;
        }else if (hand.arr[m]=='H') {
            temp = 1;
        } else if (hand.arr[m]=='D') {
            temp = 2;
        } else
            temp = 3;
        res[temp][counts[temp]]=hand.arr[m-1];
        counts[temp]++;
    }
    printf("done this hand:\n");
    for (int m = 0; m < 4; m++) {
        printf("%c ",res[m][counts[m]]);
    }
    printf("\n");
}

void printHand(struct hand hand) {
    char cards[4][11] = {"SPADES:   \0","HEARTS:   \0","DIAMONDS: \0","CLUBS:    \0"};
    /*char res[4][12];
    int counts[4]={0,0,0,0},temp;
    for (int m = 1; m < 26+13; m+=3) {
        if (hand.arr[m]=='S') {
            temp = 0;
        }else if (hand.arr[m]=='H') {
            temp = 1;
        } else if (hand.arr[m]=='D') {
            temp = 2;
        } else
            temp = 3;
        res[temp][counts[temp]]=hand.arr[m-1];
        counts[temp]++;
    }
    */
    printf("hi\n");
    char **res=malloc(4*sizeof(char *));
    int *counts=malloc(4*sizeof(int));
    fill_array(res,counts,hand);
    for (int m = 0; m < 4; m++) {
        printf("%s",cards[m]);
        for (int j = 0; j < counts[m]; j++) {
            printf("%c ",res[m][j]);
        }
        printf("\n");
    }
    free(counts);
    free(res);
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

bool balanced(struct hand hand) {
    int *num=num_of_cards(hand.arr);
    int num_of_exactly_2_colour=0,num_of_colours=0;
    for (int k = 0; k < 4; k++) {
        if (num[k]==0 || num[k]==1) {
            free(num);
            return false;
        }
        num_of_exactly_2_colour += num[k]==2?1:0;
        num_of_colours += num[k]>=2?1:0;
    }
    free(num);
    if (num_of_exactly_2_colour>1 || num_of_colours<4)
        return false;
    return true;
}

int hcp(struct hand hand) {
    int sum = 0;
    for (int i = 0; i < 26+13; i+=3) {
        if (hand.arr[i] == 'A')
            sum+=4;
        else if (hand.arr[i] == 'K')
            sum+=3;
        else if (hand.arr[i] == 'Q')
            sum+=2;
        else if (hand.arr[i] == 'J')
            sum+=1;
    }
    return sum;
}

int declarer(struct hand hand) {
    int *index=num_of_cards(hand.arr),sum=0;
    for (int i = 0; i<4;i++)
        sum += index[i]-4>0?index[i]-4:0;
    free(index);
    return sum;
}

void response (struct hand hand) {
    int hcp_points = hcp(hand),declarer_points = declarer(hand);
    if (hcp_points + declarer_points <13) {
        printf("PASS\n");
        return;
    }  // check easy possibilities first
    if (hcp_points >= 22) {
        printf("2 CLUBS\n"); // has higher priority
        return;
    }
    if (balanced(hand)) {
        if (hcp_points >= 15 && hcp_points <= 17) {   // 2nd highest priority
            printf("1NT\n");
            return;
        }
        if (hcp_points >= 20){
            printf("2NT\n");
            return;
        }
    }
    if (hcp_points + declarer_points >= 13) {   // chaos
        int *num = num_of_cards(hand.arr);
        if (num == NULL) {
            printf("error");
            return;
        }
        if (num[0] >= 5 && num[1]<=5)
            printf("1 SPADES\n");
        else if (num[1]>=5 && num[0]<=5)
            printf("1 HEARTS\n");
        else if (num[2]>=4 && num[3]<5 && num[0]<5 && num[1]<5)
            printf("1 DIAMONDS\n");
        else if (num[0]<5 && num[1]<5 && num[2]<4)
            printf("1 CLUBS\n");
        free(num);
    }
}

char *readString() {
    char *s = malloc(0);
    int count = 0;
    char input;
    scanf(" %c",&input);
    while (input != '\n'){
        count++;
        char *test = realloc(s,count*sizeof(char));
        if (test != NULL) {
            s=test;
        }
        s[count-1]=input;
        scanf("%c",&input);
    }
    //realloc(s,(count+1)*sizeof(char));
    s[count] = '\0';
    printf("len of string is: %ld\n",strlen(s));
    return s;
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

void saveData(struct hand hand[],int n) {
    char cards[4][11] = {"SPADES:   \0","HEARTS:   \0","DIAMONDS: \0","CLUBS:    \0"};
    char *s = readString();
    FILE *file = fopen(s,"w");
    free(s);
    if (file != NULL) {
        for (int k = 0; k < n; k++) {
            /*char res[4][12];
            int counts[4]={0,0,0,0},temp;
            for (int m = 1; m < 26+13; m+=3) {
                if (hand[k].arr[m]=='S') {
                    temp = 0;
                }else if (hand[k].arr[m]=='H') {
                    temp = 1;
                } else if (hand[k].arr[m]=='D') {
                    temp = 2;
                } else
                    temp = 3;
                res[temp][counts[temp]]=hand[k].arr[m-1];
                counts[temp]++;
            }
            */
            char **res=malloc(4*sizeof(char *));
            int *counts=malloc(4*sizeof(int));
            for (int i = 0; i<4;i++)
                res[i]=malloc((26+13)*sizeof(char));
            for (int m = 0; m < 4; m++) {
                fprintf(file,"%s",cards[m]);
                for (int j = 0; j < counts[m]; j++) {
                    fprintf(file,"%c ",res[m][j]);
                }
                fprintf(file,"\n");
            }
            free(res);
            free(counts);
            fprintf(file,"\n");
            }
        fclose(file);
    }else
        printf("failed\n");
    //printf("done\n");
}






int main(void) {
    struct hand hand[10];
    printf("from which file to read?\n");
    int n = readFromFile(hand);
    printf("%d\n",n);
    //int n = readFromInput(hand);
    for (int i = 0; i<n;i++)
        printHand(hand[i]);
    printf("to what file to save?\n");
    saveData(hand,n);
    return 0;
}

