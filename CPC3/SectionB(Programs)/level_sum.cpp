#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

node * create_BST_helper(int arr[], int start, int end)
{
	//Base case
	if(start > end)
		return NULL;
	
	//Choose middle element as root and construct left and right subtrees recursively
	int mid = (start + end) / 2;
	node * newnode = new node;
	newnode->data = arr[mid];
	
	//We've already chosen mid as root hence left subtree will be [start... mid - 1]
	newnode->left = create_BST_helper(arr, start, mid - 1);
	
	//Similarly right subtree will be [mid + 1...end]
	newnode->right = create_BST_helper(arr, mid + 1, end);
	return newnode;
}

node * create_BST(int arr[], int size)
{
	return create_BST_helper(arr, 0, size - 1);
}

void level_sum(node * root)
{
	//Pretty similar to level order traversal of a tree using a queue
	//http://www.geeksforgeeks.org/level-order-tree-traversal/
	queue<node *> q;
	int sum = 0;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node * temp = q.front();
		q.pop();
		//If we encounter NULL, a level finished so print sum, set sum to 0 and push NULL
		if(temp == NULL)
		{
			cout<<sum<<" ";
			sum = 0;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			sum += temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main()
{
	//You can try for other sorted arrays too
	int arr[] = {1, 3, 5, 6, 8, 11, 14, 16};
	int size = sizeof(arr) / sizeof(int);
	node * root = NULL;
	root = create_BST(arr, size);
	
	//Using the same tree from previous question
	level_sum(root);
	return 0;
}
