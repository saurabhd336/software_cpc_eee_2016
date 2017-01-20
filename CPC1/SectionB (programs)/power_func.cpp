#include<bits/stdc++.h>

using namespace std;

//This is a naive power function which has a time complexity of O(n)
//Check out the faster O(log(n)) function below 
int power_func(int a, int n)
{
	int ans = 1;
	
	for(int i = 0; i < n; i++)
		ans *= a;
	return ans;
}

/*
This is based on a simple observation that
	a^n = a^(n/2) * a^(n/2) if n is even
	a^n = a^(n/2) * a^(n/2) * a if n is odd
As n gets halved in each call, the time reccurance realtion is
	T(n) = T(n/2) + C which => O(log(n)) time complexity
*/
int power_func_optimised(int a, int n)
{
	if(a == 0)
		return 0;

	if(n == 0)
		return 1;
	
	int ans = power_func_optimised(a, n / 2);
	if(n % 2 == 0)
		return ans * ans;
	else
		return ans * ans * a;
}

int main()
{
	cout<<power_func(4, 5)<<"\n";
	cout<<power_func_optimised(4, 5)<<"\n";
	return 0;
}
