#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
};
class queue
{
public:
    node *front = NULL;
    node *rear = NULL;
};
void display(queue *q)
{
    node *n = q->front;
    // n = q->front;
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    delete n;
}
bool isFull(queue *q)
{
    node *n = new node;
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
bool isEmpty(queue *q)
{

    if (q->front == NULL)
    {
        return 1;
    }
    return 0;
}
void enQueue(queue *q, int value)
{
    if (isFull(q))
    {
        cout << "Queue OverFlow";
    }
    else if (q->front == NULL)
    {
        node *ptr = new node;
        ptr->data = value;
        ptr->next = NULL;
        q->front = q->rear = ptr;
    }
    else
    {
        node *ptr = new node;
        ptr->data = value;
        ptr->next = NULL;
        q->rear->next = ptr;
        q->rear = ptr;
    }
}
void deQueue(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue UnderFlow";
    }
    else
    {
        node *ptr = q->front;
        q->front = q->front->next;
        delete ptr;
    }
}
int main(int argc, char const *argv[])
{
    queue *q = new queue;

    enQueue(q, 88);
    enQueue(q, 85);
    enQueue(q, 83);
    enQueue(q, 81);
    deQueue(q);
    enQueue(q, 82);
    // deQueue(q);
    // deQueue(q);
    // deQueue(q);
    // deQueue(q);
    // deQueue(q);

    display(q);
    // cout << isEmpty(q);
    return 0;
}