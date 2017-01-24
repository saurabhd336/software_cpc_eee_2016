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

void introduce_loop(node ** head, node ** loop_here)
{
	node * prev, *head1 = *head;
	while(head1)
	{
		prev = head1;
		head1 = head1->next;
	}
	
	prev->next = *loop_here;
}

void print_list(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}


//Have two pointers moving at different speeds
//slow moves one node a time while fast moves two nodes a time
//If they ever meet i.e. point to same node, we have a loop
//http://www.geeksforgeeks.org/write-a-c-function-to-detect-loop-in-a-linked-list/
int cycle_detect(node * head)
{
	node * slow = head;
	node * fast = head;
	int flag = 0;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
		{
			flag = 1;
			break;
		}
	}
	
	if(!flag)
	{
		cout<<"No cycle found\n";
		return -1;
	}
	
	
	//Set slow at head and move both pointers one node each
	//The node where they meet is the loop begining
	slow = head;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow->data;
}

int main()
{
	node * head = NULL;
	insert(&head, 8);
	insert(&head, 7);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	
	//Check for loop now.
	cout<<cycle_detect(head)<<"\n";
	
	//helper to introduce a loop in the list
	//Let's introduce a loop at node 4. You can try introducing loop elsewhere
	node * loop_at = head->next->next->next;
	introduce_loop(&head, &loop_at);
	
	//Check for loop
	cout<<"Cycle found at : "<<cycle_detect(head)<<"\n";
	return 0;
}
