#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

// size of HashTable
const int TABLE_SIZE = 8;

// prime number used by Division-method
const int PRIME_NO = 251;

int hashFunction(string str)
{
    // func. which accepts a given string from the user and it returns
    // an index corresponding to that string.

    // local variables
    int index = 0; // holds the index assigned to string
    int sum = 0;   // holds the total of ASCII codes of letters

    // Division-method for computing H(k)
    for (int i = 0; i < 3; i++)
    {
        sum += (int)str[i]; // typeCasting (str) to (int)
    }

    // compute index by Division-method
    index = (sum % PRIME_NO) % TABLE_SIZE;

    return index;
}

int midSquare(string str)
{
    // func. which accepts a given string from the user and it returns
    // an index corresponding to that string.

    // local variables
    int index = 0;       // holds the index assigned to string
    int sum = 0;         // holds the total of ASCII codes of letters
    int squaredSum = 0;  // holds the square of total of ASCII codes of letters
    int middleIndex = 0; // holds the middle index of 'squaredSum'
    int midValue = 0;    // holds the middle value of total of Squared value
    string result = "";  // holds the total result
    char r = '\0';

    for (int i = 0; i < 3; i++)
    {
        sum += (int)str[i];
    }

    // calculate square of total of ASCII codes
    squaredSum = pow(sum, 2);

    // convert (int) to (str)
    result = to_string(squaredSum);

    // calculate middleIndex
    middleIndex = result.length() / 2;

    // get the middleIndex value and convert it from (str) to (int)
    midValue = stoi(result.substr(middleIndex - 1, 3));

    // compute index by Division-method
    index = (midValue) % TABLE_SIZE;

    return index;
}

int main()
{
    // local variables
    string userInput = "";
    int hashKey = 0;

    // get input from user
    cout << "Enter a string (3-characters): ";
    getline(cin, userInput);

    // compute hashKey h(k) or index associated with entered string
    hashKey = hashFunction(userInput);

    // display hashKey h(k)
    cout << "HashKey h(k) or index for string \'" << userInput << "\' = " << hashKey << endl;

    // compute hashKey h(k) or index associated with entered string
    hashKey = midSquare(userInput);

    // display hashKey h(k)
    cout << "HashKey h(k) or index for string \'" << userInput << "\' = " << hashKey << endl;

    cout << endl;
    system("pause");
    return 0;
}