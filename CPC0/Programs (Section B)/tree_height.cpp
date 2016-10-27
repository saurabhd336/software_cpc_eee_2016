#include<bits/stdc++.h>
using namespace std;

struct treenode
{
	int data;
	treenode * left;
	treenode * right;
};

void insert(treenode ** root, int data)
{
	if(*root == NULL)
	{
		treenode * newnode = new treenode;
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		*root = newnode;
		return;
	}
	
	if(data < (*root)->data)
		insert(&(*root)->left, data);
	else
		insert(&(*root)->right, data);
}

int find_height(treenode *root)
{
	//A simple recursive function
	//Base case: if root is NULL, return height as 0
	//Else return 1 + max(find_height(root->left), find_height(root->right))
	
	if(root == NULL)
		return 0;
	return 1 + max(find_height(root->left), find_height(root->right));
}


int main()
{
	treenode *root = NULL;
	insert(&root, 7);
	insert(&root, 4);
	insert(&root, 9);
	insert(&root, 1);
	insert(&root, 3);
	//Results in a BST with a heignt of 4
	
	cout<<"Height of the tree is: "<<find_height(root);
	return 0;
}
