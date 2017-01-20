#include<bits/stdc++.h>

using namespace std;

//A trivial solution is to traverse the array linearly and return the first value we encounter which is > v
//Time complexity = O(n)
//We can exploit the fact that the array is sorted and write a binary search based solution
//Time complexity = O(log(n))

int find_greater(int arr[], int size, int v)
{
	int ans = -1, low, high, mid;
	low = 0;
	high = size - 1;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(arr[mid] > v)
		{
			//Found a value > v but it may not be the smallest value > v
			//So update ans and search in the lower half again
			ans = arr[mid];
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}


int main()
{
	int arr[] = {1, 4, 6, 7, 8, 10, 13, 24, 56};
	
	int size = (sizeof(arr) / sizeof(int));
	
	cout<<find_greater(arr, size, 7)<<"\n";
	cout<<find_greater(arr, size, 100)<<"\n";
	cout<<find_greater(arr, size, 12)<<"\n";
	cout<<find_greater(arr, size, 20)<<"\n";
	
	return 0;
}
