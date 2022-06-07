#include<stdio.h>
#include<string.h>
struct student
{
	int roll;
	char name[30];
	int marks;
	float cgpa;
};

int main()
{
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);
	
	struct student s[n];
	int i, j;
	for(i=0;i<n;i++)
	{
		printf("Enter Roll, Name, Marks and CGPA: ");
		scanf("%d %s %d %f",&s[i].roll,s[i].name,&s[i].marks,&s[i].cgpa);
	}
	//Sorting list based on name
	for(i=0;i<n-1;i++)
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
	//Sorting list based on CGPA [Descending] if name is same
	for(i=0;i<n-1;i++)
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
	
	printf("\nInformation of the Students:\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%d\t%f\n",s[i].roll,s[i].name,s[i].marks,s[i].cgpa);
	
	return 0;
}
