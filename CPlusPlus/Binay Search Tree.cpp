#include <iostream>
using namespace std;

class TreeNode
{
private:
	int data;
	int key;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int d=0) :left(NULL), right(NULL)
	{
		data = d;
		key = 0;
	}
	friend class BST;
};

class BST
{
public:
	TreeNode* parent;
	int size;

	BST() : parent(NULL) { size = 0; }

	bool isEmpty()
	{
		return (parent == NULL);
	}

	bool isParent(TreeNode* Node)
	{
		return (Node->left!=NULL && Node->right!=NULL);
	}

	bool isChild(TreeNode* Node)
	{
		return (Node->left==NULL && Node->right==NULL);
	}

	bool isInternal(TreeNode* Node)
	{
		return (Node!= NULL && Node->left != NULL && Node->right != NULL);
	}

	bool isExternal(TreeNode* Node)
	{
		return (Node->left == NULL && Node->right == NULL);
	}

	void insert(int value = 0)
	{
		TreeNode* newNode = new TreeNode(value);
		if (isEmpty())										
		{
			parent = newNode;									//If parent is empty then add /newNode/ as Parent
			parent->key++;
			size++;
			cout << "Node " << value << " is Parent." << endl;
		}
		else
		{
			TreeNode* temp = parent;
			while (temp != NULL)
			{	
				//Case 1: If Value is less then Parent 
				if (temp->left!=NULL && value < temp->data)
					temp = temp->left;
				else if (value < temp->data)
				{
					temp->left = newNode;
					newNode->key++;
					size++;
					cout << "Node " << value << " added at left of " << temp->data << endl;
					break;
				}
				//Case 2: If Value is greater then Parent 
				else if (temp->right!=NULL && value > temp->data)
					temp = temp->right;
				else if (value > temp->data)
				{
					temp->right = newNode;
					newNode->key++;
					size++;
					cout << "Node " << value << " added at right of " << temp->data << endl;
					break;
				}
			}
		}
	}

	int maxNum(TreeNode* Node)
	{
		while (Node->right!=NULL)
		{
			Node = Node->right;
		}
		return Node->data;
	}
	
	int minNum(TreeNode* Node)
	{
		while (Node->left!=NULL)
		{
			Node = Node->left;
		}
		return Node->data;
	}

	void search(TreeNode* Node,int num)			//Recursive Search Fumction
	{
		if (num == Node->data)
		{
			cout << num << " found in " << Node->key << " Key." << endl;
			return;
		}
		else if (num < Node->data)
			search(Node->left, num);
		else if (num > Node->data)
			search(Node->right, num);
		else { cout << num << " not found!" << endl; }
	}

	void InOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		InOrder(root->left);
		cout << root->data << "\t";
		InOrder(root->right);
	}

	void PreOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		cout << root->data << "\t";
		PreOrder(root->left);
		PreOrder(root->right);
	}

	void PostOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << "\t";
	}
};

int main()
{
	BST Tree;

	Tree.insert(50);
	Tree.insert(20);
	Tree.insert(75);
	Tree.insert(98);
	Tree.insert(80);
	Tree.insert(31);
	Tree.insert(150);
	Tree.insert(39);
	Tree.insert(23);
	Tree.insert(11);
	Tree.insert(77);
	cout << "\nPreOrder Travercel " << endl;
	Tree.PreOrder(Tree.parent);
	cout << "\nInOrder Travercel " << endl;
	Tree.InOrder(Tree.parent);
	cout << "\nPostOrder Travercel " << endl;
	Tree.PostOrder(Tree.parent);
	cout << endl;
	cout << "The Maximum Number in Tree is: " << Tree.maxNum(Tree.parent) << endl;
	cout << "The Minimum Number in Tree is: " << Tree.minNum(Tree.parent) << endl;

	int search = 0;
	cout << "Enter the value to Search in a Tree: ";
	cin >> search;
	Tree.search(Tree.parent,search);

	return 0;
}