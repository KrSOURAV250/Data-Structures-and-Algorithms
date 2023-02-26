#include <iostream>
using namespace std;
void display(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void countSort(int *arr, int n)
{
    int i = 0, j = 0;
    int maxx = INT_MIN;
    for (i = 0; i < n; i++)
    {
        maxx = max(maxx, arr[i]); 
    }
    cout << "The Value of Max is : " << maxx << endl;
    int countArr[maxx];
    for (i = 0; i < maxx; i++)
    {
        countArr[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        countArr[arr[i]] = countArr[arr[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= maxx)
    {
        if (countArr[i] > 0)
        {
            arr[j] = i;
            countArr[i] = countArr[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n = 9;
    int arr[] = {66, 88, 99, 11, 22, 77, 44, 33, 55};
    // int arr[] = {2, 4, 2, 5, 111, 5, 5, 3, 3};

    display(arr, n);
    countSort(arr, n);
    display(arr, n);

    return 0;
}
