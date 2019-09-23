#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f_mean(float* inp, int len)
{
	float sum;
	int i;
	float mean;
	for (i = 0; i < len ; i++)
	{
		sum += inp[i];
	}

	mean = sum / len;
	return mean;
}


float f_std_dev(float* inp, int len)
{
	float mean;
	float std_dev;
	int i;
	for (i = 0; i < len ; i++)
	{
		mean += inp[i];
	}
	mean = mean/len;

	/*std_dev*/
	float a = 0;
	/* a = sum of result of each number subtract the mean and square*/
	int ii = 0;
	for (ii = 0; ii < len; ii++)
	{
		a = a + pow((inp[ii]-mean),2);
	} 

	std_dev = sqrt(a/(len-1));
	return std_dev;
}

float f_mean_std_dev(float* inp, int len, float* ans_mean, float* ans_std_dev)
{
	float mean;
	float std_dev;
	int i;
	int ii;
	float sum;

	for (i = 0; i < len ; i++)
	{
		sum += inp[i];
	}

	mean = sum / len;
	ans_mean = mean;

	float a = 0;
	/* a = sum of result of each number subtract the mean and square*/
	
	for (ii = 0; ii < len; ii++)
	{
		a = a + pow((inp[ii]-mean),2);
	} 

	ans_std_dev = sqrt(a/(len-1));
	

	return 0;
}



int main()
{	
	float a[] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};
	int length = sizeof(a)/sizeof(a[0]);

	
	float m = f_mean(a,length);
	
	float std = f_std_dev(a,length);
	
	printf("\n%f,\n%f",m,std);

	float x;
	float y;
	float k = f_mean_std_dev(a, length,x,y);
	printf("\n%f,\n%f",x,y);
	
	return 0;
}