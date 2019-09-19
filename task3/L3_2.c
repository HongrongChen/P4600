#include <stdlib.h>
#include <stdio.h>

int main()
{
	float x;
	float y;
	FILE* input_file;
	input_file = fopen("data.dat","r");

	if (input_file != NULL)
		//check before rewriting
	{
		fscanf(input_file,"%f %f",&x,&y);



		fclose(input_file);
	}

	input_file = fopen("hello.txt","w");

	fprintf(input_file,"Hello from x %f and y %f",x,y);

	fclose(input_file);


}