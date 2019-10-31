#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>



ViStatus set_voltage(ViSession handle, float volts)
{
	char command = [36]
	sprintf(command,"CH1:SCALE %E\n", volts);
	viWrite(handle,command,strlen(command),&resultCount);
}


Vistatus get_curve(ViSession handle, char *databuffer, int npoints)
{
	
	ViStatus status;
	viWrite(handle,"CURV?\n",6,&resultCount);
	status = viRead(handle,databuffer,npoints,&resultCount);
	return status;
}


ViSession scopeHandle;
ViSession FGHandle;

viFindRsrc(defaultRM,"USB[0-9]::0x0699?*INSTR",......,description);
viOpen(defaultRM,description,....,&scopeHandle);

viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR",....,description);
viOpen(defaultRM,description,.....,&FGHandle);

viWrite(scopeHandle,"*IDN/n",6,...);
viWrite(FGHandle,"IDN?/n",6,...);


void main(int argc, char** argv)
{

	ViStatus status = VI_SUCCESS;
	VIFindList resourceList;
	ViUnit32 num_inst;
	ViUnit32 resultCount;
	ViChar description[VI_FIND_BUFLEN];
	char databuffer[2500];

	ViSession scopeHandle;
	ViSession FGHandle;
	status = viPenDefaultRM(&defaultRM);
	//Find FG
	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR"
			,&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,VI_NULL,VI_NULL,&FGHandle);

		}
		else
		{
			printf("\nCouldn't find FG");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}
}