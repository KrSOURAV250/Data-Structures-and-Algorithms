#include <iostream>
using namespace std;
int pass = 0;
void insertionSort(int *ptr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = ptr[i];
        int bi = i - 1;
        while (ptr[bi] > current && bi > -1)
        {
            ptr[bi + 1] = ptr[bi];
            bi--;
        }
        ptr[bi + 1] = current;
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
    int n = 6;
    int arr[n] = {99, 66, 88, 22, 33, 44, 55};
    //  int arr[n] = {11, 13, 9, 12, 10, 8};
    //int arr[n] = {7, 5, 7, 7, 7, 7, 7};
    cout << "Arry Before Insertion Sort : ";
    display(arr, n);
    insertionSort(arr, n);
    cout << endl
         << "Arry After Insertion Sort : ";
    display(arr, n);
    cout << endl
         << "The No. of Pass is : " << pass << endl;
    return 0;
}
