#include <stdio.h>
#include "bits.h"



unsigned int BinaryMirror(unsigned int number)
{

	unsigned int binary[31]={};
	unsigned int number_temp = number;
	unsigned int decimal=0; 
	unsigned int j=0;
	//storing 32 zeros 
	for (j=0 ; j<32; j++)
	{
		binary[j]=0;
	}
	unsigned int i = 0; 
	//converting to binary 
	while(number>0)
	{
		binary[i] = number%2; 
		number = number/2; 
		i++; 
	}
	
	//convert binary to decimal 
	unsigned int base = 1; 
	int k=0;
	for ( k=31; k>=0; k--)
	{
		if (binary[k] == 1) 
		{
			decimal += base; 
		}
		base = base*2; 

	}
	//printf("Mirror decimal Value:%u\n",decimal);
	return decimal; 
	
}


unsigned int SequenceCount(unsigned int number)
{
	unsigned int binary[31]={};
	int i = 0;
	int count = 0;
	//storing 32 zeros 
	//printf("Decimal:%u\n",number);
	int j=0;
	for (j=0; j<32; j++)
	{
		binary[j]=0;
	}
	while(number>0)
	{
		binary[i] = number%2; 
		number = number/2; 
		i++; 
	}
	
	/*printf("Binary:");
	int a=0;
	for (a=32; a>0; a--)
	{
		printf("%u", binary[a]);

	}*/
	
	//printf("\n");
	int h=0;
	for (h=32; h>=1; h--)
	{
		int temp_one = 1; 
		int temp_two = 0; 
		if ((binary[h] == temp_one) && (binary[h-1] == temp_two))
		{
			//if (binary[i+1] == temp_two)
			{
				count++; 
			}
		}
	}
	//printf("hello\n"); 

	//printf("count:%u\n",count);
	
	return count;

}
