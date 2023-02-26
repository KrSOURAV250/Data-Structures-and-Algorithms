#include <iostream>
using namespace std;
int n = 9;
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left, newArr[n];
    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            newArr[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            newArr[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i <= mid)
    {
        newArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        newArr[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = newArr[i];
    }
}
void mergeSort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main(int argc, char const *argv[])
{

    int arr[] = {55, 44, 99, 11, 22, 66, 77, 33, 88};
    display(arr, n);
    mergeSort(arr, 0, 9);
    cout << endl;
    display(arr, n);
    return 0;
}
