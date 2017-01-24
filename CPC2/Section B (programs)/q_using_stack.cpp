#include<bits/stdc++.h>
using namespace std;


//The idea is to use two stacks. Let's call them s1 and s2. The push operation is done on s2. Pop must be done from the bottom of s2 then.
//But s2's bottom can't be accesed as it's a stack. This is where we use s1. When popping or get_top, we first check if s1 is empty, if it isn't, we pop from the top of s1.
//Else, we reverse_pop s2 into s1 i.e. one by one pop from s2 and push into s1. This way the last element in s2 becoems top of s1 and we may proceed with popping from s1.
//http://www.geeksforgeeks.org/queue-using-stacks/
stack<int> s1, s2; 
//WHAT IS THIS!!!! 
//Using inbuilt stack provided by C++ STL (standard template library). Might as well write my own but why bother.
// Declaration -> stack<data type> <name>; examples:  stack<int> s, stack<double> s1, stack<stack<int> > s2 (can even make stacks of stacks) Noice!
//It's worth noting that a lot of these containers are provided by C++ STL and are really helpful while programming especially when time a factor (Online coding rounds).
//A simple google search about STL in C++ would be really helpful.
//We will be covering STL in tutorials.
void reverse_pop()
{
	//Keep popping s2 until it's empty. empty() is also an inbuilt function
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void push(int val)
{
	//Simple push into s2
	s2.push(val);
}


//If s1 is empty, we reverse_pop s2 into s1
//If s1 is still empty we return i.e. the queue is indeed empty

void pop()
{
	if(s1.empty())
		reverse_pop();
	
	if(s1.empty())
	{
		cout<<"Queue is empty\n";
		return;
	}
	
	s1.pop();
}

int get_top()
{
	if(s1.empty())
		reverse_pop();
	if(s1.empty())
	{
		cout<<"Queue is empty\n";
		return -1;
	}
		
	return s1.top();
}


int main()
{
	pop();
	cout<<get_top()<<"\n";
	push(1);
	push(2);
	push(3);
	cout<<get_top()<<"\n";
	pop();
	cout<<get_top()<<"\n";
	pop();
	cout<<get_top()<<"\n";
	pop();
	cout<<get_top()<<"\n";
	return 0;
}
