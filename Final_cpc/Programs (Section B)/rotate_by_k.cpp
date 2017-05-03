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

void print_list(node * head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"\n";
}

node * rotate_by_k(node * head, int k)
{
	//If no or just one element, simply return
	if(head == NULL || head->next == NULL)
		return head;
	//Make the list cyclic
	node * temp = head->next, *prev = head;
	while(temp)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = head;
	
	//Move head k steps, keeping track of it's previous, set prev->next to NULL and return head
	for(int i = 0; i < k; i++)
	{
		prev = head;
		head = head->next;
	}
	prev->next = NULL;
	return head;
	
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
	
	head = rotate_by_k(head, 2);
	
	cout<<"After rotation by 2\n";
	print_list(head);
	return 0;	
}
