#include <iostream>
using namespace std;
class circularQueue
{
public:
    int front = -1, rear = -1, count = 0, size;
    int *arr;
};
void display(circularQueue *q)
{
    int i = q->front;
    for (int j = 0; j < q->count; j++)
    {
        cout << q->arr[i] << " ";
        i = (i + 1) % q->size;
    }
}
bool isFull(circularQueue *q)
{
    if (q->count == q->size)
    {
        return 1;
    }
    return 0;
}
bool isEmpty(circularQueue *q)
{
    if (q->count == 0)
    {
        return 1;
    }
    return 0;
}
void enQueue(circularQueue *q, int value)
{
    if (isFull(q))
    {
        cout << "Queue OverFlow" << endl;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front++;
        q->rear++;
        q->arr[q->rear] = value;
        q->count++;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        q->count++;
    }
}
void deQueue(circularQueue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue UnderFlow" << endl;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        q->count--;
    }
}
int main(int argc, char const *argv[])
{
    circularQueue qq;
    circularQueue *q = &qq;
    q->size = 6;
    q->arr = new int[q->size];
    enQueue(q, 54);
    enQueue(q, 55);
    enQueue(q, 56);
    enQueue(q, 57);
    enQueue(q, 58);
    enQueue(q, 59);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    enQueue(q, 59);
    enQueue(q, 59);
    enQueue(q, 59);

    // enQueue(q, 52);
    display(q);
    cout << endl;
    cout << "Full :   " << isFull(q) << endl;
    cout << "Empty :   " << isEmpty(q) << endl;

    return 0;
}
