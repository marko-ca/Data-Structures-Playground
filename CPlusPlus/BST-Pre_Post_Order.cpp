#include <iostream>
#include <conio.h>
using namespace std;

class BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode(int val=0)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BSTNode* insert(BSTNode* root, int data)
    {
        if (root == NULL)
            return new BSTNode(data);
        else
        {
            if (data <= root->value)
                root->left = insert(root->left, data);
            else
                root->right = insert(root->right, data);
        }
        return root;
    }

    void search(BSTNode* root, int data)
    {
        if (root == NULL)
        {
            cout << data << " has not found in tree.";
        }
        else if (data == root->value)
        {
            cout << data << " has found in tree.";
        }
        else
        {
            if (data < root->value)
            {
                search(root->left, data);
            }
            else
            {
                search(root->right, data);
            }
        }
    }

    BSTNode* removeNode(BSTNode* root, int value)
    {
        BSTNode* t;
        int cmp = value - root->value;
        if (cmp < 0)
        {
            t = removeNode(root->left, value);
            root->left = t;
        }
        else if (cmp > 0)
        {
            t = removeNode(root->right, value);
            root->right = t;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            BSTNode* minNode;
            minNode = Min(root->right);
            root->value = minNode->value;
            t = removeNode(root->right, minNode->value);
            root->right = t;
        }
        else
        { 
            BSTNode* nodeToDelete = root;
            if (root->left == NULL) 
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            else
                root = NULL;

            delete nodeToDelete;
        }
        return root;
    }

    void inOrder(BSTNode* root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }

    void preOrder(BSTNode* root)
    {
        if (root == NULL)
            return;
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(BSTNode* root)
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }

    void traversalDescendingOrder(BSTNode* root)    //Inverse of Inorder Treversal
    {
        if (root == NULL)
            return;
        traversalDescendingOrder(root->right);
        cout << root->value << " ";
        traversalDescendingOrder(root->left);
    }

    BSTNode* Max(BSTNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->right == NULL)
        {
            return root;
        }
        else
        {
            Max(root->right);
        }
    }

    BSTNode* Min(BSTNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            return root;
        }
        else
        {
            Min(root->left);
        }
    }

    int height(BSTNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight <= rightHeight)
        {
            return rightHeight + 1;
        }
        else
        {
            return leftHeight + 1;
        }
    }

    bool isBalanced(BSTNode* root)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return true;
        }
        if (isBalanced(root->right) == false)
        {
            return false;
        }
        if (isBalanced(root->right) == false)
        {
            return false;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int height = leftHeight - rightHeight;
        if (height == -1 || height == 0 || height == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printLevelOrder(BSTNode* root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printGivenLevel(root, i);
    }

    void printGivenLevel(BSTNode* root, int level)
    {
        if (root == NULL)
            cout << "Tree is Empty!" << endl;
            return;
        if (level == 1)
            cout << root->value << " ";
        else if (level > 1)
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    void RotationCheck(BSTNode* root)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return;
        }

        int Balance = height(root->left) - height(root->right);

        cout << root->value << " (Balance Factor " << Balance << ")\n";

        RotationCheck(root->left);
        RotationCheck(root->right);

    }

    int getData()
    {
        return value;
    }

    BSTNode* getLeft()
    {
        return left;
    }

    BSTNode* getRight()
    {
        return right;
    }
};

class Tree
{
    BSTNode* root;

public:
    Tree()
    {
        root = NULL;
    }

    void inOrder()
    {
        root->inOrder(root);
    }

    void postOrder()
    {
        root->postOrder(root);
    }

    void preOrder()
    {
        root->preOrder(root);
    }

    BSTNode* getRoot()
    {
        return root;
    }

    void insert(int data)
    {
        root = root->insert(root, data);
    }

    void removeNode(int data)
    {
        root->removeNode(root, data);
    }

    int Max()
    {
        return root->Max(root)->getData();
    }

    int Min()
    {
        return root->Min(root)->getData();
    }

    void search(int data)
    {
        root->search(root, data);
    }

    int height()
    {
        return root->height(root);
    }

    bool isBalanced()
    {
        return root->isBalanced(root);
    }

    void printLevelOrder()
    {
        root->printLevelOrder(root);
    }

    void traversalDescendingOrder()
    {
        root->traversalDescendingOrder(root);
    }

    void RotationCheck()
    {
        root->RotationCheck(root);
    }
};

int main()
{
    Tree T;
    int choice;

    do
    {
        cout << "\n[1] Add Node in Tree " << endl;
        cout << "[2] Search Value in Tree." << endl;
        cout << "[3] Delete Node from the Tree." << endl;
        cout << "[4] Print Tree in Pre - Order." << endl;
        cout << "[5] Print Tree in In - Order." << endl;
        cout << "[6] Print Tree in Post - Order." << endl;
        cout << "[7] Find Maximum Value." << endl;
        cout << "[8] Find Minimum Value." << endl;
        cout << "[9] Find Height of the Tree." << endl;
        cout << "[10] Check the Tree Balance." << endl;
        cout << "[11] Display the tree data in level order." << endl;
        cout << "[12] Display Traversal Descending Order" << endl;
        cout << "[13] AVL Rotation Identifier" << endl;
        cout << "[14] Exit\n ";
        cout << "\nEnter Your Choice:";
        cin >> choice;

        int value;
        switch (choice)
        {
        case 1:
            cout << "Enter the value:";
            cin >> value;
            T.insert(value);
            break;
        case 2:
            cout << "Enter the value:";
            cin >> value;
            T.search(value);
            break;
        case 3:
            cout << "Enter the value:";
            cin >> value;
            T.removeNode(value);
            break;
        case 4:
            T.preOrder(); break;
        case 5:
            T.inOrder(); break;
        case 6:
            T.postOrder(); break;
        case 7:
            cout << "Maximum Value in the Tree is " << T.Max();
            break;
        case 8:
            cout << "Minimum Value in the Tree is " << T.Min();
            break;
        case 9:
            cout << "Height of Tree is " << T.height();
            break;
        case 10:
            if (T.isBalanced())
            {
                cout << "\nTree is Balanced.\n";
            }
            else
            {
                cout << "\nTree is not Balanced.\n";
            }
            break;
        case 11:
            T.printLevelOrder();
            break;
        case 12:
            T.traversalDescendingOrder();
            break;
        case 13:
            T.RotationCheck();
            break;
        case 14:
            break;
        } 
    } while (choice < 0 || choice>0);

    return 0;
}