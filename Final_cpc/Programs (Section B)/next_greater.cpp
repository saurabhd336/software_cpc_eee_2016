#include<bits/stdc++.h>
using namespace std;

/*
IMPORTANT STACK PROBLEM

One naive way to solve the problem is to run two nested loop with the inner loop looking for the next greater elemnt for each i.
Time complexity : O(n^2)

We can do better by using a stack such that each element is pushed only once.
Time complexity : O(n) 
*/

void next_greater(int a[], int size)
{
	stack<int> s;
	int nge[size];
	
	for(int i = 0; i < size; i++)
	{
		//A[i] is greater than A[s.top(), so pop and set a[i] as it's nge.
		while(!s.empty() && a[i] > a[s.top()])
		{
			nge[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	
	while(!s.empty())
	{
		nge[s.top()] = -1;
		s.pop();
	}
	
	for(int i = 0; i < size; i++)
		cout<<nge[i]<<" ";
}

int main()
{
	int a[] = {8, 1, 5, 2, 4, 3, 6, 4};
	int size = sizeof(a) / sizeof(int);
	
	next_greater(a, size);
	return 0;
}
