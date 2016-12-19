#pragma once  
#include <iostream>  
using namespace std;
#include <vector>  

struct Node
{
	Node* left;
	Node *right;
	int value;
	Node(int v)
		:left(NULL)
		, right(NULL)
		, value(v)
	
};
bool GetPath(Node *root, vector<Node*>&path, Node* x)
{
	if (root == NULL)
	{
		return false;
	}
	path.push_back(root);
	if (root == x)
	{
		return true;
	}
	if (GetPath(root->left, path, x))
	{
		return true;
	}
	if (GetPath(root->right, path, x))
	{
		return true;
	}
	else
	{
		path.pop_back();
		return false;
	}
}
Node* find_common_parent(Node* root, Node* a, Node* b)
{
	if (root == NULL)
	{
		return NULL;
	}
	Node* common_parent = NULL;

	vector<Node *> va, vb;
	GetPath(root, va, a);
	GetPath(root, vb, b);
	size_t i = 0;
	while (i < va.size() && i < vb.size() && va[i] == vb[i])
	{
		common_parent = va[i];
		i++;
	}
	return common_parent;

}
