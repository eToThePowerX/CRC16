#include "functions.h"

unsigned int polynomial = 0xA001;

unsigned int XOR(unsigned int constant, unsigned int data)
{
	int i;
	data = constant ^ data;
	for(i=0;i<8;i++)
	{
		if((data & (0x0001)) == 0)
		{
			data = data >> 1;
			data = data & (0x7FFF);
		}
		else
		{
			data = data >> 1;
			data = data & (0x7FFF);
			data = data ^ polynomial;
		}
	}
	return data;
}

unsigned int CRC(int len, int value[])
{
	unsigned int finalCRC,j;

	for(j=0;j<len;j++)
	{
		if(j==0)
		{
			value[j] = XOR(0xFFFF,value[j]);
		}
		else
		{
			value[j] = XOR(value[j-1],value[j]);
			finalCRC = value[j];
		}
		if(j==len-1)
		{
			unsigned int upper,lower;
			upper = finalCRC & (0xFF00);
			upper = upper >> 8;
			lower = finalCRC & (0x00FF);
			lower = lower << 8;
			finalCRC = upper+lower;
		}
	}

	return finalCRC;
}











