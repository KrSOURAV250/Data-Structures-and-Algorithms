#include <iostream>
using namespace std;
int bSearch(int *arr, int key, int size)
{
    int f = 0, e = size - 1, m = 0, i = 0;
    while (f != e)
    {
        i++;
        cout << " II = " << i << endl;
        m = (f + e) / 2;
        if (arr[f] == key)
            return f + 1;
        else if (arr[e] == key)
            return e + 1;
        else if (arr[m] == key)
            return m + 1;
        else if (key < arr[m])
        {
            e = m - 1;
            f++;
        }
        else
        {
            f = m + 1;
            e--;
        }
    }
    cout << "Key Not Found" << endl;
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 6, 9, 10, 13, 15, 20, 25, 29, 30};
    int a = bSearch(arr, 25, 10);
    cout << "The Key is At Index : " << a;
    return 0;
}
