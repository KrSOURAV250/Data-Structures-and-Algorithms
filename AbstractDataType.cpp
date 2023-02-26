#include <iostream>
using namespace std;
class myArry
{
    int tSize, uSize;
    int *ptr;

public:
    void createArry(int ts, int us)
    {
        tSize = ts;
        uSize = us;
        ptr = new int[ts];
    }
    void setData()
    {
        for (int i = 0; i < uSize; i++)
        {
            cout << "Enter Element No. " << i << endl;
            cin >> ptr[i];
        }
    }
    void getData()
    {
        for (int i = 0; i < uSize; i++)
        {
            cout << "The Element No. " << i << " is : " << (ptr[i]) << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    myArry m1;
    m1.createArry(1, 3);
    m1.setData();
    m1.getData();

    return 0;
}
