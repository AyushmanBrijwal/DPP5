#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
    Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printPostorder(Node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);

	printPostorder(node->right);

	cout << node->data << " ";
}

void printInorder(Node* node)
{
	if (node == NULL)
		return;
	
	printInorder(node->left);


	cout << node->data << " ";

	printInorder(node->right);
}

void printPreorder(Node* node)
{
	if (node == NULL)
		return;

	
	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}

int main()
{
    Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(50);
	root->right->left->right = new Node(10);

	cout << "Preorder traversal of binary tree: ";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree: ";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree: ";
	printPostorder(root);

	return 0;
}
