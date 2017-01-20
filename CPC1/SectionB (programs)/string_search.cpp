#include<bits/stdc++.h>

using namespace std;

/*
We can write a naive solution that checks each character of B as a start for A and does basic string matching at each point
	time complexity = O(length(A) * length(B))
Such naive algorithms would most certainly time out in online tests
Learn any one optimised string matching algorithm (KMP, Rabin Karp, Z algorithm etc)

Here I've demostrated string matching using Z algorithm
	Time complexity = O(length(A) + length(B))
You can read about Z algorithm online
http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/tutorial/
*/

int string_search(char a[], char b[])
{
	char s[1000];
	strcpy(s, a);
	s[strlen(s)] = '$';
	strcat(s, b);
	//s = a + '$' + b (concatenation with a special character)
	int len = strlen(s);


	int z[len], l, r;
	l = r = 0;
	z[0] = len;
	
	for(int i = 1; i < len; i++)
	{
		if(i > r)
		{
			l = r = i;
			while(r < len && s[r] == s[r - l])
				r++;
			z[i] = r - l;
			r--;
		}
		
		else
		{
			int k = i - l;
			if(z[k] < r - i + 1)
				z[i] = z[k];
			else
			{
				l = i;
				while(r < len && s[r] == s[r - l])
					r++;
				z[i] = r - l;
				r--;
			}	
		}
	}
	
	int len1 = strlen(a);
	for(int i = len1 + 1; i < len; i++)
		if(z[i] == len1)
			return 1;
	return 0;
}

int main()
{
	//Change the strings to check outputs for other cases
	char s1[] = {'p', 'e', 'n'};
	char s2[] = {'c', 'a', 'r', 'p', 'e', 'n', 't', 'e', 'r'};
	
	if(string_search(s1, s2))
		cout<<s1<<" is present in "<<s2<<"\n";
	else
		cout<<s1<<" is not present in "<<s2<<"\n";
 	
	return 0;
}
