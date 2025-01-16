#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));

	char string[100]="oatuk jeffer",newstring[100];
	//fgets(string,100,stdin);
	//string[strcspn(string,"\n\r")]='\0';
	int test = strcmp(string,"quit");
	unsigned long long tries = 0;
	while (test!=0) {
        //printf("%s\n",string);
		int a = 0,i, len = strlen(string);
		for (i = 0; i<len-1; i++) {
			int j = rand()%(len);
			char temp = string[i];
			string[i]=string[j];
			string[j]=temp;
		}
		string[i+1]='\0';
		printf("scrambled: (%s)\n",string);
		//scanf(" ");
		//fgets(string,100,stdin);
		//string[strcspn(string,"\n\r")]='\0';
		test = strcmp(string,"otaku jeffer");
		strcpy(string,"aotuk jeffer");
		tries++;
		//  printf("(%s)\n",string);
		//system("pause");
	}
	printf("done!! found it in %llu th tries",tries);

}


