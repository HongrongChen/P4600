#include <stdio.h>
#include <stdlib.h>
#include<math.h>


float moving_average(int argc, char** argv)
{
	FILE* inputfile;
	FILE* input_file;
	input_file = fopen(argv[1],"r");
	float a;
	float b;
	int counter;


	int i = 0;
	float M = 0.5;
	while(fscanf(input_file,"%f %f\n",&a,&b) != EOF)
	{
		counter++;
	}
	rewind(input_file);
	float x[counter];
	float amp[counter];
	i = 0;
	for(i = 0; i < counter ; i++)
	{
		fscanf(input_file,"%f %f\n", &x[i],&amp[i]);
	}
	fclose(input_file);
	i = 0;
	int j = 0;
	for(i=0;i<counter;i++)
	{
		j = 0;
		for(j=0;j<5;j++)
		{
			if(i+j<counter)
			{
				amp[i] += M*(amp[i+j]);
			}
			if(i+j>counter)
			{
				amp[i] = 0;
			}
		}
		
	}

	




inputfile = fopen(argv[1],"r");
}