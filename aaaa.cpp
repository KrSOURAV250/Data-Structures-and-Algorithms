#include <iostream>
using namespace std;
template <class ItemType>
class Queue
{
private:
    int front;
    int rear;
    int maxQue;
    int count;
    ItemType *items;

public:
    Queue();
    ~Queue();
    Queue(int max);
    int IsEmpty() const;
    int IsFull() const;
    void Insert(ItemType newItem);
    void Remove(ItemType &item);
    void insertLeft(ItemType newItem);
    void removeLeft(ItemType &item);
    void insertRight(ItemType newItem);
    void removeRight(ItemType &item);
    void display();
};
template <class ItemType>
Queue<ItemType>::Queue()
{
    maxQue = 501;
    count = 0;
    front = -1;
    rear = -1;
    items = new ItemType[maxQue];
}
template <class ItemType>
Queue<ItemType>::Queue(int max)
{
    maxQue = max + 1;
    count = 0;
    front = -1;
    rear = -1;
    items = new ItemType[maxQue];
}
template <class ItemType>
Queue<ItemType>::~Queue()
{
    delete[] items;
}
template <class ItemType>
int Queue<ItemType>::IsEmpty() const
{
    return (count == 0);
}
template <class ItemType>
int Queue<ItemType>::IsFull() const
{
    return 0;
}