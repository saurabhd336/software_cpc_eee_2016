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

int merge_detect(node * h1, node * h2)
{
	int len1, len2;
	len1 = len2 = 0;
	
	//Find length of each list
	
	node * temp1 = h1;
	while(temp1)
	{
		len1++;
		temp1 = temp1->next;
	}

	node * temp2 = h2;
	while(temp2)
	{
		len2++;
		temp2 = temp2->next;
	}
	
	//Now assuming the lists merge, we will traverve the longer list by |len1 - len2| length
	
	if(len1 > len2)
	{
		//h1 needs to be traversed
		for(int i = 0; i < len1 - len2; i++)
			h1 = h1->next;
	}
	
	//Else traverse h2
	else
		for(int i = 0; i < len2 - len1; i++)
			h2 = h2->next;
		
	//Now traverse each of the heads one node at a time and return the value of node at which they merge.
	//If they don't, print error statement and return -1 or whatever
	
	while(h1 && h2)
	{
		if(h1 == h2)	//NOT (h1->val == h2->val), we need to check equality of nodes and not the equality of values
		{
			cout<<"Merge detected at ";
			return h1->data;
		}
		h1 = h1->next;
		h2 = h2->next;
	}
	//If we reach here, no merge is present
	cout<<"No merge detected\n";
	return -1;
}

void merge(node ** h1, node ** here)
{
	node * prev;
	
	node * head1 = *h1;
	while(head1)
	{
		prev = head1;
		head1 = head1->next;
	}
	
	prev->next = *here;
}

int main()
{
	node * head1 = NULL;
	insert(&head1, 8);
	insert(&head1, 7);
	insert(&head1, 6);
	insert(&head1, 5);
	insert(&head1, 4);
	insert(&head1, 3);
	insert(&head1, 2);
	insert(&head1, 1);
	
	node * head2 = NULL;
	insert(&head2, 2);
	insert(&head2, 1);
	insert(&head2, 0);
	
	//head1 and head2 do not merge yet
	cout<<merge_detect(head1, head2)<<"\n";
	
	//Let's merge head1 and head2 at node 6 of head1
	node * merge_here = head1->next->next->next->next->next;
	merge(&head2, &merge_here);
	
	cout<<merge_detect(head1, head2)<<"\n";
	return 0;
}
