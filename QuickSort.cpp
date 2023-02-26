#include <iostream>
using namespace std;
int pass = 0;
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}
int rightPositionOfPivit(int *arr, int l, int h)
{
    int i = l + 1, j = h, temp;
    do
    {
        while (arr[i] <= arr[l])
        {
            i++;
        }
        while (arr[j] > arr[l])
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int *arr, int low, int high)
{
    int pivit;
    if (low < high)
    {
        pass++;
        pivit = rightPositionOfPivit(arr, low, high);
        quickSort(arr, low, pivit - 1);
        quickSort(arr, pivit + 1, high);
    }
}
int main(int argc, char const *argv[])
{

    // int n = 10, arr[] = {7, 5, 4, 9, 10, 1, 6, 8, 3, 2};
    // int n = 10, arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int n=7, arr[] = {6, 3, 9, 5, 2, 8, 7};
    int n = 5, arr[] = {1, 2, 4, 8, 12};
    display(arr, n);
    quickSort(arr, 0, n - 1);
    cout << endl;
    display(arr, n);
    cout << endl
         << pass;
    return 0;
}
