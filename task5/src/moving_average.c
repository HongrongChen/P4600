#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include "moving_average.h"



float moving_average(float* data,int length,int window,float* smoothdata)
{	
	
	float m;
	float b[length];
	int n;
	FILE* output_file;
	output_file = fopen("smoothed_data.txt","w");

	for(n=0; n<(length-(window-1)); n++)
	{
		m=0;
		for(int i=n;i<(n+window);i++)
			{
			m += data[i];
			}	
		b[n]=m;
	 	smoothdata[n]= b[n]/window;
	 	fprintf(output_file, "%f\n",smoothdata[n] );
	}
	fclose(output_file);
	return 0;
}
