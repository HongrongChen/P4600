ViStatus set_voltage(ViSession handle, float volts)
{
	char command = [36]
	sprintf(command,"CH1:SCALE %E\n", volts);
	(handle,command,strlen(command),&resultCount)
}


Vistatus get curve(ViSession handle, char *databuffer, int npoints)
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