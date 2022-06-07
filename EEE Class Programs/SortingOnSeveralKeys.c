#include<stdio.h>

struct student
{
	int roll, marks;
	char name[30];
	float cgpa;
};

int main()
{
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);//Total number of records
	
	struct student s[n];//Array of structure
	int i, j;
	for(i=0;i<n;i++)
	{
		printf("Enter Roll, Name, Marks and CGPA: ");
		scanf("%d %s %d %f",&s[i].roll,s[i].name,&s[i].marks,&s[i].cgpa);
	}
	
	for(i=0;i<n-1;i++)//Sort based on name of the students
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
	
	for(i=0;i<n-1;i++)//Sort based on CGPA in case names are same
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
	
	printf("\nStudents information:\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%d\t%.2f\n",s[i].roll,s[i].name,s[i].marks,s[i].cgpa);
	return 0;
}
