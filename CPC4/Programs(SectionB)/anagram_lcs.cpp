#include<bits/stdc++.h>
using namespace std;

//Here I'm demostrating bottom up dp, can also be done using a recursive top down dp
int lcs_dp(string s1, string s2)
{
	//Initialized dp array
	vector<vector<int> > dp (s1.length() + 1, vector<int> (s2.length() + 1, 0));
	
	//dp[i][j] represents lcs for s1[i..length] and s2[j...length]
	for(int i = s1.length() - 1; i >= 0; i--)
		for(int j = s2.length() - 1; j >= 0; j--)
		{
			if(s1[i] == s2[j])
			{
				//Match -> dp[i][j] = dp[i + 1][j + 1] + 1;
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	//dp[0][0] is the answer
	return dp[0][0];
}

int b_search(vector<int> &c, int val)
{
	int start, mid, end, ans = -1;
	start = 0;
	end = c.size() - 1;
	
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(c[mid] >= val)
		{
			end = mid - 1;
			ans = mid;
		}
		else
			start = mid + 1;
	}
	return ans;
}

int lis_opt(vector<int> &v)
{
	vector<int> c;
	c.push_back(v[0]);
	for(int i = 1; i < v.size(); i++)
	{
		//Find if v[i] can fit somewhere in c else we just push it
		int pos = b_search(c, v[i]);
		if(pos != -1)
			c[pos] = v[i];
		else
			c.push_back(v[i]);
	}
	return c.size();
}

int main()
{
	string s1, s2;
	s1 = "bacge";
	s2 = "aecbg";
	
	//One way to do this in O(length*length) is to use basic DP based LCS
	cout<<"Using LCS : "<<lcs_dp(s1, s2)<<"\n";
	
	//A clever way to solve this problem is to realise that because the strings are anagrams,
	//If we consider one of them to be sorted, the problem changes to LIS on second string
	//LIS can be solved in O(length* log(length)).
	//We'll treat s1 as sorted and change s2 accordingly
	//Let's create a has storing positions of characters in s1;
	
	int arr[26];
	
	for(int i = 0; i < s1.length(); i++)
		arr[s1[i] - 'a'] = i;
	
	vector<int> a (s2.length());
	for(int i = 0; i < s2.length(); i++)
	{
		//Construct a new array using s2[i]'s position in s1;
		a[i] = arr[s2[i] - 'a'];
	}
	//LIS of a will give LCS of s1 and s2;
	//LIS can be found in n*log(n)
	cout<<"Using LIS : "<<lis_opt(a);
	return 0;
}
