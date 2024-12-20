#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <iostream>
#include <unistd.h>
#include "Save-Information.cpp"

using namespace std;

// Helper function to validate if a voter ID exists in the voter list
bool isValidVoter(long long int voterID)
{
    bool found = searchbyID("Voters.txt", voterID);

    if (found == true)
        return true;

    return false;
}

void processVote(string candidateFile, string voteLogFile)
{
    string voterID, candidateID;

    // Input voter ID (CNIC)
    cout << "Enter your CNIC (Voter ID): ";
    cin >> voterID;

    bool isValidVoter = searchbyID("Voters.txt", stoll(voterID));

    // Validate voter ID
    if (!isValidVoter)
    {
        sleep(3);

        cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
        return;
    }

    // Check if the voter has already voted
    if (searchbyID(voteLogFile, stoll(voterID)))
    {
        sleep(3);
        cout << "You have already voted.\n";
        return;
    }

    sleep(3);
    // Display the list of candidates
    cout << "Candidates:\n";
    viewInfo(candidateFile); // Display candidate list using the viewInfo function

    sleep(3);
    // Input candidate ID (CNIC)
    cout << "Enter the CNIC of the candidate you want to vote for: ";
    cin >> candidateID;

    bool isValidCandidate = searchbyID("Candidates.txt", stoll(candidateID));
    // Validate candidate ID
    if (!isValidCandidate)
    {
        sleep(3);
        cout << "Invalid candidate CNIC.\n";
        return;
    }

    // Log the vote
    if (saveInfo(voteLogFile, "Voters.txt", stoll(voterID))) // Add a placeholder for voter logging
    {
        sleep(3);
        cout << "Your vote has been cast successfully!\n";
    }
    else
    {
        sleep(3);
        cout << "Error: Unable to record your vote.\n";
    }
}

#endif