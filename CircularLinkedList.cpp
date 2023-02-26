#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void display(node *head)
{
    node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}
void insertAtFirst(node *head, int e)
{
    node *ptr = new node;
    ptr->data = e;
    ptr->next = head->next;
    head->next = ptr;
    node *temp = new node;
    temp->data = ptr->data;
    ptr->data = head->data;
    head->data = temp->data;
    delete temp;
}
void insertAtEnd(node *head, int e)
{
    node *nnode = head;
    node *ptr = new node;
    ptr->data = e;
    while (nnode->next != head)
    {
        nnode = nnode->next;
    }
    ptr->next = head;
    nnode->next = ptr;
}
void insertAfterNode(node *prevNode, int key)
{
    node *ptr = new node;
    ptr->data = key;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}
void insertAtIndex(node *head, int index, int key)
{
    node *ptr = new node;
    ptr->data = key;
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }
    ptr->next = q;
    p->next = ptr;
}
void deleteFirstNode(node *&head)
{
    node *ptr = head;
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    head = head->next;
    delete ptr;
}
void deleteIndexNode(node *head, int index)
{
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete q;
}
void deleteLastNode(node *head)
{
    node *p = head;
    node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    delete q;
}
void deleteValueNode(node *&head, int value)
{
    if (value == head->data)
    {
        deleteFirstNode(head);
    }
    else
    {
        node *p = head;
        node *q = head->next;
        while (q->data != value && q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
            delete q;
        }
    }
}
int search(node *head, int value)
{
    node *ptr = head;
    int i = 1;
    while (ptr->data != value && ptr->next != head)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr->data != value)
    {
        return 0;
    }
    else
        return i;
}
int main(int argc, char const *argv[])
{
    node *head = new node;
    node *head1 = new node;
    node *head2 = new node;
    node *head3 = new node;
    node *head4 = new node;
    head->data = 66;
    head->next = head1;
    head1->data = 67;
    head1->next = head2;
    head2->data = 68;
    head2->next = head3;
    head3->data = 69;
    head3->next = head4;
    head4->data = 70;
    head4->next = head;
    display(head);
    cout << endl;
    // insertAtFirst(head, 55);
    // insertAtEnd(head, 105);
    // insertAfterNode(head, 23);
    // insertAtIndex(head, 4, 295);
    // deleteFirstNode(head);
    // deleteIndexNode(head, 3);
    // deleteLastNode(head);
    // deleteValueNode(head, 66);
    display(head);
    // cout << "The Value is At Index : " << search(head, 68) << endl;
    return 0;
}
