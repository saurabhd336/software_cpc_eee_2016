#include<bits/stdc++.h>
using namespace std;

//This is a standard dynamic programming problem
//We will maintain a 2D dp array that stores the states so that we don't have to recompute them
//Without dp, the time complexity will be O(2^n)
//With dp the time complexity is O(n * v) (WEW!!)

int dp[100][100]; //Ideally should be large enough to store dp[n][v] values

int subset_sum_helper(int a[], int size, int pos, int v)
{
	//Base cases
	//If v = 0, we reached the sum, return true
	//If we passed the last element, or the current sum exceeded the value, return 0
	if(v == 0)
		return 1;
	if(pos == size || v < 0)
		return 0;
	
	//DP computed before, return it
	if(dp[pos][v] != -1)
		return dp[pos][v];
	
	//Now we have two possibilities for a[pos], either include it in the current sum or exclude it
	//We will check both possibilities recursively and return their logical OR
	
	//subset_sum(a, size, pos + 1, v) = not choosing a[pos] therefore trying to find sum 'v' with remaining elements from pos + 1 to end
	//subset_sum(a, size, pos + 1, v - a[pos]) = choosing a[pos] therefore trying to find remaing sum 'v-a[pos]' with elements from pos + 1 to end
	
	return dp[pos][v] = subset_sum_helper(a, size, pos + 1, v) || subset_sum_helper(a, size, pos + 1, v - a[pos]);
}

int subset_sum(int a[], int size, int v)
{
	return subset_sum_helper(a, size, 0, v);
}

int main()
{
	int a[] = {3, 5, 1, 4, 6};
	int size = sizeof(a) / sizeof(int);
	
	memset(dp, -1, sizeof(dp)); //set dp array to -1
	
	//Checking with sum 8 and 17
	cout<<subset_sum(a, size, 8)<<"\n";
	cout<<subset_sum(a, size, 17);
	return 0;
}

