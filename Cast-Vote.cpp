#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <iostream>
#include <unistd.h>
#include "Save-Information.cpp"
#include "Admin-Interface.cpp"

using namespace std;

// Helper function to validate if a voter ID exists in the given file
bool isValidVoter(const string &filename, long long int voterID)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        if (stoll(line) == voterID)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void processVote(string candidatesFile, string votingLogFile)
{
    long long int CNIC;
    string candidateName;

    cout << "Enter the name of the candidate you want to vote for: " << endl;
    cin >> candidateName;
    cout << "Enter the name of the candidate you want to vote for: ";
    cin >> CNIC;

    // Find candidate in the hash table
    for (int i = 0; i < TableSize; i++)
    {
        searchbyID(candidatesFile, CNIC);

        Node_LinkedList *current = Voter_Table.table[i].head;
        while (current != NULL)
        {
            if (current->CNIC == CNIC)
            {
                current->votes++; // Increment vote count
                saveInfo(votingLogFile, candidateName, current->CNIC);
                cout << "Your vote has been successfully cast for " << CNIC << "." << endl;
                return;
            }
            current = current->next;
        }
    }

    cout << "Candidate not found! Please check the name and try again." << endl;
}

#endif