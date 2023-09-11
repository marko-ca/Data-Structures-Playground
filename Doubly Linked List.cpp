#include<iostream>
#include<string>
using namespace std;

class Node
{
private:
	int data;
	string letter;
	Node* next;
	Node* prev;
public:
	Node(int d = 0, string l = "\0") : next(NULL), prev(NULL)
	{
		data = d;
		letter = l;
	}
	friend class DLL;
};

class DLL
{
	Node* head;
public:
	DLL() :head(NULL) {}

	bool isEmpty()
	{
		return (head == NULL);
	}

	void insertatHead(int val = 0)
	{
		Node* newNode = new Node(val);
		if (isEmpty())
			head = newNode;
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		cout << "Node added at head." << endl;
	}

	void insertatEnd(int val = 0)
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
			newNode->prev = temp;
		}
		cout << "Node added at end of the list." << endl;
	}

	void insertatValue(int val = 0)
	{
		Node* newNode = new Node(val);
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
			newNode->prev = temp;
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
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NULL;
			cout << "Last Node delete Successfully!" << endl;
		}
	}

	void DisplayfromHead()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << "<=>";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}

	void DisplayfromTail()
	{
		if (isEmpty())
			cout << "List is Empty!" << endl;
		else
		{
			cout << "\nReverse Display" << endl;
			Node* temp = head;
			while (temp->next != NULL)	//Loop to traverse the End of the list
			{
				temp = temp->next;
			}

			//Checkin wether the loop traverse to the last of the List?
			if (temp->next != NULL) //if not the move one step next
				temp = temp->next;
			
			while (temp != NULL && temp!= head)
			{
				cout << temp->data << "<=>";
				temp = temp->prev;
			}

			//Since this loop traverse the list backward to the head it do not print
			//the heads value bcz of the conditon in while loo
			//So we need to display the Heads value explicitly
			cout << temp->data << "<=>";
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	DLL DoublyLinkedList;
	DoublyLinkedList.insertatHead(2);
	DoublyLinkedList.insertatHead(1);
	DoublyLinkedList.insertatHead(0);
	DoublyLinkedList.insertatEnd(3);
	DoublyLinkedList.insertatEnd(4);
	DoublyLinkedList.insertatEnd(5);
	DoublyLinkedList.insertatEnd(6);
	DoublyLinkedList.DisplayfromHead();
	DoublyLinkedList.DeletefromHead();
	DoublyLinkedList.DeletefromEnd();
	DoublyLinkedList.DisplayfromHead();
	DoublyLinkedList.DisplayfromTail();

	return 0;
}