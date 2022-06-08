#include<stdio.h>
#include<string.h>
struct student
{
	int roll, marks;
	char name[20];
	float cgpa;
};//Every student information

int main()
{
	int n;
	printf("Enter total number of records: ");
	scanf("%d",&n);//Reading total records value
	
	struct student s[n];//Declaration of n records
	int i, j;
	for(i=0;i<n;i++)
	{
		printf("Enter Roll, Name, Marks and CGPA: ");
		scanf("%d %s %d %f",&s[i].roll,s[i].name,&s[i].marks,&s[i].cgpa);
	}
	
	for(i=0;i<n-1;i++)//Sorting list based on name of the student
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i].name,s[j].name) > 0)
			{
				struct student temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	
	for(i=0;i<n-1;i++)//Sorting the list based on CGPA [Names are same]
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i].name,s[j].name) == 0)
			{
				if(s[i].cgpa < s[j].cgpa)
				{
					struct student temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
	
	printf("\nStudents Information:\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%d\t%.2f\n",s[i].roll,s[i].name,s[i].marks,s[i].cgpa);
	return 0;
}
