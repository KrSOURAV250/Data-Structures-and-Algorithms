#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top = -1;
    int *arr;
};
void display(stack *ptr)
{
    int *a = ptr->arr;
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << *a << " ";
        a++;
    }
}
bool isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
bool isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *p, int val)
{
    stack *ptr = p;
    if (isFull(ptr))
    {
        cout << "Stack OverFlow" << endl;
    }
    else
    {
        ptr->arr[ptr->top + 1] = val;
        ptr->top++;
    }
}
void pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack UnderFlow" << endl;
    }
    else
    {
        ptr->top--;
    }
}
void peek(stack *ptr, int position)
{
    if (position <= 0 || position > ptr->top + 1)
    {
        cout << "Please Pass Valid Position" << endl;
    }
    else
    {
        cout << ptr->arr[position - 1] << endl;
    }
}
int main(int argc, char const *argv[])
{
    stack p;
    stack *s = &p;
    s->size = 6;
    // s->top = -1;
    s->arr = new int[s->size];
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);

    display(s);
    cout << endl;
    // pop(s);
    // pop(s);
    // display(s);

    peek(s, 1);

    return 0;
}