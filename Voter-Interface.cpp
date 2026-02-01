// Voter interface implementation
#include "Voter-Interface.h"

#include <iostream>
#include "Save-Information.h"
#include "Queues.h"
#include "Hashing.h"
#include "Binary-Search-Tree.h"
#include "Singly-Linked-List.h"
#include "Cast-Vote.h"
#include "Graphs.h"
#include "Stack.h"
#include "Admin-Interface.h"

using namespace std;

// Global objects
HashMap Voter_Table(10);
BST *Voter_Records;
const int QueueCapacity = 100;
CircularQueue VoterQueue(QueueCapacity);

void VoterInterface::addVoter(Singlelinklist *&head, std::string name, long long int &CNIC)
{
    Voter_Table.registeration("Voters.txt", name, CNIC);
    head->insert(name, CNIC);
    saveInfo("Voters.txt", name, CNIC);
    Voter_Records->insertRecord(Voter_Records, CNIC);

    if (!VoterQueue.isFull())
    {
        VoterQueue.EnQueue(Voter(name, CNIC));
        std::cout << name << " with CNIC " << CNIC << " has been registered successfully." << std::endl;
    }
    else
    {
        std::cout << "Queue is full. Cannot enqueue voter." << std::endl;
    }
}

void VoterInterface::deleteVoter(Singlelinklist *&head, long long int &CNIC)
{
    head->deletion(CNIC);
    deleteInfo("Voters.txt", CNIC);
    Voter_Table.delete_by_CNIC(CNIC);
    Voter_Records->deleteRecord(Voter_Records, CNIC);

    CircularQueue tempQueue(QueueCapacity);
    bool found = false;

    while (!VoterQueue.isEmpty())
    {
        Voter voter = VoterQueue.DeQueue();
        if (voter.CNIC == CNIC)
        {
            found = true;
        }
        else
        {
            tempQueue.EnQueue(voter);
        }
    }

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

void VoterInterface::castVote(long long int CNIC)
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

void VoterInterface::viewResult()
{
    Stack candidateStack;

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

    candidateStack.sortStack();

    std::cout << "\nElection Results:\n";
    while (!candidateStack.empty())
    {
        Candidate c = candidateStack.top();
        candidateStack.pop();
        std::cout << "Candidate: " << c.name << ", Votes: " << c.votes << std::endl;
    }

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