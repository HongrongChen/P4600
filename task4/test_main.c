#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>

float noisy_sin(int a) 
{
	FILE* output_file;
	output_file = fopen("noisy_data.txt","w");
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
		/*printf("%f %f\n",noisy_sin[i],noise);*/
	}
	fclose(output_file);
	return 0;
}


float find_amp(float* data, int len)
{
	int i = 0;
	float v;
	float max_amp = 0;
	for(i = 0; i < len ; i++)
	{
		if( data[i] > max_amp )
		{
			max_amp = data[i];
		}
	}
	return max_amp;
}



float moving_average(float* data, int len)
{
	int i = 0;
	int j = 0;
	float amp[len];
	FILE* output_file;
	output_file = fopen("smoothed_data.txt","w");

	for (i = 0 ; i < len ; i++)
	{
		printf("%f\n",i);
		j = 0;
		for(j = 0 ; j < 4 ; j++)
		{
			if(i+j<len)
			{
				amp[i] = amp[i] + (data[i+j])/5;
				//printf("%.1f,%.1f,%.1f,%.1f,%.1f\n",i,data[i],i+j,data[i+j],amp[i]);
			}
			else
			{
				amp[i] = 0;
			}
		}
		fprintf(output_file,"%f\n",amp[i]);
	}
	fclose(output_file);
	return 0;
}





void main()
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


	float smoothed_curve[200];
	moving_average(data,200);

	
	

}