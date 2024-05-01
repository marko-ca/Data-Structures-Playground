#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

// Globle Constant Size of Table Array
const int TABLE_SIZE = 15;

class Hash;
class Node
{
public:
    string name;
    int phoneNum;
    Node* next;
    Node() : next(NULL)
    {
        name = "empty";
        phoneNum = 0;
    }
    friend class Hash;
};

class Hash
{
private:
    Node* hashTable[TABLE_SIZE]; 

public:
    Hash()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            hashTable[i] = new Node;
        }
    }

    int hashFunction(string str)      //HashFun
    {
        int hashKey = 0, index = 0; // holds hashKey h(k) and index
        int sum = 0;                // holds sum of ASCII codes of letters
        int strLength = 0;          // holds current length of string

        strLength = str.length();

        for (int i = 0; i < 2; i++)
        {
            sum += int(str[i]);
        }

        index = sum % TABLE_SIZE;
        return index;
    }

    int getNumberOfItemsAtIndex(int index)
    {
        int count = 0;

        if (hashTable[index]->name == "empty" && hashTable[index]->phoneNum == 0)
        {
            return count;
        }
        else
        {
            Node* temp = hashTable[index];

            while (temp != NULL)
            {
                count++;          
                temp = temp->next; 
            }
        }
        return count;
    }

    void addItem(string personName, int personPhoneNum)
    {

        int index = 0;

        index = hashFunction(personName);

        if (hashTable[index]->name == "empty" && hashTable[index]->next == NULL)
        {
            hashTable[index]->name = personName;
            hashTable[index]->phoneNum = personPhoneNum;
            hashTable[index]->next = NULL;
        }
        else
        {
            Node* temp = hashTable[index];
            Node* newNode = new Node;
            newNode->name = personName;
            newNode->phoneNum = personPhoneNum;
            newNode->next = NULL;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void removeItem(string personName)
    {
        int index = 0;
        index = hashFunction(personName);

        Node* delPtr = NULL; // holds Node to be deleted
        Node* p = NULL;      // backward *ptr
        Node* q = NULL;      // forward *ptr

        if (hashTable[index]->name == "empty" && hashTable[index]->phoneNum == 0)
        {
            cout << personName << "'s information was not present in the HashTable.\n\n";
        }

        else if (hashTable[index]->name == personName && hashTable[index]->next == NULL)
        {
            hashTable[index]->name = "empty";
            hashTable[index]->phoneNum = 0;
            hashTable[index]->next = NULL;

            cout << personName << "'s information was removed from the Hash Table.\n";
        }

        else if (hashTable[index]->name == personName && hashTable[index]->next != NULL)
        {
            delPtr = hashTable[index];
            hashTable[index] = hashTable[index]->next;
            delete delPtr;
            cout << personName << "'s information was removed from the Hash Table.\n";
        }

        else if (hashTable[index]->name != personName && hashTable[index]->next != NULL)
        {

            p = hashTable[index];
            q = hashTable[index]->next;

            while (q != NULL && q->name != personName)
            {
                p = p->next;
                q = q->next;
            }


            if (q == NULL && q->name != personName)
            {
                cout << personName << "'s information was not present in the HashTable.\n\n";
            }
            else if (q != NULL && q->name == personName)
            {
                delPtr = q;
                q = q->next;
                p->next = q;
                delete delPtr;

                cout << personName << "'s information was removed from the Hash Table.\n";
            }
        }
    }

    void searchPhoneNumber(string personName)
    {
        int index = 0;        // holds hashKey h(k)
        int phoneNo = 0;      // holds the searched person's phone #
        bool isFound = false; // flag variable


        index = hashFunction(personName);

        Node* temp = hashTable[index];

        while (temp != NULL)
        {
            if (temp->name == personName)
            {
                isFound = true;
                phoneNo = temp->phoneNum;
                break;
            }
            temp = temp->next;
        }

        if (isFound == true)
        {
            cout << "+---------------\n";
            cout << "| Name: " << temp->name << endl;
            cout << "| Phone number: " << temp->phoneNum << endl;
            cout << "+---------------\n";
        }
        else
        {
            cout << personName << "'s information was not present in Hash Table.\n"
                << endl;
        }
    }

    void printItemsAtIndex(int index)
    {
        Node* temp = hashTable[index];

        if (temp->name == "empty" && temp->phoneNum == 0)
        {
            cout << "There is no Nodes present at index = " << index << endl;
        }
        else
        {
            cout << "Number of Nodes at index " << index << " = "
                << getNumberOfItemsAtIndex(index) << endl;
            cout << "index = " << index << " contains the following Nodes:\n\n";

            while (temp != NULL)
            {
                cout << "---------------\n";
                cout << "Name: " << temp->name << endl;
                cout << "Phone number: " << temp->phoneNum << endl;
                cout << "---------------\n\n";
                temp = temp->next;
            }
        }
    }

    void printTable()
    {
        int numNodes = 0; // holds number of other linked Nodes

        for (int i = 0; i < TABLE_SIZE; i++)
        {

            numNodes = getNumberOfItemsAtIndex(i);

            cout << "---------------\n";
            cout << "Index = " << i << endl;
            cout << "Name: " << hashTable[i]->name << endl;
            cout << "Phone number: " << hashTable[i]->phoneNum << endl;
            cout << "# of items at index = " << i << " : " << numNodes << endl;
            cout << "---------------\n\n";
        }
    }
};

int main()
{
    Hash hashObj;

    int index = 0;
    string userString = "\0";

    // insert functoin called to add some Data items in HashTable
    hashObj.addItem("Wali Muhammad", 900100);
    hashObj.addItem("Farjad", 900101);
    hashObj.addItem("Haseeb", 900103);
    hashObj.addItem("Newman", 900102);
    hashObj.addItem("Martin Garix", 900104);
    hashObj.addItem("Afrojack", 900105);
    hashObj.addItem("Skrillex", 900106);
    hashObj.addItem("Diplo", 900107);
    hashObj.addItem("Alok", 900108);
    hashObj.addItem("Dimitri Vegas", 900109);
    hashObj.addItem("Like Mike", 900110);
    hashObj.addItem("Steve Aoki", 900111);


    hashObj.printTable();

    cout << "Enter the person name you want to search and Print: ";
    getline(cin, userString);
    hashObj.searchPhoneNumber(userString);

     cout << "Enter Name to delete record from HashTable: ";
     cout << "or 'exit' to quit the delete function.";
     getline(cin, userString);

    if (userString != "exit")
    {
         // function call to search for phone #
         hashObj.removeItem(userString);
         cout << endl;
         hashObj.printTable();
    }

    cout << endl;
    system("pause");
    return 0;
}