#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

#include <iostream>

struct Node_LinkedList
{
    std::string name;
    long long int CNIC;
    int votes = 0;
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
    void insert(std::string name, long long int CNIC)
    {
        Node_LinkedList *newNode = new Node_LinkedList;

        newNode->name = name;
        newNode->CNIC = CNIC;
        newNode->votes = 1; // Initialize votes to 1
        newNode->next = head;

        head = newNode;
    }

    /// @brief This is a general function for deletion. It performs deletion for all the cases
    /// @param CNIC This is the CNIC / National ID of the person (for whom we want to delete information)
    /// @return Returns false if the list is empty or deletion is not successful.
    bool deletion(long long int CNIC)
    {
        if (head == NULL)
        {
            return false; // Returns false if the list is empty
        }

        if (head->CNIC == CNIC)
        {
            Node_LinkedList *temp = head;
            head = head->next;
            delete temp;
            return true;
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
            return false;
        }

        // Freeing the connection and deleting the node
        prev->next = current->next;
        delete current;
        return true;
    }

    /// @brief The function for traversal in list
    void traversal()
    {
        Node_LinkedList *temp = head;

        if (temp == NULL)
        {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        int count = 1;

        while (temp != NULL)
        {
            std::cout << count << ") Name: " << temp->name << "\nCNIC: " << temp->CNIC << std::endl;
            std::cout << std::endl;

            temp = temp->next;
            count++;
        }
    }
};

#endif