#include <stdio.h>
#include <stdlib.h>
#include<math.h>


void main()
{
	float rad =0;
	float vsin =0;
	int i = 0;
	FILE* output_file;
	output_file = fopen("data.txt","w");
	for (i = 0; i < 360; i++)
	{

		rad = i*M_PI/180;
		vsin = sin(rad);
	    fprintf(output_file, "%f %f\n",rad,vsin);
	    //printf("%f,%f\n",rad,vsin);
	}

	fclose(output_file);
	//creates data.txt


	float a;
	float b;
	int ii = 0;
	FILE* input_file;
	int counter = 0;
	input_file = fopen("data.txt","r");

	while(fscanf(input_file,"%f %f\n",&a,&b) != EOF)
	{
	 counter++;
	}
	rewind(input_file);
	float x[counter];
	float y[counter];
	for(ii=0;ii<counter;ii++)
	{
		fscanf(input_file,"%f %f\n",&x[ii],&y[ii]);
        printf("%f\n",y[ii]);
	}
	fclose(input_file);


	float mean;
	float std_dev;
	/*mean*/
	float length = sizeof(y)/sizeof(y[0]);
	float sum = 0;
	i = 0;
	for (i = 0; i < length ; i++)
	{
		sum = sum + y[i];
	}

	mean = sum / length;


	/*std_dev*/
	float k = 0;
	/* k = sum of result of each number subtract the mean and square*/
	ii = 0;
	for (ii = 0; ii < length; ii++)
	{
		k = k + pow((y[ii]-mean),2);
	} 

	std_dev = sqrt(k/(length-1));


	printf("\nMean = %f", mean);
	printf("\nStandard deviation = %f", std_dev);

	
}








