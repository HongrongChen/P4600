#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>
#include <string.h>


ViStatus set_F_A(ViSession FGhandle,float set_point,float Vpp)
{
	char command[50];
	ViUInt32 resultCount;
	sprintf(command,":SOUR1:APPL:SIN %f,%f,0,0\n", set_point,Vpp);
	viWrite(FGhandle,command,strlen(command),&resultCount);
}


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

	float frequency=500.0;
	float Vpp=2.5;

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
					set_F_A(FGHandle,frequency,Vpp);
					viWrite(FGHandle,":OUTP1 ON\n",10,&resultCount);
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