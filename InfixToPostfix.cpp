#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top = -1;
    char *arr;
};
bool isEmpty(stack *&s)
{
    if (s->top == -1)
    {
        return true;
    }
    return false;
}
bool isFull(stack *&s)
{
    if (s->top == s->size)
    {
        return true;
    }
    return false;
}
void push(stack *&s, char ch)
{
    if (isFull(s))
    {
        cout << "Stack OverFlow" << endl;
    }
    else
    {
        s->arr[s->top + 1] = ch;
        s->top++;
    }
}
void pop(stack *&s)
{
    if (isEmpty(s))
    {
        cout << "Stack UnderFlow" << endl;
    }
    else
    {
        s->top--;
    }
}
int presd(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else
        return 0;
}
void ifToPf(stack *s1, string str)
{
    stack *postfix = new stack;
    postfix->arr = new char[str.size() + 1];

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (presd(str[i]) == 0)
        {
            push(postfix, str[i]);
        }
        else if (presd(str[i]) > presd(s1->arr[s1->top]))
        {
            push(s1, str[i]);
        }
        else if (presd(str[i]) <= presd(s1->arr[s1->top]))
        {
            while (s1->top != -1)
            {
                push(postfix, s1->arr[s1->top]);
                pop(s1);
            }
            push(s1, str[i]);
        }
    }
    while (s1->top != -1)
    {
        push(postfix, s1->arr[s1->top]);
        pop(s1);
    }
    push(postfix, '\0');
    cout << postfix->arr;
    delete postfix;
}
int main(int argc, char const *argv[])
{
      string s = "l+u/n-p*r";
    // answer ->            lun/+pr*-
    //  prefix ->>          -+l/un*pr
    stack *st = new stack;
    st->arr = new char[s.length()];
    cout << s << endl;
    ifToPf(st, s);

    return 0;
}
