#include<bits/stdc++.h>
using namespace std;


//Idea is to sort the array and then swap alternate elements
//Complexity O(n*log(n)) (For sorting) and O(n) for swaping

void change_array(int arr[], int size)
{
	sort(arr, arr + size);
	
	for(int i = 1; i < size; i += 2)
		swap(arr[i], arr[i - 1]);
}

int main()
{
	int arr[] = {5, 1, 6, 13, 8, 3, 2, 4};
	int size = sizeof(arr)/sizeof(int);
	change_array(arr, size);
	
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
	return 0;
}
