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

void delete_node(node ** delete_me)
{
	//The problem here is that we cannot find the node before delete_me 
	//if head is not passed.
	//The idea is to copy the data of the node next to delete_me into delete_me
	//And then delete the next node;
	//However the limitation is that if the node to be deleted is the last one, we can't delete it.
	
	if((*delete_me)->next == NULL)
	{
		cout<<"Cannot delete the last node\n";
		return;
	}
	
	//Copy delete_me->next's data into delete_me
	(*delete_me)->data = (*delete_me)->next->data;
	
	//Now delete the next node
	node * temp = (*delete_me)->next;
	(*delete_me)->next = temp->next;
	delete temp;
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
	//Let's say we want to delete node 3
	node * delete_me = head->next->next;
	
	delete_node(&delete_me);
	
	cout<<"After deletion\n";
	print_list(head);
	return 0;	
}
