#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "find_amp.h"
#include "moving_average.h"


int main()
{
	float data[200] ;
	FILE* input_file;
	input_file = fopen("noisy_data.txt","r");
	int i = 0;
	for(i =0; i<200;i++)
	{
		fscanf(input_file,"%f\n",&data[i]);
		//printf("%.3f\n",data[i]);
	}
	fclose(input_file);
	float maxamp;

	maxamp = find_amp(data,200);
	//printf("%f\n",maxamp);

	float smoothe_data[200];
	float smoothed_curve[200];
	moving_average(data,200,1,smoothe_data);

	return 0;
	

}