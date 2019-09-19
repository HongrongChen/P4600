#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*
int main()
{
	char letter = '\n';

	char* words = "Hello World" ;
	char* cursor = words;
	int x =5;
	float = 3.1415;
	char a ='a';

	while(*cursor != '\0')
	{
		printf("%c\n", *cursor);
		printf(words);
		printf("This is a int = %d float %0.2f char = %c\n",x,y,a);
		printf("Copy of string %s",string);
		//Format specifiers
		cursor++;
	}

}	
*/
int main()
{
	char input[64];
	int x = 5;
	float y = 3.1415;
	char a = 'a';
	float inputx;
	char* string = "This is a int = %d float %0.2f char = %c\n";
	printf(string,x,y,a);
	printf("Please enter a number:");
	int correct = scanf("%f",&inputx);
	fflush(stdin);


	if (correct == 1)
	{
		printf("\nScanf returned %d",correct);
		printf("\ninput was %f",inputx);
		return 0;
	}


	do
	{
		printf("\nScanf returned %d",correct);
		printf("\ninput was %f",inputx);
		printf("\nEnter again:");
		fflush(stdin);
		scanf("\n%f",&inputx);
		correct = scanf("%f",&inputx);
	}
	while (correct != 1);


/*	if (correct == 0)
	{
		printf("\nScanf returned %d",correct);
		printf("\ninput was %f",inputx);
		printf("\nEnter again:");
		scanf("\n%f",&inputx);
	}
*/


	
}