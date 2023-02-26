#include <iostream>
using namespace std;
class DEQueue
{
public:
    int front = -1, rear = -1;
    int *arr;
};
void display(DEQueue *dq)
{
    for (int i = dq->front; i <= dq->rear; i++)
    {
        cout << dq->arr[i] << " ";
    }
}
bool isFull(DEQueue *dq)
{
    if (dq->rear == 5)
    {
        return 1;
    }
    return 0;
}
bool isEmpty(DEQueue *dq)
{
    if (dq->rear == -1 && dq->front == -1)
    {
        return 1;
    }
    return 0;
}
void enQueueRear(DEQueue *dq, int val)
{
    if (isFull(dq))
    {
        cout << " Queue OverFlow" << endl;
    }
    else if (dq->rear == -1 && dq->front == -1)
    {
        dq->front++;
        dq->rear++;
        dq->arr[dq->rear] = val;
    }
    else
    {
        dq->rear++;
        dq->arr[dq->rear] = val;
    }
}
void enQueueFront(DEQueue *dq, int val)
{
    if (isFull(dq) && dq->front == -1)
    {
        cout << " Queue OverFlow" << endl;
    }
    else
    {
        dq->front--;
        dq->arr[dq->front] = val;
    }
}
void deQueueFront(DEQueue *dq)
{
    if (isEmpty(dq))
    {
        cout << " Queue UnderFlow" << endl;
    }
    else
    {
        dq->front++;
    }
}
void deQueueRear(DEQueue *dq)
{
    if (isEmpty(dq))
    {
        cout << " Queue UnderFlow" << endl;
    }
    else
    {
        dq->rear--;
    }
}
int main(int argc, char const *argv[])
{
    DEQueue qq;
    DEQueue *dq = &qq;
    dq->arr = new int[6];
    enQueueRear(dq, 63);
    enQueueRear(dq, 64);
    enQueueRear(dq, 65);
    enQueueRear(dq, 66);
    enQueueRear(dq, 67);
    enQueueRear(dq, 68);
    deQueueFront(dq);
    enQueueFront(dq, 99);
    deQueueRear(dq);
    deQueueRear(dq);
    deQueueRear(dq);
    enQueueRear(dq, 63);
    enQueueRear(dq, 64);
    enQueueRear(dq, 65);
    display(dq);

    return 0;
}
