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

void inorder(node * root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node * root)
{
	if(!root)
		return;
		
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node * root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int height(node * root)
{
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

int main()
{
	//You can try for other sorted arrays too
	int arr[] = {1, 3, 5, 6, 8, 11, 14, 16};
	int size = sizeof(arr) / sizeof(int);
	node * root = NULL;
	root = create_BST(arr, size);
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\nHeight difference b/w left and right subtree :";
	cout<<abs(height(root->left) - height(root->right))<<"\n";
	return 0;
}
