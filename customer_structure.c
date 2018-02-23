#include <stdio.h>

struct customer {
	char lastName[15];
	char firstName[15];
	unsigned int customerNumber;
	
	struct{
		char phoneNumber[11];
		char address[50];
		char city[15];
		char state[3];
		char zipCode[6];
	}personal;
	
}customerRecord = {"Gonzalez", "Steven", 1, {"8318018637", "123 home", "Hollister", "Ca", "95023"}};

struct customer *customerPtr = &customerRecord;

void main()	{
	printf("struct: %s\n", customerRecord.lastName);
	printf("pointer: %s\n", (*customerPtr).lastName);
	
	printf("struct: %s\n", customerRecord.firstName);
	printf("pointer: %s\n", (*customerPtr).firstName);
	
	printf("struct: %u\n", customerRecord.customerNumber);
	printf("pointer: %u\n", (*customerPtr).customerNumber);
	
	printf("struct: %s\n", customerRecord.personal.phoneNumber);
	printf("pointer: %s\n", (*customerPtr).personal.phoneNumber);
	
	printf("struct: %s\n", customerRecord.personal.address);
	printf("pointer: %s\n", (*customerPtr).personal.address);
	
	printf("struct: %s\n", customerRecord.personal.city);
	printf("pointer: %s\n", (*customerPtr).personal.city);
	
	printf("struct: %s\n", customerRecord.personal.state);
	printf("pointer: %s\n", (*customerPtr).personal.state);
	
	printf("struct: %s\n", customerRecord.personal.zipCode);
	printf("pointer: %s\n", (*customerPtr).personal.zipCode);
}
