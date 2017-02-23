#include<bits/stdc++.h>
using namespace std;

int max_candies(int c[], int size, int k)
{
	priority_queue<int> pq;
	int ans = 0;
	//Supports push in O(log(n)), delete in O(log(n)) and getting max element in O(1)
	//We'll extract the max, add half to answer, and push the new number to pq again.
	//One etract + delete = O(log(n)), one push = O(log(n)), and this happens K times hence the total TC = O(k * log(n))
		
	for(int i = 0; i < size; i++)
		pq.push(c[i]);
	
	for(int i = 0; i < k; i++)
	{
		int temp = pq.top();
		pq.pop();
		
		//Add half to answer
		ans += temp / 2;
		
		pq.push((temp + 1) / 2); //Push ceil(temp / 2) back
	}
	
	return ans;
}

int main()
{
	//One way to solve this provblem is to find the maximum in the array each time.
	//Time complexity will then be O(n * k)
	//We can do better ( O(k * log(n)) ) using a max heap data structure
	//https://en.wikipedia.org/wiki/Heap_(data_structure)
	//You can check C++ implementation within the repo
	//We'll use inbuilt heap i.e. priority_queue STL
	
	int candies[] = {5, 1, 12, 3, 2};
	int size = sizeof(candies) / sizeof(int);
	int k = 4;
	cout<<max_candies(candies, size, k);
	return 0; 
}
