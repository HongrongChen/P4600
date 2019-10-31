#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>
#include <string.h>

float EorrorHandling(int error_num)
{
	if (error_num == 0)
	{
		printf("Couldn't open defaultRM.\n");
		return 0;
	}
	if (error_num == 1)
	{
		printf("Couldn't find FG.\n");
		return 0;
	}
	if (error_num == 2)
	{
		printf("\nFailed to open FG");
		return 0;
	}
/*	if (error_num == 3)
	{
		printf("\nFG IDN Error");
		return 0;
	}
*/
		if (error_num == 4)
	{
		printf("\nSet_FG Error");
		return 0;
	}
		if (error_num == 5)
	{
		printf("\nCouldn't find scope");
		return 0;
	}
		if (error_num == 6)
	{
		printf("\nFailed to open scope");
		return 0;
	}
		if (error_num == 7)
	{
		printf("\nScope IDN Error");
		return 0;
	}
}

ViStatus Find_FG()
{
	
	ViStatus status = VI_SUCCESS;
	ViSession defaultRM;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViChar description[VI_FIND_BUFLEN];
	status = viOpenDefaultRM(&defaultRM);
	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR",&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			printf("%s\n",description);
		}
		else
		{
			EorrorHandling(1);
		}
	}
	else
	{
		EorrorHandling(0);
	}
}

ViStatus Open_FG(ViSession FGhandle, char* resultBuffer)
{
	ViSession defaultRM;
	ViStatus status = VI_SUCCESS;
	ViChar description[VI_FIND_BUFLEN];
	ViUInt32 resultCount;
	status = viOpen(defaultRM,description,VI_NULL,VI_NULL,&FGhandle);
	if(status == VI_SUCCESS)
	{
		printf("Opened\n");
	}
	else
	{
		EorrorHandling(2);
	}
}

ViStatus set_FG(ViSession FGhandle,float set_f,float Vpp)
{
	char command[50];
	ViStatus status;
	ViUInt32 resultCount;
	sprintf(command,":SOUR1:APPL:SIN %f,%f,0,0\n", set_f,Vpp);
	viWrite(FGhandle,command,strlen(command),&resultCount);
	viWrite(FGhandle,":OUTP1 ON\n",10,&resultCount);
	printf("\nOn");

	

}

ViStatus Find_scope()
{
	ViSession defaultRM;
	ViStatus status = VI_SUCCESS;
	status = viOpenDefaultRM(&defaultRM);
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViChar description[VI_FIND_BUFLEN];
	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",&resourceList,&num_inst,description);
	}
	else
	{
		EorrorHandling(5);
	}
}

ViStatus Open_scope(ViSession scopehandle, char* resultBuffer)
{
	ViSession defaultRM;
	ViStatus status = VI_SUCCESS;

	status = viOpenDefaultRM(&defaultRM);
	ViChar description[VI_FIND_BUFLEN];
	ViUInt32 resultCount;
	if(status ==VI_SUCCESS)
	{
		status = viOpen(defaultRM,description,VI_NULL,VI_NULL,&scopehandle);
		if(status == VI_SUCCESS)
		{
			viWrite(scopehandle,"*IDN\n",6,&resultCount);
			viRead(scopehandle,resultBuffer,256,&resultCount);
		}
		else
		{
			EorrorHandling(7);
		}
	}
	else
	{
		EorrorHandling(6);
	}
}

ViStatus set_scope_voltage(ViSession scopehandle, float volts)
{
	char command[36];
	ViStatus status;
	ViUInt32 resultCount;
	sprintf(command,"CH1:SCA %E\n",volts);
	viWrite(scopehandle,command,strlen(command),&resultCount);
}


ViStatus read_scope(ViSession scopehandle, char*dataBuffer, int npoints)
{
	ViUInt32 resultCount;
	ViStatus status;
	viWrite(scopehandle,"DAT:SOU CH1\n",12,&resultCount);
	viWrite(scopehandle,"CURV?\n",6,&resultCount);
	sleep(2);
	status = viRead(scopehandle,dataBuffer,npoints,&resultCount);
}




int main()
{
	unsigned char resultBuffer[256];
	ViSession defaultRM, scopeHandle, FGHandle;
	ViStatus status;

	char dataBuffer[2500];
	float frequency=500.0;
	float Vpp=2.5;

	Find_FG();
	Open_FG(FGHandle,resultBuffer);
	set_FG(FGHandle,frequency,Vpp);

	/*Find_scope();
	Open_scope(scopeHandle,resultBuffer);
	set_scope_voltage(scopeHandle,2);
	read_scope(scopeHandle,dataBuffer,2500);
*/
}