#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
		printf("%f %f\n",noisy_sin[i],noise);
	}


	fclose(output_file);
	
}
