#include<stdio.h>
struct student
{
	int roll, marks;
	char name[20];
	float cgpa;
};

int main()
{
	int n, i, j;
	printf("Enter n value: ");
	scanf("%d",&n);//Total records information
	
	struct student s[n];//Array of structure
	for(i=0;i<n;i++)
	{
		printf("Enter Roll, Name, Marks and CGPA: ");
		scanf("%d %s %d %f",&s[i].roll,s[i].name,&s[i].marks,&s[i].cgpa);
	}
	
	for(i=0;i<n-1;i++)//Sorting information based on name
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
	
	for(i=0;i<n-1;i++)//Sorting information based on CGPA [Names are same]
	{
		for(j=i+1;j<n;j++)
		{
			if((strcmp(s[i].name,s[j].name) == 0) && (s[i].cgpa < s[j].cgpa))
			{
				struct student temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	
	printf("\nStudents Information:\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%d\t%.2f\n",s[i].roll,s[i].name,s[i].marks,s[i].cgpa);
	
	return 0;
}
