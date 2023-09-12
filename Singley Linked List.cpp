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
	Node(int d = 0,string l="\0") : next(NULL)
	{
		data = d;
		letter = l;
	}
	friend class SLL;
};

class SLL
{
	Node* head;
public:
	SLL() :head(NULL) {}

	bool isEmpty()
	{
		return (head == NULL);
	}

	void insertatHead(int val=0)
	{
		Node *newNode = new Node(val);
		if (isEmpty())
			head = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}
		cout << "Node added at head." << endl;
	}
	void insertatEnd(int val=0)
	{
		Node *newNode = new Node(val);
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
		cout << "Node added at end of the list." << endl;
	}

	void insertatValue(int val=0)
	{
		Node *newNode = new Node(val);
		int search = 0;
		if (isEmpty())
			head = newNode;
		else
		{	
			cout << "Enter the value where you want to add the new Node: ";
			cin >> search;
			Node* temp = head;
			while (temp->data != search)
			{
				temp = temp->next; 
				if (temp->data == search)
					break;
			}
			temp->next = newNode;
		}
		cout << "Node added after " << search << " ." << endl;
	}

	void DeletefromHead()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = head;
			head = temp->next;
			delete temp;
			cout << "Head Node delete Successfully!" << endl;
		}
	}
	
	void DeletefromEnd()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = head;
			while (temp->next->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = NULL;
			cout << "Last Node delete Successfully!" << endl;
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
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	SLL SinglyLinkedList;
	SinglyLinkedList.insertatHead(2);
	SinglyLinkedList.insertatHead(1);
	SinglyLinkedList.insertatEnd(3);
	SinglyLinkedList.insertatEnd(4);
	SinglyLinkedList.insertatEnd(6);
	SinglyLinkedList.Display();
	SinglyLinkedList.DeletefromHead();
	SinglyLinkedList.DeletefromEnd();
	SinglyLinkedList.Display();
	SinglyLinkedList.insertatValue(5);
	SinglyLinkedList.Display();

	return 0;
}