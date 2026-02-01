// Implementation file for singly linked list
#include "Singly-Linked-List.h"

#include <iostream>

// Constructor
Singlelinklist::Singlelinklist()
{
    head = NULL;
}

void Singlelinklist::insert(std::string name, long long int CNIC)
{
    Node_LinkedList *newNode = new Node_LinkedList;

    newNode->name = name;
    newNode->CNIC = CNIC;
    newNode->votes = 1; // Initialize votes to 1
    newNode->next = head;

    head = newNode;
}

bool Singlelinklist::deletion(long long int CNIC)
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

void Singlelinklist::traversal()
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