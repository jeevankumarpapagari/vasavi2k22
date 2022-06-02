#include<stdio.h>
#include<stdbool.h>
int n;

bool isItSafePositionToPlace(int maze[n][n],int r,int c)
{
	if(r>=0 && r<n && c>=0 && c<n && maze[r][c]==1)
		return true;
	else
		return false;
	//return (r>=0 && r<n && c>=0 && c<n && maze[r][c]==1)
}

bool isMazeSolved(int maze[n][n],int r,int c,int sol[n][n])
{
	if(r==n-1 && c==n-1)//Base condition
	{
		sol[r][c] = 1;
		return true;
	}
	
	if(isItSafePositionToPlace(maze,r,c))
	{
		sol[r][c] = 1;
		if(isMazeSolved(maze,r,c+1,sol))//Forward position
			return true;
		if(isMazeSolved(maze,r+1,c,sol))//Downward position
			return true;
		sol[r][c] = 0;
		return false;
	}
}

void printSolution(int sol[n][n])
{
	printf("\nSolution of the maze is:\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
}

int main()
{
	printf("Enter n value: ");
	scanf("%d",&n);
	
	int maze[n][n], i, j, sol[n][n];
	printf("Enter values into maze in the form of 0/1:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&maze[i][j]);
			sol[i][j] = 0;
		}
	}
	
	if(isMazeSolved(maze,0,0,sol))
		printSolution(sol);
	else
		printf("The solution does not existed");
	return 0;
}
