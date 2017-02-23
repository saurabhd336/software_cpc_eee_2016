#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

queue<node **> q1, q2;

void insert1(int data)
{
	node * newnode = new node;
	newnode->left = newnode->right = NULL;
	newnode->data = data;
	
	if((*q1.front()) == NULL)
	{
		(*q1.front()) = newnode;
		return;
	}
	
	if(!(*q1.front())->left)
	{
		(*q1.front())->left = newnode;
		q1.push(&newnode);
		return;
	}
	
	(*q1.front())->right = newnode;
	q1.push(&newnode);
	q1.pop();
	return;
}

void insert2(int data)
{
	node * newnode = new node;
	newnode->left = newnode->right = NULL;
	newnode->data = data;
	
	if((*q2.front()) == NULL)
	{
		(*q2.front()) = newnode;
		return;
	}
	
	if(!(*q2.front())->left)
	{
		(*q2.front())->left = newnode;
		q2.push(&newnode);
		return;
	}
	
	(*q2.front())->right = newnode;
	q2.push(&newnode);
	q2.pop();
	return;
}


void inorder(node * root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


//Mirror check starts here
bool check_mirror(node * r1, node * r2)
{
	//If both are null, they are mirrors
	if(r1 == NULL && r2 == NULL)
		return 1;
	
	//If one is null and other isn't, they aren't mirrors
	if(r1 == NULL || r2 == NULL)
		return 0;
	
	//If left of 1 is mirror to right of 2 and right1 is mirror to left2 and data is same at root, then return true
	return (r1->data == r2->data) && check_mirror(r1->left, r2->right) && check_mirror(r1->right, r2->left);
}

int main()
{
	node * root1 = NULL, *root2 = NULL;
	q1.push(&root1);
	q2.push(&root2);
	
	//Inserts in order i.e. level wise
	insert1(5);
	insert1(4);
	insert1(8);
	//inorder(root1);
	
	//You can try for other trees as well
	insert2(5);
	insert2(8);
	insert2(4);
	//inorder(root2);
	cout<<check_mirror(root1, root2)<<"\n";
	return 0;
}
