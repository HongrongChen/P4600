#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f_mean (float data[])
{
	
	float length = sizeof(data)/sizeof(data[0]);
	float sum = 0;
	int i;
	for (i = 0; i < length ; i++)
	{
		sum = sum + data[i];
	}

	mean = sum / length;
	return mean;
}
