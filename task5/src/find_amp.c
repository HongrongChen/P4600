#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "find_amp.h"



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
