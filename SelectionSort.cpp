#include <iostream>
using namespace std;
int pass = 0;
void selectionSort(int *ptr, int n)
{
    for (int i = 0; i < n -1; i++)
    {
        int keyIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ptr[j] < ptr[keyIndex])
            {
                keyIndex = j;
            }
        }
        int temp = ptr[i];
        ptr[i] = ptr[keyIndex];
        ptr[keyIndex] = temp;
        pass++;
    }
}
void display(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << ", ";
    }
}
int main(int argc, char const *argv[])
{
    int n = 7;
    int arr[n] = {99, 66, 88, 22, 33, 44, 55};
    //  int arr[n] = {11, 13, 9, 12, 10, 8};
    // int arr[n] = {7, 5, 7, 7, 7, 7, 7};
    // int arr[n] = {7, 7, 7, 7, 7, 7, 7};
    cout << "Arry Before  Selection Sort : ";
    display(arr, n);
    selectionSort(arr, n);
    cout << endl
         << "Arry After  Selection Sort : ";
    display(arr, n);
    cout << endl
         << "The No. of Pass is : " << pass << endl;
    return 0;
}
