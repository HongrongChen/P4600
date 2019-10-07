#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

void main(int argc, char** argv)
{
	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];

	int y;

	int lsb;
	int msb;

	status = viOpenDefaultRM(&defaultRM);
	FILE*output_file;
	output_file = fopen("data.dat","w");

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );
				viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount);
				
				viWrite(scopeHandle,"CURV?\n",6,&resultCount);
				sleep(2);
				if(status == VI_SUCCESS)
				{
					viRead(scopeHandle,dataBuffer,2500,&resultCount);
					for(int i = 0; i<2500; i++)
					{
						y = dataBuffer[i];
						printf("\nRaw = %x,  Read = %d",y,y);
						fprintf(output_file,"%d\n",dataBuffer[i]);
					}
				}
				else
				{
					printf("\nError");
				}
				


				for(int i = 0; i<2500; i++)
				{
					y = dataBuffer[i];
					printf("\nRaw = %x,  Read = %d",y,y);
					fprintf(output_file,"%d\n",dataBuffer[i]);
				}
			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}

	else
	{
		printf("\nFailed to open defaultRM");
	}
	fclose(output_file);
}