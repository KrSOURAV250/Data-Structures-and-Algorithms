#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top = -1;
    char *arr;
};
bool isEmpty(stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    return false;
}
bool isFull(stack *s)
{
    if (s->top == s->size)
    {
        return true;
    }
    return false;
}
void push(stack *s, char ch)
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
void pop(stack *s)
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
int checkParenthesis(stack *s, string str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty(s))
            {
                cout << "Invalid Parenthesis" << endl;
                return 0;
            }
            else
            {
                if (!(str[i] == ')' && s->arr[s->top] == '(') && !(str[i] == ']' && s->arr[s->top] == '[') && !(str[i] == '}' && s->arr[s->top] == '{'))
                {
                    cout << "Invalid Parenthesis" << endl;
                    return 0;
                }
                else
                {
                    pop(s);
                }
            }
        }
    }
    if (s->top == -1)
    {
        cout << "Valid Parenthesis" << endl;
    }
    else
        cout << "Invalid Parenthesis" << endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    // string s = "7-(8(3*9)+11+12))-8)";
    string s = " ";
    stack *st = new stack;
    st->size = s.length();
    st->arr = new char[st->size];
    checkParenthesis(st, s);
    return 0;
}