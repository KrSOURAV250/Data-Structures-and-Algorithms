#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void display(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void deleteFirstNode(node *&head)
{
    node *ptr = head;
    head = head->next;
    delete ptr;
}
void deleteIndexNode(node *&head, int index)
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
void deleteLastNode(node *&head)
{
    node *p = head;
    node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
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
        while (q->data != value && q->next != NULL)
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
    head4->next = NULL;

    display(head);
    cout << endl;

    // deleteValueNode(head, 68);
    deleteFirstNode(head);
    display(head);

    return 0;
}
