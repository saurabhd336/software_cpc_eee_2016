#include<bits/stdc++.h>
using namespace std;

/*
First thing to realise is that for a grid sized n*m, the total number of ways is
(n - 1 + m - 1)C(n-1) where nCr => number of ways to choose r objects out of n distinct objects
Why?
Notice that to reach bottom right, we need to make m - 1 'Right' movements and n - 1 'Down' movements.
Now these movements can be made in any order. So the number of ways to arrange m - 1 'R' moves and m - 1 'D' moves is
	(n - 1 + m - 1)!
	----------------	=	(n - 1 + m - 1)C(n-1)  Why? Cuz Maths
	(n-1)! * (m - 1)!
Now the task is to write a effiecint nCr code that doesn't overflow.
Check out the two ways here
*/



//This uses naive factorial function
//Will overflow if (n + m - 2)! does not fit in a 32 bit integer
//BAD!
int fact(int n)
{
	if(n == 0)
		return 1;
	return n * fact(n - 1);
}

int paths(int n, int m)
{
	return fact(n + m - 2) / (fact(n - 1) * fact(m - 1));
}


//Here we use an efficient way to calculate nCr which makes sure we divide before next multiplication so it never overflows
int paths_optimised(int n, int m)
{
	int ans = 1;
	int N = (n + m - 2);
	int R = (n - 1);
	R = max(R, N - R);
	for(int i = N; i > R; i--)
	{
		ans *= i;
		ans /= (N - i + 1);
	}
	
	return ans;
}

int main()
{
	cout<<paths(3, 2)<<"\n";
	cout<<paths(4, 3)<<"\n";
	cout<<paths(4, 5)<<"\n";
	cout<<paths_optimised(4, 5)<<"\n";
	return 0;	
}
