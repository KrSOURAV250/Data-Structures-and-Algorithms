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
lList *insertAtFirst(lList *nnode, string e)
{
    lList *ptr = new lList;
    ptr->data = e;
    ptr->next = nnode;
    return ptr;
}
lList *insertAtIndex(lList *ptr, int index, string key)
{
    lList *nnode = new lList;
    nnode->data = key;
    for (int i = 0; i < index - 2; i++)
    {
        ptr = ptr->next;
    }
    nnode->next = ptr->next;
    ptr->next = nnode;

    return ptr;
}
void insertAtEnd(lList *ptr, string key)
{
    lList *nnode = new lList;
    nnode->data = key;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = nnode;
    nnode->next = NULL;
}
void insertAfterIndex(lList *prevNode, string key)
{
    lList *nnode = new lList;
    nnode->data = key;
    nnode->next = prevNode->next;
    prevNode->next = nnode;
}
int main(int argc, char const *argv[])
{
    lList *node = new lList;
    lList *node1 = new lList;
    lList *node2 = new lList;
    lList *node3 = new lList;
    lList *node4 = new lList;
    node->data = "Kr.";
    node->next = node1;
    node1->data = "SOURAV";
    node1->next = node2;
    node2->data = "in";
    node2->next = node3;
    node3->data = "House";
    node3->next = NULL;

    // node = insertAtFirst(node, "Something");
    insertAtIndex(node, 4, "The");
    insertAtEnd(node, "Something");
    insertAfterIndex(node1, "Legend");
    display(node);

    return 0;
}
