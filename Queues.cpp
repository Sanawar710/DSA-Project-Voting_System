#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;
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

    void enqueue(int value) // Function to add an element to the queue
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }

        Node *newNode = new Node(value);

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

    int dequeue() // Function to remove an element from the queue
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
            Node *temp = front;
            value = temp->data;
            front = front->next;
            rear->next = front; // Maintain circular link
            delete temp;
        }

        size--;
        return value;
    }
};