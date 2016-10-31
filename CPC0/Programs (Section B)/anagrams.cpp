#include<bits/stdc++.h>
using namespace std;

//Time complexity: O(n) where n is the length of each string

int main()
{
	char s1[100], s2[100];
	cin>>s1;
	cin>>s2;
	int len = strlen(s1);
	if(len != strlen(s2))
	{
		//If lengths are not equal, strings can't be anagrams
		cout<<"NO";
		return 0;
	}
	//One way is to sort both the strings
	//and then check if each corresponding
	//character is same or not
	//sorting will require time O(n*log(n))
	
	//Can be done in lesser time by hashing
	
	//Idea is to have an array of size 26
	//arr[i] contains the frequency of ('a' + i)th character
	//example arr[2] = frequency of character 'c'
	//arr[0] = frequency of character 'a'
	
	int arr[26] = {0}; //Initialize each element to 0; 
	
	//For the first string sum up to get frequency for each characeter
	for(int i = 0; i < len; i++)
	{
		arr[s1[i] - 'a']++; 	
		//If s[i] is 'x' for example, s[i] - 'a' will be 'x' - 'a'
		//Which in integer will be 23
	}
	
	//For the second string subtract the count of each character
	for(int i = 0; i < len; i++)
		arr[s2[i] - 'a']--;
	
	//Now arr[i] stores the difference in the number of occurances of character i
	//If each arr[i] is 0, then the strings are anagrams else not
	
	int flag = 0;
	for(int i = 0; i < 26; i++)
		if(arr[i] != 0)
		{
			flag = 1;
			break;
		}
	
	if(!flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
