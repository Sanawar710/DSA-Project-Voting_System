#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <string>

struct Voter
{
    std::string name;
    long long int CNIC;

    Voter(std::string n = "", long long int c = 0);
};

class Node_CQ
{
public:
    Voter data;
    Node_CQ *next;

    Node_CQ(Voter value);
};

class CircularQueue
{
private:
    Node_CQ *front;
    Node_CQ *rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap);

    bool isEmpty();

    bool isFull();

    Voter Front();

    void EnQueue(Voter value);

    Voter DeQueue();
};

#endif // CIRCULAR_QUEUE_H
