#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

// maximum size of HashTable
const int TABLE_SIZE = 8;

// class -Node implementation
class Node
{
public:
    // attributes
    string name;
    int phoneNum;
    Node *nextNode;

    Node()
    {
        // Default Constructor
        name = "empty";
        phoneNum = 0;
        nextNode = NULL;
    }
};

class Hash
{
private:
    Node *hashTable[TABLE_SIZE]; // *ptr to dynamically allocate array

public:
    Hash()
    {
        // Default Constructor

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            hashTable[i] = new Node; // dynamically allocate array
        }
    }

    int hashFunction(string str)
    {
        // func. that takes a string as argument and return a
        // HashKey h(k) for an index.

        // local variables
        int hashKey = 0, index = 0; // holds hashKey h(k) and index
        int sum = 0;                // holds sum of ASCII codes of letters
        int strLength = 0;          // holds current length of string

        // get the length of string
        strLength = str.length();

        // using 'for' loop to get sum of ASCII codes
        for (int i = 0; i < 2; i++)
        {
            // get sum of ASCII of first two letters
            sum += int(str[i]);
        }

        index = sum % TABLE_SIZE; // 'division-method' to get index or hashKey
        return index;
    }

    int getNumberOfItemsAtIndex(int index)
    {
        // utility func. to get count of Items at a particular index

        // local variables
        int count = 0;

        // check whether given index contains no Node
        if (hashTable[index]->name == "empty" && hashTable[index]->phoneNum == 0)
        {
            return count;
        }
        else
        {
            // create a '*temp'
            Node *temp = hashTable[index];

            while (temp != NULL)
            {
                count++;               // increment count by 1
                temp = temp->nextNode; // update '*temp'
            }
        }

        return count;
    }

    void addItem(string personName, int personPhoneNum)
    {
        // func. to insert a Node into hashTable

        // local variables
        int index = 0;

        // function call to get hashKey h(k) or index
        index = hashFunction(personName);

        // Case1: when at given index of hashTable, there is no other linked Nodes exists
        if (hashTable[index]->name == "empty" && hashTable[index]->nextNode == NULL)
        {
            hashTable[index]->name = personName;
            hashTable[index]->phoneNum = personPhoneNum;
            hashTable[index]->nextNode = NULL;
        }
        // Case2: when at given index of hashTable, there is some other linked Nodes exists
        else
        {
            // create a '*temp' ptr
            Node *temp = hashTable[index];

            // create a new dynamicall allocated Node
            Node *newNode = new Node;

            // set the Data attributes
            newNode->name = personName;
            newNode->phoneNum = personPhoneNum;
            newNode->nextNode = NULL;

            while (temp->nextNode != NULL)
            {
                // traverse till last Node in a particular index
                temp = temp->nextNode;
            }

            temp->nextNode = newNode;
        }
    }

    void removeItem(string personName)
    {
        // func. to remove a Node from HashTable

        // local variables
        int index = 0; // holds the hashKey h(k) or index

        // function call to get hashKey h(k)
        index = hashFunction(personName);

        // create some *ptr
        Node *delPtr = NULL; // holds Node to be deleted
        Node *p = NULL;      // backward *ptr
        Node *q = NULL;      // forward *ptr

        /*
        Outline for removing Nodes at a particular index (Bucket):
        ## Case1: given particular index (Bucket) is empty.
        ## Case2: only 1 Node (Data item) contained at particular index (Bucket) and
                  that Node have matching 'personName'.
        ## Case3: first Node have matching 'personName' but there are more additional
                  Nodes exists at particular index (Bucket).
        ## Case4: There are some Nodes exists at particular index (Bucket) but
                  first Node is not a match
                  - No match found throughout
                  - match found at some Node
        */

        // Case1: given particular index (Bucket) is empty
        if (hashTable[index]->name == "empty" && hashTable[index]->phoneNum == 0)
        {
            cout << personName << "'s information was not present in the HashTable.\n\n";
        }

        // Case2: only 1 Node (Data item) contained at particular index (Bucket) and
        // that Node have matching 'personName'.
        else if (hashTable[index]->name == personName && hashTable[index]->nextNode == NULL)
        {
            hashTable[index]->name = "empty";
            hashTable[index]->phoneNum = 0;
            hashTable[index]->nextNode = NULL;

            // display message
            cout << personName << "'s information was removed from the Hash Table.\n";
        }

        // Case3: first Node have matching 'personName' but there are more additional
        // Nodes exists at particular index(Bucket).
        else if (hashTable[index]->name == personName && hashTable[index]->nextNode != NULL)
        {
            delPtr = hashTable[index];
            hashTable[index] = hashTable[index]->nextNode;

            // release memory
            delete delPtr;

            // display message
            cout << personName << "'s information was removed from the Hash Table.\n";
        }

        // Case4: There are some Nodes exists at particular index(Bucket) but
        // first Node is not a match
        // - No match found throughout
        // - match found at some Node
        else if (hashTable[index]->name != personName && hashTable[index]->nextNode != NULL)
        {
            // point *p to previous Node before that Node to be deleted
            p = hashTable[index];
            // point *q to that Node to be deleted
            q = hashTable[index]->nextNode;

            while (q != NULL && q->name != personName)
            {
                // traverse till last linked Node
                p = p->nextNode;
                q = q->nextNode;
            }

            // - No match found throughout
            if (q == NULL && q->name != personName)
            {
                // when no matching Node is found throughout
                cout << personName << "'s information was not present in the HashTable.\n\n";
            }
            // - match found at some Node
            else if (q != NULL && q->name == personName)
            {
                // when some matching Node is found
                delPtr = q;
                q = q->nextNode;
                p->nextNode = q;

                // release memory
                delete delPtr;

                // display message
                cout << personName << "'s information was removed from the Hash Table.\n";
            }
        }
    }

    void searchPhoneNumber(string personName)
    {
        // func. to search for a particular phone number of a person
        // in hashTable.

        // local variables
        int index = 0;        // holds hashKey h(k)
        int phoneNo = 0;      // holds the searched person's phone #
        bool isFound = false; // flag variable

        // function call to get hashKey h(k) or index
        index = hashFunction(personName);

        // create a '*temp' pointer
        Node *temp = hashTable[index];

        while (temp != NULL)
        {
            // traverse till last linked Node at a given index
            if (temp->name == personName)
            {
                // when 'personName' matched in HashTable
                isFound = true;
                phoneNo = temp->phoneNum;
                break;
            }

            // update '*temp' pointer
            temp = temp->nextNode;
        }

        // perform validation
        if (isFound == true)
        {
            cout << "---------------\n";
            cout << "Name: " << temp->name << endl;
            cout << "Phone number: " << temp->phoneNum << endl;
            cout << "---------------\n";
        }
        else
        {
            cout << personName << "'s information was not present in Hash Table.\n"
                 << endl;
        }
    }

    void printItemsAtIndex(int index)
    {
        // func. to print content of linked Nodes at a particular index

        // create a '*temp' pointer
        Node *temp = hashTable[index];

        // check whether there is a Node exists at given index or not
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

                // update '*temp'
                temp = temp->nextNode;
            }
        }
    }

    void printTable()
    {
        // func. to print content of HashTable

        // local variables
        int numNodes = 0; // holds number of other linked Nodes

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            // get number of linked items
            numNodes = getNumberOfItemsAtIndex(i);

            cout << "---------------\n";
            cout << "index = " << i << endl;
            cout << "Name: " << hashTable[i]->name << endl;
            cout << "Phone number: " << hashTable[i]->phoneNum << endl;
            cout << "# of items at index = " << i << " : " << numNodes << endl;
            cout << "---------------\n\n";
        }
    }
};

int main()
{
    // create an object of Hash class
    Hash hashObj;

    // local variables
    int index = 0;
    string userString = ""; // holds string entered by user

    // insert some Data items in HashTable
    hashObj.addItem("Haider ali", 900100);
    hashObj.addItem("Syed Faraz", 900101);
    hashObj.addItem("Samiullah", 900102);
    hashObj.addItem("Qamar", 900103);
    hashObj.addItem("Rizwan", 900104);
    hashObj.addItem("Usman", 900105);
    hashObj.addItem("Junaid", 900106);
    hashObj.addItem("Kashif", 900107);
    hashObj.addItem("Humayoun", 900108);
    hashObj.addItem("Ahmed", 900109);
    hashObj.addItem("Abdur Rasheed", 900110);
    hashObj.addItem("Arham", 900111);

    // print content of hashTable
    hashObj.printTable();

    // print content of a particular index
    // hashObj.printItemsAtIndex(7);

    while (userString != "exit")
    {
        // taking input
        cout << "Enter Name to delete record from HashTable: ";
        getline(cin, userString);

        if (userString != "exit")
        {
            // function call to search for phone #
            hashObj.removeItem(userString);
            cout << endl;
            hashObj.printTable();
        }
    }
    cout << endl;
    system("pause");
    return 0;
}