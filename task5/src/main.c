#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "find_amp.h"
#include "moving_average.h"

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

	float y;
	char scale[6];
	float fscale;
	float volts[2500];
	int lsb;
	int msb;

	status = viOpenDefaultRM(&defaultRM);
	FILE*output_file;
	output_file = fopen("data_volt.dat","w");

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );
				if(status == VI_SUCCESS)
				{
					viWrite(scopeHandle,"CH1:VOL?\n",9,&resultCount);
					viRead(scopeHandle,scale,6,&resultCount);
					sscanf(scale,"%f",&fscale);
				}
				else
				{
					printf("Error\n");
				}

				viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount);
				viWrite(scopeHandle,"CURV?\n",6,&resultCount);
				sleep(2);


				if(status == VI_SUCCESS)
				{
					viRead(scopeHandle,dataBuffer,2500,&resultCount);
					for(int i = 0; i<2500; i++)
					{
						y = dataBuffer[i];
						volts[i] = fscale*10.0/256.0*y;
						printf("\nRaw = %d,  Read = %f",dataBuffer[i],y);
						fprintf(output_file,"%f\n",volts[i]);
					}
				}
				else
				{
					printf("\nError");
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

	float max_amp = find_amp(volts,2500);
	printf("A_max = %.3f",max_amp);
	moving_average(volts,2500,1,float smooth_data[200]);
	printf("%f\n",smooth_data);

	



			}
		}
	
	}
	
}