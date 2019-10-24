#include <stdio.h>
#include <stdlib.h>
#include<math.h>

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
	
}