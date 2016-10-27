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

node * reverse_list(node * head)
{
	if(head == NULL || head->next == NULL)
		return head;
	
	node *temp = head->next;
	//Reverse the remaining list
	node * newhead = reverse_list(head->next);
	
	//Join head here
	temp->next = head;
	head->next = NULL;
	return newhead;
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
