#include <iostream>
using namespace std;

class lList
{
public:
    string data;
    lList *next;
};

void display(lList *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main(int argc, char const *argv[])
{
    lList *node = new lList[3];
    node[0].data = "Kr.";
    node[0].next = &node[1];
    node[1].data = "SOURAV";
    node[1].next = &node[2];
    node[2].data = "Team";
    node[2].next = NULL;
    display(node);

    return 0;
}
