#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};

void insert(node ** head, int data)
{
	node * newnode = new node;
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

node * reverse_list(node * head)
{
	//Need to change the links one by one to get newlist
	//Time complexity O(n)
	//Can also be done recursively
	
	node *prev, *next, *current;
	
	prev = next = NULL;
	current = head;
	
	while(current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;
}

void print_list(node * head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"\n";
}


int main()
{
	node * head = NULL;
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	
	print_list(head);
	head = reverse_list(head);
	cout<<"Afer reversal\n";
	print_list(head);
	return 0;
}
