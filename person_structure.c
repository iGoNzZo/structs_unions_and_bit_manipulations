#include <stdio.h>
#include <string.h>

struct person {
	char lastName[15];
	char firstName[15];
	char age[4];
};

void initializer();
void updateRecord();
void deleteRecord();

void main()	{
	initializer();
	
	FILE *fp;
	
	if((fp = fopen("nameage.dat", "r+")) == NULL)	{
		puts("File could not be opened");
	}
	else 	{
		int i = 0;
		printf("Enter: lastname firstname age seperated by a space:\n");
		char lastHolder[15];
		char firstHolder[15];
		char ageHolder[4];
		while(i < 10)	{
			printf("%s", "? ");
			scanf("%15s%15s%4s", lastHolder, firstHolder, ageHolder);
			
			struct person p;
			strcpy(p.lastName, lastHolder);
			strcpy(p.firstName, firstHolder);
			strcpy(p.age, ageHolder); 
			if(i == 9)	{
				fprintf(fp, "%s %s %s", p.lastName, p.firstName, p.age);
			}
			else	{
				fprintf(fp, "%s %s %s\n", p.lastName, p.firstName, p.age);
			}
			
			i++;
		}
		fclose(fp);
	}
	
	updateRecord();
	
	deleteRecord();
}

void deleteRecord()	{
	char lastHolder[15];
	char firstHolder[15];
	char ageHolder[4];
	FILE *fp;
	
	printf("DELETE RECORD NOW:");
	printf("Enter: lastname firstname age seperated by a space:\n");
	scanf("%15s%15s%4s", lastHolder, firstHolder, ageHolder);

	struct person p;
	strcpy(p.lastName, lastHolder);
	strcpy(p.firstName, firstHolder);
	strcpy(p.age, ageHolder); 
	
	if((fp = fopen("nameage.dat", "r+")) == NULL)	{
		puts("File could not be opened");
	}
	else	{
		fscanf(fp, "%15s%15s%4s", lastHolder, firstHolder, ageHolder);
		while(!feof)	{
			if(p.lastName == lastHolder && p.firstName == firstHolder)	{
				fprintf(fp, "%s %s %s\n", "unsigned", "", "0");
			}
			fscanf(fp, "%15s%15s%4s", lastHolder, firstHolder, ageHolder);
		}
	}
	fclose(fp);
}

void updateRecord()	{
	char lastHolder[15];
	char firstHolder[15];
	char ageHolder[4];
	
	char lastHolder2[15];
	char firstHolder2[15];
	char ageHolder2[4];
	FILE *fp;
	
	printf("UPDATE RECORD NOW:");
	printf("Enter: lastname firstname age seperated by a space:\n");
	scanf("%15s%15s%4s", lastHolder, firstHolder, ageHolder);
	
	printf("Enter new age for person: ");
	scanf("%4s", ageHolder);

	struct person p;
	strcpy(p.lastName, lastHolder);
	strcpy(p.firstName, firstHolder);
	strcpy(p.age, ageHolder); 
	
	if((fp = fopen("nameage.dat", "r+")) == NULL)	{
		puts("File could not be opened");
	}
	else	{
		fscanf(fp, "%15s%15s%4s", lastHolder2, firstHolder2, ageHolder2);
		while(!feof)	{
			if(lastHolder == lastHolder2 && firstHolder == firstHolder2)	{
				fprintf(fp, "%s %s %s\n", p.lastName, p.firstName, p.age);
			}
			fscanf(fp, "%15s%15s%4s", lastHolder2, firstHolder2, ageHolder2);
		}
	}
	fclose(fp);
}

void initializer()	{
	FILE *fp;
	
	if((fp = fopen("nameage.dat", "w")) == NULL)	{
		puts("File could not be opened");
	}
	else	{
		struct person p;
		strncpy(p.lastName, "unsigned", 15);
		strncpy(p.firstName, "", 15);
		strncpy(p.age, "0", 4);
		
		int i = 0;
		while(i < 100)	{
			fprintf(fp, "%s %s %s\n", p.lastName, p.firstName, p.age);
			i++;
		}
		fclose(fp);
	}
}
