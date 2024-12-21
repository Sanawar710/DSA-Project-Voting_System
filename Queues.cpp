#ifndef CIRCULAR_QUEUE_H // Checks if circular queue is defined or not
#define CIRCULAR_QUEUE_H // If it is not defined, this statement will define it

#include <iostream>

using namespace std;

// Struct to hold voter information
struct Voter
{
    string name;
    long long int CNIC;

    // Constructor for easier initialization
    Voter(string n = "", long long int c = 0) : name(n), CNIC(c) {}
};

class Node_CQ
{
public:
    Voter data; // Store voter information
    Node_CQ *next;

    // Constructor to initialize a node
    Node_CQ(Voter value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularQueue
{
private:
    Node_CQ *front;
    Node_CQ *rear;
    int size;     // Current number of elements in the queue
    int capacity; // Maximum capacity of the queue

public:
    CircularQueue(int cap) // Constructor to initialize the circular queue
    {
        front = nullptr;
        rear = nullptr;
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

    Voter Front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return Voter(); // Return an empty voter struct
        }
        return front->data; // Return the voter at the front
    }

    void EnQueue(Voter value) // Function to add a voter to the queue
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value.name << "." << endl;
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
        cout << value.name << " with CNIC " << value.CNIC << " enqueued to the queue." << endl;
    }

    Voter DeQueue() // Function to remove a voter from the queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return Voter(); // Return an empty voter struct
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
            rear->next = front; // Maintain circular link
            delete temp;
        }

        size--;
        return value;
    }
};

#endif