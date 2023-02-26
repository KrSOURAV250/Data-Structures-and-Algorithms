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
int insert(int arr[], int index, int uSize)
{
    if (index > uSize)
    {
        return -1;
    }
    else

        for (int i = uSize; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
    return 0;
}
int main(int argc, char const *argv[])
{
    int arr[30] = {66, 36, 52, 88, 22, 9, 75, 36};
    display(arr, 8);
    insert(arr, 3, 8);
    arr[2] = 55;
    display(arr, 9);

    return 0;
}
