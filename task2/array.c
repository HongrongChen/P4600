#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int array [] = {12,14,16,18};

	int* cursor = array;


	int i = 0;

	for (i = 0;i<4;i++)
	{

		printf("\n%d", *cursor);
		cursor ++;
	}



}