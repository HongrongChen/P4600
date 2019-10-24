#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float det_amp(int argc, char** argv)
{
	FILE* inputfile;
	FILE* input_file;
	input_file = fopen(argv[1],"r");
	float a;
	int counter;


	int i = 0;
	while(fscanf(input_file,"%f\n",&a) != EOF)
	{
		counter++;
	}
	rewind(input_file);
	float x[counter];
	float amp[counter];
	float max_amp = 0;
	i = 0;
	for(i = 0; i < counter ; i++)
	{
		fscanf(input_file,"%f %f\n", &x[i],&amp[i]);
		if( amp[i] > amp[i-1] )
		{
			max_amp = amp[i];
		}
	}
	
	fclose(input_file);
	inputfile = fopen(argv[1],"r");
	printf("\nMaxim	um Amplitude is %.3f",max_amp);
	

}

void main()
{
	det_amp(noisy_sin);
}
