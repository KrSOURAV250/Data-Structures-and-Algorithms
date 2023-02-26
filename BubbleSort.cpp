#include <iostream>
using namespace std;
void display(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << ", ";
    }
}
void bubbleSort(int *arr, int n)
{
}
int main(int argc, char const *argv[])
{
    int n = 7;
    // int arr[n] = {99, 66, 88, 22, 33, 44, 55};
    // int arr[n] = {11, 13, 9, 12, 10, 8};
    int arr[n] = {7, 5, 7, 7, 7, 7, 7};
    cout << "Arry Before Bubble Sort : ";
    display(arr, n);
    bubbleSort(arr, n);
    cout << endl
         << "Arry After Bubble Sort : ";
    display(arr, n);
    cout << endl;
        //  << "The No. of Pass is : " << pass << endl; 
    return 0;
}
