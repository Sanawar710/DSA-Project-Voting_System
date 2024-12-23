#ifndef VOTERINTERFACE_H
#define VOTERINTERFACE_H

#include <iostream>
#include "Save-Information.cpp"
#include "Queues.cpp"
#include "Hashing.cpp"
#include "Binary-Search-Tree.cpp"
#include "Singly-Linked-List.cpp"
#include "Cast-Vote.cpp"
#include "Graphs.cpp"
#include "Stack.cpp"
#include "Admin-Interface.cpp"

using namespace std;

// Global Object
HashMap Voter_Table(10); // This table stores the information of voters
BST *Voter_Records;
const int QueueCapacity = 100;           // Set capacity for the queue
CircularQueue VoterQueue(QueueCapacity); // Circular queue for storing voters

class VoterInterface
{
private:
    HashMap candidateTable;

public:
    VoterInterface(int tableSize) : candidateTable(tableSize) {}

    /// @brief The menu for voter interface
    void Menu()
    {
        // Menu for the voters to choose from the options
        std::cout << "\nVoting System Voter Menu:\n"
                  << "1) Cast Vote\n"
                  << "2) Register Yourself\n"
                  << "3) Unregister Yourself\n"
                  << "4) View Result\n"
                  << "5) Exit\n"
                  << std::endl;
    }

    /// @brief Theis function is used to register voter
    /// @param head The head of the linked list in which we're storing the information
    /// @param name The name of the voter
    /// @param CNIC The CNIC/National ID of the voter
    void addVoter(Singlelinklist *&head, std::string name, long long int &CNIC)
    {
        // Register voter in hash table, linked list, and file
        Voter_Table.registeration("Voters.txt", name, CNIC);
        head->insert(name, CNIC); // Inserting the pair of name and CNIC at the end of the list
        saveInfo("Voters.txt", name, CNIC);
        Voter_Records->insertRecord(Voter_Records, CNIC);

        // Enqueue the voter into the circular queue
        if (!VoterQueue.isFull())
        {
            VoterQueue.EnQueue(Voter(name, CNIC)); // Enqueue voter as a struct
            std::cout << name << " with CNIC " << CNIC << " has been registered successfully." << std::endl;
        }
        else
        {
            std::cout << "Queue is full. Cannot enqueue voter." << std::endl;
        }
    }

    /// @brief Theis function is used to unregister voter
    /// @param head The head of the linked list in which we're storing the information
    /// @param name The name of the voter
    /// @param CNIC The CNIC/National ID of the voter
    void deleteVoter(Singlelinklist *&head, long long int &CNIC)
    {
        head->deletion(CNIC);
        deleteInfo("Voters.txt", CNIC);
        Voter_Table.delete_by_CNIC(CNIC);
        Voter_Records->deleteRecord(Voter_Records, CNIC);

        // Remove voter from the queue if they exist (search the queue for CNIC and dequeue)
        CircularQueue tempQueue(QueueCapacity); // Temporary queue to hold voters while searching
        bool found = false;

        while (!VoterQueue.isEmpty())
        {
            Voter voter = VoterQueue.DeQueue();
            if (voter.CNIC == CNIC)
            {
                found = true; // Found the voter to be deleted
            }
            else
            {
                tempQueue.EnQueue(voter); // Re-enqueue the other voters
            }
        }

        // Restore the original queue from tempQueue
        while (!tempQueue.isEmpty())
        {
            VoterQueue.EnQueue(tempQueue.DeQueue());
        }

        if (found)
        {
            std::cout << "Voter with CNIC " << CNIC << " has been unregistered successfully." << std::endl;
        }
        else
        {
            std::cout << "Voter with CNIC " << CNIC << " not found in the queue." << std::endl;
        }
    }

    /// @brief This function checks if the voter is registered and casts votes
    /// @param CNIC The CNIC/National id of the voter
    void castVote(long long int CNIC)
    {
        if (isValidVoter("Voters.txt", CNIC))
        {
            processVote("Candidates.txt", "VotingLog.txt");
        }
        else
        {
            std::cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
        }
    }

    /// @brief The function to view the result of the Elections
    void viewResult()
    {
        Stack candidateStack;

        // Load candidates from the hash table into the stack
        for (int i = 0; i < candidateTable.getSize(); i++)
        {
            Singlelinklist &bucket = candidateTable.getBucket(i);
            Node_LinkedList *current = bucket.head;

            while (current != nullptr)
            {
                Candidate c;
                c.name = current->name;
                c.votes = current->votes;
                candidateStack.push(c);
                current = current->next;
            }
        }

        // Sort the stack by votes
        candidateStack.sortStack();

        // Display the results
        std::cout << "\nElection Results:\n";
        while (!candidateStack.empty())
        {
            Candidate c = candidateStack.top();
            candidateStack.pop();
            std::cout << "Candidate: " << c.name << ", Votes: " << c.votes << std::endl;
        }

        // Find and display the candidate with the highest votes
        if (!candidateStack.empty())
        {
            Candidate topCandidate = candidateStack.findTopCandidate();
            std::cout << "\nWinner: "
                      << topCandidate.name
                      << " with "
                      << topCandidate.votes
                      << " votes."
                      << std::endl;
        }
        else
        {
            std::cout << "No candidates available to display results." << std::endl;
        }
    }
};

#endif