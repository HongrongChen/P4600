#include <visa.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



void main(int argc, char** argv)
{
	char inq[] = "*IDN?/n"
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	unsigned int num_inst;


	viUInt32 returnCount = 0;
	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	/*char idnResponse[1024];
	char message[1024];*/

	status = viOpenDefaultRM(&defaultRM);
	if (status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::*INSTR",
			&resourceList,&num_inst,description);
		if (status == VI_SUCCESS)
		{
			viOpen(defaultRM,description,
				VI_NULL,VI_NULL,&scopeHandle);
			if (status == VI_SUCCESS);
			{
				printf("Opened %s",description);
			}
			else
			{
				printf("Failed to open %s",description);
			}
		else
		{
			printf("Couldn't find any instruments");	
		}
	else
	{
		printf("Couldn't find any")
	}	
	}
}