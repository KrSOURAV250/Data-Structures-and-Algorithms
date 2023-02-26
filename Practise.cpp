#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void selectionSort(int *arr, int size)
{
    int index = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int smallElement = INT_MAX;
        for (int j = i; j < size; j++)
            if (smallElement > arr[j])
            {
                smallElement = arr[j];
                index = j;
            }
        if (index > i)
            swap(arr[i], arr[index]);
    }
}
int binarySearch(int *arr, int size, int key)
{
    int f = 0, e = size - 1, m = 0, i = 0;
    while (f <= e)
    {
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
    return -1;
}
void bubbleSort(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void insertionSort(int *arr, int size) // Correct, But Do it Again
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        for (j; arr[j] > current && j >= 0; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = current;
    }
}
void maxOfIndex(int *arr, int size)
{
    int mx = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx << " ";
    }
    cout << endl;
}
void printSubArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            for (int k = i; k < j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
}
void mergep(int *arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *na1 = new int[n1];
    int *na2 = new int[n2];
    for (int i = 0; i < n1; i++)
        na1[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        na2[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (na1[i] <= na2[j])
        {
            arr[k] = na1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = na2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = na1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = na2[j];
        j++;
        k++;
    }
    delete[] na1;
    delete[] na2;
}
void mergeSortP(int *arr, int l, int r)
{
    if (l != r)
    {
        int mid = (l + r) / 2;
        mergeSortP(arr, l, mid);
        mergeSortP(arr, mid + 1, r);
        mergep(arr, l, mid, r);
    }
}
int piFunc(int *arr, int l, int r)
{
    int i = l - 1, pelement = arr[l];
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pelement)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSortP(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int pi = piFunc(arr, l, r);
    quickSortP(arr, l, pi - 1);
    quickSortP(arr, pi + 1, r);
}
int main(int argc, char const *argv[])
{
    int arr[] = {25, 14, 36, 74, 85, 96, 52, 63, 41, 17, 28, 93, 82, 71, 39};
    // int arr[] = {25, 14, 36, 74, 85, 96, 52, 63, 41, 0, 17, 28, 93, 82, 71, 39};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // int arr[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // printArray(arr, 15);
    // selectionSort(arrr, 10);
    // bubbleSort(arr, 15);
    // insertionSort(arr, 15);
    // printArray(arr, 15);
    // maxOfIndex(arr, 15);
    // printSubArray(arr, 15);
    // printArray(arr, 15);
    // int a = binarySearch(arrr, 10, 25);
    // cout << "The Key is at : " << a << endl;
    // string s = "l pur.com";
    // getline(cin, s);
    // cout << s << endl;
    // s.append("FFFF");
    // s.assign("Chal Changa Fer");
    // cout << s.at(1) << endl;
    // cout << s.capacity() << endl;
    // string s = "NipponIndia";

    // cout << s.find("In") << endl;
    // s.insert(6, "World");
    // cout << s << endl;
    // cout << s.size() << endl;
    // cout << s.length() << endl;
    // for(auto x:s)
    // cout<<x<<", ";
    // cout << s.substr(6, 8);
    // string ss = "295";
    // int x = stoi(ss);
    // cout << x + 5 << endl;
    // int z = 250;
    // // string st = to_string(z);
    // // for (auto y : st)
    // cout << to_string(z) + "2" << endl;
    // string s1 = "mnbvcxzasdfghjklpoiuytrewq";
    // sort(s1.begin(), s1.end());
    // cout << s1 << endl;

    // s = "soURaV";
    // printArray(arr, 15);
    // mergeSortP(arr, 0, 15);
    // quickSortP(arr, 0, 14);
    // printArray(arr, 15);
    vector<int> *v = new vector<int>;
    pair<int, string> *p = new pair<int, string>[4];
     

    return 0;
}
