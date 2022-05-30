#include<stdio.h>
#include<stdbool.h>

int n;

bool isItSafePosition(int maze[n][n],int r,int c)
{
	if(r<n && r>=0 && c<n && c>=0 && maze[r][c])
		return true;
	else
		return false;
	//return (r<n && r>=0 && c<n && c>=0 && maze[r][c])
}

bool isMazeSolved(int maze[n][n],int r,int c,int sol[n][n])
{
	if(r==n-1 && c==n-1)
	{
		sol[r][c] = 1;
		return true;
	}
	
	if(isItSafePosition(maze,r,c))
	{
		sol[r][c] = 1;
		if(isMazeSolved(maze,r,c+1,sol))//Moving forward direction
			return true;
		if(isMazeSolved(maze,r+1,c,sol))//Moving downward direction
			return true;
		sol[r][c] = 0;
		return false;
	}
}

void printSolution(int sol[n][n])
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
}

int main()
{
	printf("Enter value of n: ");
	scanf("%d",&n);
	
	int maze[n][n], i, j, sol[n][n];
	printf("Enter %d rows of input into maze in the form of 0 / 1:\n");
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
		printf("\nSolution does not existed");
}
