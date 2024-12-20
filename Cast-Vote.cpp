#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <iostream>
#include <unistd.h>
#include "Save-Information.cpp"

using namespace std;

// Helper function to validate if a voter ID exists in the voter list
bool isValidVoter(long long int voterID)
{
    return searchbyID("Voters.txt", voterID);
}

// Function to process a vote
void processVote(string candidateFile, string voteLogFile)
{
    string voterIDStr, candidateIDStr;

    // Input voter ID (CNIC)
    cout << "Enter your CNIC (Voter ID): ";
    cin >> voterIDStr;

    // Validate voter ID input and existence
    long long int voterID;
    try
    {
        voterID = stoll(voterIDStr);
    }
    catch (exception &e)
    {
        cout << "\nInvalid CNIC format. Please enter a valid number.\n";
        return;
    }

    if (!isValidVoter(voterID))
    {
        sleep(3);
        cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
        return;
    }

    // Check if the voter has already voted
    if (searchbyID(voteLogFile, voterID))
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
    cin >> candidateIDStr;

    // Validate candidate ID input and existence
    long long int candidateID;
    try
    {
        candidateID = stoll(candidateIDStr);
    }
    catch (exception &e)
    {
        cout << "\nInvalid candidate CNIC format. Please enter a valid number.\n";
        return;
    }

    if (!searchbyID(candidateFile, candidateID))
    {
        sleep(3);
        cout << "Invalid candidate CNIC.\n";
        return;
    }

    // Log the vote
    if (saveInfo(voteLogFile, voterIDStr, stoll(candidateIDStr)))
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