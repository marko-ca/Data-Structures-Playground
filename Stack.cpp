#include<iostream>
#include<string>
using namespace std;

class Node
{
private:
	int data;
	string letter;
	Node* next;
public:
	Node(int d = 0, string l = "\0") : next(NULL)
	{
		data = d;
		letter = l;
	}
	friend class Stack;
};

class Stack
{
	Node* top;
public:
	Stack() :top(NULL) {}

	bool isEmpty()
	{
		return (top == NULL);
	}

	Node* topofStack()
	{
		return top;
	}

	void push(int val = 0)
	{
		Node* newNode = new Node(val);
		if (isEmpty())
			top = newNode;
		else
		{
			newNode->next = top;
			top = newNode;
		}
		cout << "Node push." << endl;
	}

	void pop()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = top;
			top = temp->next;
			delete temp;
			cout << "Node Pop!" << endl;
		}
	}

	void Display()
	{
		cout << endl;
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = top;
			while (temp != NULL)
			{
				cout << "| " << temp->data << " |" << endl;
				temp = temp->next;
			}
			cout << "|___|" << endl;
		}
	}
};

int main()
{
	Stack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(9);
	S.Display();
	S.pop();
	S.Display();

	return 0;
}