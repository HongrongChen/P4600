#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>




int main()
{
	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle, FGHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];

	float frequency = 500;

	status = viOpenDefaultRM(&defaultRM);
	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR",&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,VI_NULL,VI_NULL,&FGHandle);
			
			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);
				viWrite(FGHandle,"*IDN\n",6,&resultCount);
				if(status == VI_SUCCESS)
				{
					viWrite(FGHandle,":SOUR1:APPL:SIN frequency,5,0,0\n",33,&resultCount);
					viWrite(FGHandle,":OUTP1 ON\n",11,&resultCount);
				}
				else
				{
					printf("Couldn't open CH1\n");
				}
			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("Couldn't find FG");
		}
	}
	else
	{
		printf("Failed to open defaultRM");
	}
}