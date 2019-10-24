#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float moving_average(float* data, int len)
{
	int i = 0;
	float M = 0.5;
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
				amp[i] += M*(amp[i+j]);
			}
			else
				amp[i] = 0;
		}
	}
	
}


