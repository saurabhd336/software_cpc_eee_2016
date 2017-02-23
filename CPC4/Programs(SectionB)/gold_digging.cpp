#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

//Idea is to recursively check both paths and return maximum of both
//As we observe overlapping subproblems, we can use dynamic programming to reduce time complexity
//dp[i][j] represents max gold we can get while travelling from (i, j) to (n-1, m-1)
int gold_digger_helper(int grid[][3], int x, int y, int n, int m)
{
	//Base case
	if(x == n || y == m)
		return 0;
	
	if(dp[x][y] != -1) //Already calculated
		return dp[x][y];
	
	return dp[x][y] = grid[x][y] + max(gold_digger_helper(grid, x + 1, y, n, m), gold_digger_helper(grid, x, y + 1, n, m)); 
}

int gold_digger(int grid[][3], int n, int m)
{
	return gold_digger_helper(grid, 0, 0, n, m);
}

int main()
{
	//You can test for other grids too
	int grid[][3] = {{1, 4, 6}, {2, 5, 2}, {2, 6, 9}};
	int n, m;
	n = sizeof(grid) / sizeof(grid[0]);
	m = sizeof(grid[0]) / sizeof(int);
	
	memset(dp, -1, sizeof(dp));
	cout<<gold_digger(grid, n, m);
	return 0;
}
