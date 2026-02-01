// Circular Queue implementation
#include "Queues.h"

#include <iostream>

Voter::Voter(std::string n, long long int c) : name(n), CNIC(c) {}

Node_CQ::Node_CQ(Voter value) : data(value), next(nullptr) {}

CircularQueue::CircularQueue(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

bool CircularQueue::isEmpty()
{
    return size == 0;
}

bool CircularQueue::isFull()
{
    return size == capacity;
}

Voter CircularQueue::Front()
{
    if (isEmpty())
    {
        std::cout << "Queue is Empty" << std::endl;
        return Voter();
    }

    return front->data;
}

void CircularQueue::EnQueue(Voter value)
{
    if (isFull())
    {
        std::cout << "Queue is full. Cannot enqueue " << value.name << "." << std::endl;
        return;
    }

    Node_CQ *newNode = new Node_CQ(value);

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    size++;
    std::cout << value.name << " with CNIC " << value.CNIC << " enqueued to the queue." << std::endl;
}

Voter CircularQueue::DeQueue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return Voter();
    }

    Voter value;
    if (front == rear)
    {
        value = front->data;
        delete front;
        front = nullptr;
        rear = nullptr;
    }
    else
    {
        Node_CQ *temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    size--;
    return value;
}