#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <iostream>
#include <unistd.h>
#include "Save-Information.cpp"

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

// Function to process a vote
void processVote(const string &candidateFile, const string &voteLogFile)
{
    string voterIDStr;
    long long int voterID;

    // Input and validate voter ID
    do
    {
        cout << "Enter your CNIC (Voter ID): ";
        cin >> voterIDStr;

        try
        {
            voterID = stoll(voterIDStr);
        }
        catch (const exception &e)
        {
            cout << "\nInvalid CNIC format. Please enter a valid number.\n";
            continue; // Continue to the next iteration of the loop
        }

        if (!isValidVoter("Voters.txt", voterID))
        {
            cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
            continue; // Continue to the next iteration of the loop
        }

        if (isValidVoter(voteLogFile, voterID))
        {
            cout << "\nYou have already voted.\n";
            continue; // Continue to the next iteration of the loop
        }

        break; // Exit the loop if all validations pass

    } while (true);

    // Display the list of candidates
    cout << "\nCandidates:\n";
    // Assuming viewInfo function is defined elsewhere
    viewInfo(candidateFile);

    string candidateIDStr;
    long long int candidateID;

    // Input and validate candidate ID
    do
    {
        cout << "Enter the CNIC of the candidate you want to vote for: ";
        cin >> candidateIDStr;

        try
        {
            candidateID = stoll(candidateIDStr);
        }
        catch (const exception &e)
        {
            cout << "\nInvalid candidate CNIC format. Please enter a valid number.\n";
            continue; // Continue to the next iteration of the loop
        }

        if (!isValidVoter(candidateFile, candidateID))
        {
            cout << "\nInvalid candidate CNIC.\n";
            continue; // Continue to the next iteration of the loop
        }

        break; // Exit the loop if all validations pass

    } while (true);

    // Log the vote
    if (saveInfo(voteLogFile, voterIDStr, candidateID))
    {
        cout << "\nYour vote has been cast successfully!\n";
    }
    else
    {
        cout << "\nError: Unable to record your vote.\n";
    }
}

#endif