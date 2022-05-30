#include<stdio.h>
#include<stdbool.h>

int n;

bool isItSafePosition(int maze[n][n],int r,int c)
{
	if(r>=0 && r<n && c>=0 && c<n && maze[r][c])
		return true;
	else
		return false;
}

bool isMazeSolved(int maze[n][n],int r,int c,int sol[n][n])
{
	if(r==n-1 && c==n-1)//Base case of recursive method
	{
		sol[r][c] = 1;
		return true;
	}
	
	if(isItSafePosition(maze,r,c))
	{
		sol[r][c] = 1;
		if(isMazeSolved(maze,r+1,c,sol))//Downward position
			return true;
		if(isMazeSolved(maze,r,c+1,sol))//Forward position
			return true;
		sol[r][c] = 0;
		return false;
	}
}

void printSolution(int sol[n][n])
{
	printf("\nPath in the maze is:\n");
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
	scanf("%d",&n);
	
	int maze[n][n], i, j, sol[n][n];
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
		printf("Solution does not existed");
	return 0;
}
