#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void noisy_sin(int a) 
{
	FILE* output_file;
	output_file = fopen("noisy_sin.txt","w");
	srand(time(NULL));
	int i = 0;
	float sin_wave[a];
	for(i = 0;i<a;i++)
	{
		sin_wave[i] = sin(i*M_PI/180);
	}
	
	i = 0;
	float r1;
	float r2;
	float noise;
	float noisy_sin[a];
	for(i = 0;i<a;i++)
	{
		r1 = (float)rand()/RAND_MAX;
		r2 = (float)rand()/RAND_MAX;
		noise = (float)(r1-r2)/10;
		noisy_sin[i] = sin_wave[i] + noise;
		fprintf(output_file,"%.3f\n",noisy_sin[i]);
	}
	fclose(output_file);
}

void moving_average(float* data, int len)
{
	FILE* output_file;
	output_file = fopen("smoothed_data.txt","w");
	int i = 0;

	int j = 0;
	float amp[len];
	for(i = 0; i < len ; i++)
	{
		data[i] = amp[i];
	}

	for (i = 0 ; i < len ; i++)
	{
		j = 0;
		for(j = 0 ; j < 5 ; j++)
		{
			if(i+j<len)
			{
				amp[i] = (amp[i+j])/5;
			}
			else
				amp[i] = 0;
		}
		fprintf(output_file,"%.3f\n",amp[i]);

	}
	fclose(output_file);
}


float find_amp(float* data, int len)
{
	float amp[len];
	float max_amp = 0;
	int i = 0;
	for(i = 0; i < len ; i++)
	{
		data[i] = amp[i];
		if( amp[i] > amp[i-1] )
		{
			max_amp = amp[i];
		}
	}
	return max_amp;
}



void main()
{
	noisy_sin(500);
	FILE* inputfile;
	FILE* input_file;
	input_file = fopen("noisy_sin.txt","r");

	float data[500];
	int i = 0;
	for(i = 0; i < 500 ; i++)
	{
		fscanf(input_file,"%f\n",&data[i]);
		printf("%f\n",&data[i]);
	}
	printf("%f\n",&data);
	float max_amp = find_amp(data,500);
	moving_average(data,500);
	printf("%f",max_amp);

	fclose(input_file);



}

