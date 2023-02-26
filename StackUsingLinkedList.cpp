#include <iostream>
using namespace std;
class node
{
public:
    int data = 0;
    node *next = NULL;
};
void display(node *ptr)
{

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
bool isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
bool isFull()
{
    node *ptr = new node;
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void push(node *&top, int value)
{
    if (isFull())
    {
        cout << "Stack OverFlow" << endl;
    }
    else if (top->data == 0)
    {
        top->data = value;
    }
    else
    {
        node *ptr = new node;
        ptr->data = value;
        ptr->next = top;
        top = ptr;
    }
}
void pop(node *&top)
{
    if (isEmpty(top))
    {
        cout << "Stack UnderFlow" << endl;
    }
    else
    {
        node *t = top;
        top = top->next;
        delete t;
    }
}
void peek(node *top, int p)
{
    node *t = top;
   
    for (int i = 0; i < p - 1 && t->next != NULL; i++)
    {
        t = t->next; 
    }
    cout << "The Value at Position " << p << " is : " << t->data << endl;
}
int main(int argc, char const *argv[])
{
    node *top = new node();
    push(top, 99);
    push(top, 92);
    push(top, 97);
    push(top, 10);
    push(top, 101);
    display(top);
    cout << endl;

    peek(top, 2);
    display(top);

    return 0;
}
