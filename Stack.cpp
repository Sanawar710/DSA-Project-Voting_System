// Stack implementation
#include "Stack.h"

#include <stdexcept>

// Candidate operator implementations
bool Candidate::operator<(const Candidate &other) const
{
    return votes < other.votes;
}

bool Candidate::operator>(const Candidate &other) const
{
    return votes > other.votes;
}

// Node constructor
Node::Node(Candidate c) : data(c), next(nullptr) {}

Stack::Stack() : topNode(nullptr) {}

void Stack::push(const Candidate &c)
{
    Node *newNode = new Node(c);
    newNode->next = topNode;
    topNode = newNode;
}

void Stack::pop()
{
    if (topNode != nullptr)
    {
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

Candidate Stack::top() const
{
    if (topNode == nullptr)
    {
        throw std::runtime_error("Stack is empty");
    }
    return topNode->data;
}

bool Stack::empty() const
{
    return topNode == nullptr;
}

void Stack::sortStack()
{
    Stack tempStack;

    while (!empty())
    {
        Candidate current = top();
        pop();

        while (!tempStack.empty() && tempStack.top() > current)
        {
            push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(current);
    }

    while (!tempStack.empty())
    {
        push(tempStack.top());
        tempStack.pop();
    }
}

Candidate Stack::findTopCandidate() const
{
    if (topNode == nullptr)
    {
        throw std::runtime_error("Stack is empty");
    }

    Node *temp = topNode;
    Candidate topCandidate = temp->data;

    while (temp != nullptr)
    {
        if (temp->data.votes > topCandidate.votes)
        {
            topCandidate = temp->data;
        }
        temp = temp->next;
    }

    return topCandidate;
}