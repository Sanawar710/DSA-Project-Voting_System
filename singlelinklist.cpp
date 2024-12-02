#include <iostream>
using namespace std;

struct Node
{
    string name;
    long long int CNIC;
    int vote;
    Node *next;
};

class Singlelinklist
{
public:
    Node *head;
    Node *tail;

    Singlelinklist() // Constructor
    {
        head = NULL;
        tail = NULL;
    }

    void insertatStart(string name, long long int CNIC, int votes) // Function to insert values
    {
        Node *newNode = new Node;

        newNode->CNIC = CNIC;
        newNode->next = head;
        newNode->vote = votes;

        head = newNode;
    }

    void traversal(Node *head) // Function for traversal
    {
        Node *temp = new Node;
        temp = head;

        int count = 1;

        do
        {

            cout << count << ")" << "Name: " << temp->name << "\nCNIC: " << temp->CNIC << "\nNumber of Votes: " << temp->vote << endl;
            cout << endl;

            temp = temp->next;
            count++;
        } while (temp->next = NULL);
    }
};