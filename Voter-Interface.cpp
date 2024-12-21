#include <iostream>
#include "Save-Information.cpp"
#include "Queues.cpp"
#include "Hashing.cpp"
#include "Binary-Search-Tree.cpp"
#include "Singly-Linked-List.cpp"
#include "Cast-Vote.cpp"

using namespace std;

const int TableSize = 10; // Max size of information that we can store in the hash table
// Global Objects
HashMap Voter_Table(TableSize);
BST *Voter_Records;
// Define the circular queue for voter information
const int QueueCapacity = 100;           // Set capacity for the queue
CircularQueue VoterQueue(QueueCapacity); // Circular queue for storing voters

class VoterInterface
{
public:
    void Menu()
    {
        // Menu for the voters to choose from the options
        cout << "\nVoting System Voter Menu:\n"
             << "1) Cast Vote\n"
             << "2) Register Yourself\n"
             << "3) Unregister Yourself\n"
             << "4) Exit\n"
             << endl;
    }

    void addVoter(Singlelinklist *&head, string name, long long int &CNIC)
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
            cout << name << " with CNIC " << CNIC << " has been registered successfully." << endl;
        }
        else
        {
            cout << "Queue is full. Cannot enqueue voter." << endl;
        }
    }

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
            cout << "Voter with CNIC " << CNIC << " has been unregistered successfully." << endl;
        }
        else
        {
            cout << "Voter with CNIC " << CNIC << " not found in the queue." << endl;
        }
    }

    void castVote(long long int CNIC)
    {
        if (isValidVoter("Voters.txt", CNIC))
        {
            processVote("Candidates.txt", "VotingLog.txt");
        }
        else
        {
            cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
        }
    }
};