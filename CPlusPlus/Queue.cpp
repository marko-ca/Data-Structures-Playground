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
	friend class Queue;
};

class Queue
{
	Node* head;
	int size;
public:
	Queue() :head(NULL) { size = 0; }

	bool isEmpty()
	{
		return (head == NULL);
	}

	int Size()
	{
		return size;
	}

	void Enqueue(int val = 0)
	{
		Node* newNode = new Node(val);
		if (isEmpty())
			head = newNode;
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		size++;
		cout << "Node Enqueued." << endl;
	}

	void Dequeue()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = head;
			head = temp->next;
			delete temp;
			size--;
			cout << "Dequeued Successfully!" << endl;
		}
	}

	void Display()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << "<-";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	Queue Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Enqueue(6);
	Q.Display();
	cout << "Size of Queue is: " << Q.Size() << endl;
	Q.Dequeue();
	Q.Dequeue();
	Q.Display();
	cout << "Size of Queue is: " << Q.Size() << endl;

	return 0;
}