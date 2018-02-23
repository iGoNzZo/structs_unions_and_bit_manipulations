#include <stdio.h>

union floatingPoint	{
	float f;
	double d;
	long b;
};

void main()	{
	union floatingPoint p;
	p.f = 24.456;
	p.d = 24.456;
	p.b = 24.456;
	
	printf("%f\n", p.f);
	printf("%f\n", p.d);
	printf("%ld\n", p.b);
}

/* Here, we can see that the values of i and f members of union got corrupted because the final value assigned to the variable has occupied the memory location and this is the reason that the value of str member is getting printed very well.
/*
