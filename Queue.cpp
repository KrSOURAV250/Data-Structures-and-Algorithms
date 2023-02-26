#include <iostream>
using namespace std;
class queue
{
public:
    int frontIndex = -1, backIndex = -1, size;
    int *arr;
};
void display(queue *q)
{
    for (int i = q->frontIndex + 1; i <= q->backIndex; i++)
    {
        cout << q->arr[i] << " ";
    }
}
bool isEmpty(queue *q)
{
    if (q->backIndex == -1 && q->backIndex == -1)
    {
        return 1;
    }
    else
        return 0;
}
bool isFull(queue *q)
{
    if (q->backIndex == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(queue *q, int value)
{
    if (isFull(q))
    {
        cout << " Queue OverFlow" << endl;
    }
    else
    {
        q->backIndex++;
        q->arr[q->backIndex] = value;
    }
}
void dequeue(queue *q)
{
    q->frontIndex++;
}
int main(int argc, char const *argv[])
{
    queue *q = new queue;
    q->size = 5;
    q->arr = new int[q->size];

    enqueue(q, 99);
    enqueue(q, 88);
    enqueue(q, 77);
    enqueue(q, 66);
    enqueue(q, 55);

    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    cout << endl;
    enqueue(q, 55);
    display(q);

    return 0;
}
