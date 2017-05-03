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

int zigzag(treenode *root)
{
	//A slight modification of the level order traversal.
	//For every level, we maintain a flag varaible which is 1 for right to left printing and o for left to right
	//if flag is 1, we print else push the value in a stack
	//Upon encountering a NULL, we print the stack and toggle flag
	queue<treenode *> q;
	int flag = 0;
	q.push(root);
	q.push(NULL);
	stack<int> s;
	while(!q.empty())
	{
		treenode * temp = q.front();
		q.pop();
		if(temp == NULL)
		{
			if(!q.empty())
				q.push(NULL);
			//If flag is 1, print the stack
			while(!s.empty())
			{
				cout<<s.top()<<" ";
				s.pop();
			}
			flag = !flag;
		}
		
		else
		{
			if(flag)
				s.push(temp->data);
			else
				cout<<temp->data<<" ";
			
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}


int main()
{
	
	/*
		 5
		/ \
	   3   6
	  /   / \
	 1   5   7
	
	*/
	treenode *root = NULL;
	insert(&root, 5);
	insert(&root, 3);
	insert(&root, 1);
	insert(&root, 6);
	insert(&root, 7);
	insert(&root, 5);
		
	zigzag(root);
	return 0;
}
