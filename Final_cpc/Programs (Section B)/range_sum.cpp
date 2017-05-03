#include<bits/stdc++.h>
using namespace std;

/*
Naive way will be to sum from i to j for each query. Worst case it'll be O(n*q)
We can optimize by having an extra array called sum such that sum[i] = sum from a[0] to a[i] inclusive
Using that array, for each query we can print sum[j] - sum[i] + a[i].
Building the sum array will be O(n) and then queries will be O(1) each therefore query time will be O(q)
*/

int main()
{
	long long n, q, i, j;
	cin>>n;
	int a[n], sum[n];
	
	for(int i = 0; i < n; i++)
		cin>>a[i];
	
	sum[0] = a[0];
	for(int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];
	
	cin>>q;
	while(q--)
	{
		cin>>i>>j;
		cout<<sum[j] - sum[i] + a[i]<<"\n";
	}
	return 0;
}
