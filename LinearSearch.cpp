#include <iostream>
using namespace std;
int lSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return i + 1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[30] = {25, 96, 84, 55, 75, 25, 61, 53, 96, 33};
   
    cout << "The Index is : " << lSearch(arr, 53, 10);

    return 0;
}
