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

    Node *deletion(long long int CNIC) // General function for deletion
    {
        if (head == NULL)
        {
            return NULL; // Returns NULL if the list is empty
        }

        else if (head->CNIC == CNIC)
        {
            head = head->next; // Head becomes the second node if the 'CNIC to be deleted' is at the head
            return head;
        }

        // If the element is not stored by the head node and the list is not also empty
        Node *current = new Node;
        Node *prev = new Node;

        current = head;
        prev = NULL;

        while (current != NULL && current->CNIC != CNIC)
        {
            prev = current;
            current = current->next;
        }

        // Freeing the connection
        prev->next = current->next;
        return head;
    }

    void traversal() // Function for traversal
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