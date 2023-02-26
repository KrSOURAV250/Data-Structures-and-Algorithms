#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
};
void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void insertAtFirst(node *&head, int e)
{
    node *ptr = new node;
    ptr->prev = NULL;
    ptr->data = e;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}
void insertAtEnd(node *head, int e)
{
    node *p = head;
    node *ptr = new node;
    ptr->data = e;
    ptr->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
}
void insertAfterNode(node *prevNode, int key)
{
    node *ptr = new node;
    ptr->data = key;
    ptr->prev = prevNode;
    ptr->next = prevNode->next;
    prevNode->next->prev = ptr;
    prevNode->next = ptr;
}
void insertAtIndex(node *head, int index, int key)
{
    node *p = head;
    node *ptr = new node;
    ptr->data = key;
    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
    }
    ptr->prev = p;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
}
void deleteFirstNode(node *&head)
{
    node *ptr = head;
    head->next->prev = NULL;
    head = head->next;
    delete ptr;
}
void deleteIndexNode(node *head, int index)
{
    node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
}
void deleteLastNode(node *head)
{
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    delete ptr;
}
void deleteValueNode(node *&head, int value)
{
    node *ptr = head;
    while (ptr->data != value && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == value)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
    else
        cout << "The Value is Not Present Here!!!" << endl;
}
int search(node *head, int value)
{
    int i = 1;
    node *ptr = head;
    while (ptr->data != value && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr->data != value)
    {
        return -1;
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
    head->prev = NULL;
    head->data = 66;
    head->next = head1;
    head1->prev = head;
    head1->data = 67;
    head1->next = head2;
    head2->prev = head1;
    head2->data = 68;
    head2->next = head3;
    head3->prev = head2;
    head3->data = 69;
    head3->next = head4;
    head4->prev = head3;
    head4->data = 70;
    head4->next = NULL;
    display(head);
    cout << endl;
    // insertAtFirst(head, 43);
    // insertAtEnd(head, 100);
    // insertAfterNode(head2, 100);
    // insertAtIndex(head, 4, 100);
    // deleteFirstNode(head);
    // deleteIndexNode(head, 3);
    // deleteLastNode(head);
    // deleteValueNode(head, 68);
    cout << "The Value is At Index: " << search(head, 69) << endl;
    display(head);
    return 0;
}