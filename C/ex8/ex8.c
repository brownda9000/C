#include<stdio.h>
#include<stdlib.h>

struct employee
{
	char name[50];
	char designation[50];
	int age;
	float salary
} emp;

int main()
{
	FILE *fp;
	int i;  // loop variable
	char string[20];
	
	

	fp=fopen("employee.txt","wb");      //opening file in wb to write into file

	if(fp==NULL)    //check if can be open
	{
		printf("\nERROR IN OPENING FILE");
		exit(1);
	}     

	for(i=0;i<2;i++)                        
	{
		printf("Enter employee, title, age, salary\n");
		//scanf("%19[^\n]s",emp.name);
		fgets(emp.name,50,stdin);
        fgets(emp.designation,50,stdin);

        fgets(string, 19, stdin);
        emp.age = atoi(string);
		fgets(string, 19, stdin);
        emp.salary = atof(string);
		//scanf("%d",&emp.age);
		//scanf("%f",&emp.salary);
		fwrite(&emp,sizeof(emp),1,fp);      //writing into file
	    
	}
	fclose(fp);

    
	fp = fopen("employee.txt", "rb");
	if(fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	

	while( fread(&emp, sizeof(emp), 1, fp) == 1 )
	{
		printf("Name: %s \n", emp.name);
		printf("Designation: %s \n", emp.designation);
		printf("Age: %d \n", emp.age);
		printf("Salary: %.2f \n\n", emp.salary);
	}

	fclose(fp);
	return 0;
}
