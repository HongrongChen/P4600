#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	/*comment*/
	float angle;
	angle = 0.7;
	float hypot = 12;
	float opp[30];
	int i;
	for (i = 0; i<30 ; i++)
		/* start num      from.. to ..    incrment*/
	{
		angle = (M_PI /2) * (i/30.0);
		opp[i] = hypot * sin(angle);
		printf("\n Oppsite side = %f cm",opp[i]);
	}
	printf("Angle 5 = %f",opp[4]);
	
	return 0;
}
