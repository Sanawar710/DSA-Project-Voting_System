#ifndef CIRCULAR_QUEUE_H // Checks if circular queue is defined or not
#define CIRCULAR_QUEUE_H // If it is not defined, this statement will define it

#include <iostream>
using namespace std;

class Node_CQ {
public:
    int data;
    Node_CQ *next;

    // Constructor to initialize a node
    Node_CQ(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node_CQ *front;
    Node_CQ *rear;
    int size; // Current number of elements in the queue
    int capacity; // Maximum capacity of the queue

public:
    CircularQueue(int cap) // Constructor to initialize the circular queue
    {
        front = NULL;
        rear = NULL;
        size = 0;
        capacity = cap;
    }

    bool isEmpty() // Function to check if the queue is empty
    {
        return size == 0;
    }

    bool isFull() // Function to check if the queue is full
    {
        return size == capacity;
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return false;
        }
        return front->data; // Return the value at the front
    }

    void EnQueue(int value) // Function to add an element to the queue
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }

        Node_CQ *newNode = new Node_CQ(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
            rear->next = front; // Circular link
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular link
        }

        size++;
        cout << value << " enqueued to the queue." << endl;
    }

    int DeQueue() // Function to remove an element from the queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int value;
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
            rear->next = front; // Maintain circular link
            delete temp;
        }

        size--;
        return value;
    }
};

#endif 