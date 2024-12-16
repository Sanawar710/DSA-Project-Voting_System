#include <iostream>

using namespace std;

struct Node_LinkedList
{
    string name;
    long long int CNIC;
    Node_LinkedList *next;
};

class Singlelinklist
{
public:
    Node_LinkedList *head;
    Node_LinkedList *tail;

    Singlelinklist() // Constructor
    {
        head = NULL;
        tail = NULL;
    }

    /// @brief Inserts the values at the start of the list
    /// @param name The name of the person
    /// @param CNIC The CNIC/National ID of the person
    void insert(string name, long long int CNIC)
    {
        Node_LinkedList *newNode = new Node_LinkedList;

        newNode->name = name;
        newNode->CNIC = CNIC;
        newNode->next = head;

        head = newNode;
    }

    /// @brief This is a general function for deletion. It performs deletion for all the cases
    /// @param CNIC This is the CNIC / National ID of the person (for whom we want to delete information)
    /// @return Returns NULL if the list is empty. Else, head
    Node_LinkedList *deletion(long long int CNIC)
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
        Node_LinkedList *current = new Node_LinkedList;
        Node_LinkedList *prev = new Node_LinkedList;

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

    /// @brief The function for traversal in list
    void traversal() // Function for traversal
    {
        Node_LinkedList *temp = new Node_LinkedList;
        temp = head;

        int count = 1;

        do
        {

            cout << count << ")" << "Name: " << temp->name << "\nCNIC: " << temp->CNIC << endl;
            cout << endl;

            temp = temp->next;
            count++;
        } while (temp->next == NULL);
    }
};