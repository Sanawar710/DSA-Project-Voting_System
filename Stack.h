#ifndef STACK_H
#define STACK_H

#include <string>

struct Candidate
{
    std::string name;
    int votes;

    bool operator<(const Candidate &other) const;
    bool operator>(const Candidate &other) const;
};

struct Node
{
    Candidate data;
    Node *next;
    Node(Candidate c);
};

class Stack
{
private:
    Node *topNode;

public:
    Stack();

    void push(const Candidate &c);

    void pop();

    Candidate top() const;

    bool empty() const;

    void sortStack();

    Candidate findTopCandidate() const;
};

#endif // STACK_H
// Header wrapper for Stack.cpp
#ifndef STACK_H
#define STACK_H

#include "Stack.cpp"

#endif // STACK_H
