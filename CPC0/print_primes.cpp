#include<bits/stdc++.h>
using namespace std;

//Time complexity  = O(N * sqrt(N) ) (Approx)
void print_prime(int N)
{
	int flag;
	for(int i = 2; i <= N; i++)
	{
		flag = 0;
		for(int j = 2; j <= sqrt(i); j++)
			if(i % j == 0)
			{
				flag = 1;
				break;
			}
		if(flag == 0)
			cout<<i<<" ";
	}
}


//Optimized code using Sieve of Eratosthenes
//Time complexity  = O(N*log(log(N))
//Can read about Sieve here 
//https://www.topcoder.com/community/data-science/data-science-tutorials/mathematics-for-topcoders
void print_prime_optimised(int N)
{
	bool is_prime[N + 1];
	memset(is_prime, true, sizeof(is_prime));
	
	for(int i = 2; i <= sqrt(N); i++)
		if(is_prime[i])
			for(int j = i*i; j <= N; j+=i)
				is_prime[j] = false;
	
	for(int i = 2; i <= N; i++)
		if(is_prime[i])
			cout<<i<<" ";
}

int main()
{
	print_prime(20);
	cout<<"\n";
	print_prime_optimised(20);
	return 0;
}
