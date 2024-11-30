#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class Singlelinklist
{
public:
    Node *head;
    Node *tail;
    Singlelinklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insertastart(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
};