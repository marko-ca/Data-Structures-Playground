#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= N && arr[left] > arr[largest])
        largest = left;
    else largest = i;
    if (right <= N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 ; i > 0; i--)
        max_heapify(arr, N, i);
}


int main()
{
    int const size = 10;
    cout << "The default size of Heap is '10'." << endl;
    int array[size];

    cout << "Enter the value for Root: ";
    cin >> array[1];

    int N = size/ 2;
    for (int i = 1; i < N; i++)
    {
        cout << "Enter the value for Left Node: ";
        cin >> array[2 * i];
        cout << "Enter the value for Right Node: ";
        cin >> array[2 * i + 1];
    }
    //N = sizeof(array) / sizeof(array[0]);
    heapSort(array, N);

    cout << "Max Heap\n";
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;

    return 0;
}