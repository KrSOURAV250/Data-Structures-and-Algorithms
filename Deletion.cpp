#include <iostream>
using namespace std;
void display(int a[], int uSize)
{
    for (int i = 0; i < uSize; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int deletion(int arr[], int index, int uSize)
{
    if (index > uSize)
    {
        return -1;
    }
    else
        for (int i = index; i < uSize; i++)
        {
            arr[i - 1] = arr[i];
        }
    return 0;
}
int main(int argc, char const *argv[])
{
    int arr[30] = {66, 36, 52, 88, 22, 9, 75, 36};
    display(arr, 8);
    deletion(arr, 3, 8);
    display(arr, 7);

    return 0;
}
