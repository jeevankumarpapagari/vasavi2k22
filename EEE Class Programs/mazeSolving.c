#include<stdio.h>
#include<stdbool.h>

int n;

bool isItSafePositionToPlace(int maze[n][n],int r,int c)
{
	if(r>=0 && r<n && c>=0 && c<n && maze[r][c])
		return true;
	else
		return false;
	//return (r>=0 && r<n && c>=0 && c<n && maze[r][c])
}

bool isMazeSolved(int maze[n][n],int r,int c,int sol[n][n])
{
	if(r==n-1 && c==n-1)//Base case
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
	int i,j;
	printf("\nSolution path:\n");
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
	printf("Enter maze elements in the form of 0 / 1:\n");
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
		printf("Solution does not existed\n");
	
	return 0;
}
