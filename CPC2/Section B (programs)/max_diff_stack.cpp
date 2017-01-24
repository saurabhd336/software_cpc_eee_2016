#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};

//We need to maintain total of three stacks here
//main_stack is the actual stack where we push and pop from
//max_stack is an auxilary stack which works as explained in this link
//http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
//min_stack works exactly like max_stack but stores minimum values
//Basically, max_stack's top and min_stack's top store the current maximum and current minimum values of the stack respectively
//max_diff() is then trivial to implement i.e. just return the difference b/w max and min values from the auxilary stacks  

node * main_stack;
node * min_stack;
node * max_stack;

void push(int val)
{
	//To push, we follow the following three steps
	// 1) Push in main stack
	// 2) If val <= top of min_stack OR min_stack is empty, push val into min_stack
	// 3) if val >= top of max_stack OR max_stack is empty, push val onto max_stack
	
	//Push on main stack
	node * newnode = new node;
	newnode->data = val;
	newnode->next = main_stack;
	main_stack = newnode;
	
	//Check if we need to push onto min_stack
	if(!min_stack || val <= min_stack->data)
	{
		node * newnode1 = new node;
		newnode1->data = val;
		newnode1->next = min_stack;
		min_stack = newnode1;
	}
	
	//Check if we need to push onto max_stack
	if(!max_stack || val >= max_stack->data)
	{
		node * newnode2 = new node;
		newnode2->data = val;
		newnode2->next = max_stack;
		max_stack = newnode2;
	}
}

void pop()
{
	//Steps to be followed
	// 1) If main stack is empty, print error and return
	// 2) Else check if the top of main_stack is  equal to min_stack and/or max_stack
	// 3) Pop min_stack and/or max_stack if it is. Else return
	
	if(!main_stack)
	{
		cout<<"Stack is empty\n";
		return;
	}
		
	
	int val = main_stack->data;
	node * temp = main_stack;
	main_stack = main_stack->next;
	delete temp;

	//Check for min_stack
	//We need not check if min_stack is empty or not. Why?
	if(val == min_stack->data)
	{
		//Pop
		node * temp1 = min_stack;
		min_stack = min_stack->next;
		delete temp1;
	}
	
	//Check for max_stack
	if(val == max_stack->data)
	{
		//Pop
		node * temp2 = max_stack;
		max_stack = max_stack->next;
		delete temp2;
	}
}


int max_diff()
{
	//If the stack is empty return 0
	if(!main_stack)
		return 0;
	//	Min_stack has the current minimum and max_stack has current max
	//	return max_stack->data - min_stack->data;
	return max_stack->data - min_stack->data;
}

int main()
{
	pop();
	push(1);
	cout<<max_diff()<<"\n";
	push(3);
	push(2);
	cout<<max_diff()<<"\n";
	push(0);
	cout<<max_diff()<<"\n";
	pop();
	push(5);
	push(3);
	cout<<max_diff()<<"\n";
	return 0;
}
