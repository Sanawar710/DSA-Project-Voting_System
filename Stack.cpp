#include <iostream>
using namespace std;

struct Candidate
{
    string name;
    int votes;

    bool operator<(const Candidate &other) const
    {
        return votes < other.votes; // Compare by votes
    }

    bool operator>(const Candidate &other) const
    {
        return votes > other.votes;
    }
};

// Node structure for the linked list
struct Node
{
    Candidate data;
    Node *next;
    Node(Candidate c) : data(c), next(nullptr) {}
};

// Stack class using linked list
class Stack
{
private:
    Node *topNode;

public:
    Stack() : topNode(nullptr) {}

    // Push an element to the stack
    void push(const Candidate &c)
    {
        Node *newNode = new Node(c);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop an element from the stack
    void pop()
    {
        if (topNode != nullptr)
        {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Get the top element of the stack
    Candidate top() const
    {
        if (topNode != nullptr)
        {
            return topNode->data;
        }
        throw runtime_error("Stack is empty");
    }

    // Check if the stack is empty
    bool empty() const
    {
        return topNode == nullptr;
    }

    // Function to print the stack
    void printStack() const
    {
        Node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->data.name << " - " << temp->data.votes << endl;
            temp = temp->next;
        }
    }

    // Sorting function
    void sortStack()
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

        // Transfer sorted elements back to the original stack
        while (!tempStack.empty())
        {
            push(tempStack.top());
            tempStack.pop();
        }
    }

    // Find and return the candidate with the highest votes
    Candidate findTopCandidate() const
    {
        if (topNode == nullptr)
        {
            throw runtime_error("Stack is empty");
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
};

int main()
{
    Stack candidates;
    int n;

    cout << "Enter the number of candidates: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Candidate c;
        cout << "Enter name for candidate " << i + 1 << ": ";
        cin >> c.name;
        cout << "Enter the number of votes for candidate " << i + 1 << ": ";
        cin >> c.votes;
        candidates.push(c);
    }

    cout << "\nOriginal Stack:\n";
    candidates.printStack();

    // Sort the stack
    candidates.sortStack();

    cout << "\nSorted Stack:\n";
    candidates.printStack();

    // Find and display the candidate with the highest vote score
    Candidate topCandidate = candidates.findTopCandidate();
    cout << "\nCandidate with the highest vote score is: "
         << topCandidate.name << " - " << topCandidate.votes << endl;

    return 0;
}