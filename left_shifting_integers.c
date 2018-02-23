#include <stdio.h>

void displayBits(unsigned int v);

void main()	{
	unsigned int bits = 100000;
	printf("Before\n ");
	displayBits(bits);
	bits <<= 4;
	printf("After\n ");
	displayBits(bits);
	printf("\n");
	
}

void displayBits(unsigned int v)	{
	unsigned int c; //counter
	//declare dMask and left shift 31 bits
	unsigned int dMask = 1 << 31;
	
	
	//loop through bits
	for(c = 1; c <= 32; c++)	{
		putchar(v & dMask ? '1' : '0');
		v <<= 1; //shift left by 1
		
		if(c % 8 == 0)	{ // output a space after 8 bits
			putchar(' '); 
		} // end if statement
	} // end for loop
	
	putchar('\n');
} // end function displayBits


