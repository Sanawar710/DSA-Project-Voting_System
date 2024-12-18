#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

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

    Singlelinklist() // Constructor
    {
        head = NULL;
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

        if (head->CNIC == CNIC)
        {
            Node_LinkedList *temp = head;
            head = head->next; // Head becomes the second node if the 'CNIC to be deleted' is at the head
            delete temp; // Free the memory of the removed node
            return head;
        }

        // If the element is not stored by the head node and the list is not empty
        Node_LinkedList *current = head;
        Node_LinkedList *prev = NULL;

        while (current != NULL && current->CNIC != CNIC)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
        {
            // CNIC not found
            cout << "CNIC not found in the list." << endl;
            return head;
        }

        // Freeing the connection and deleting the node
        prev->next = current->next;
        delete current;
        return head;
    }

    /// @brief The function for traversal in list
    void traversal()
    {
        Node_LinkedList *temp = head;

        if (temp == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        int count = 1;

        while (temp != NULL)
        {
            cout << count << ") Name: " << temp->name << "\nCNIC: " << temp->CNIC << endl;
            cout << endl;

            temp = temp->next;
            count++;
        }
    }
};

#endif 