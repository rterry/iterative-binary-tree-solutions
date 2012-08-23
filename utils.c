#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "treeheader.h"

int yesno(char *prompt)
{
	char answer;
	for(;;)
	{
		printf(prompt);
		fflush(stdin);
		scanf("%c", &answer);
		getchar();

		answer = toupper(answer);

		if(answer == 'Y')
			return 1;
		if(answer == 'N')
			return 0;
		else
			printf("Error. You have to answer Y/N.\n");
	}
}

void read_int(char *prompt, int *choice)
{
	printf(prompt);
	fflush(stdin);
	scanf("%d", choice);
	getchar();
}

void enter(char *prompt)
{
	fputs(prompt, stdout);
	fflush(stdin);
	getchar();
}
