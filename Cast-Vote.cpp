#include <iostream>
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

// Function to process a vote from a voter
void processVote(long long int voterIDs[], int voterCount, bool voted[],
                 int candidateIDs[], int candidateVotes[], int candidateCount)
{
    long long int voterID, candidateID;

    // Input voter ID
    cout << "Enter your voter ID: ";
    cin >> voterID;

    // Validate voter ID
    if (!isValidVoter(voterID))
    {
        cout << "\nYou are not registered to vote.\n";
        return;
    }

    // Find the index of the voter
    int voterIndex = -1;
    for (int i = 0; i < voterCount; ++i)
    {
        if (voterIDs[i] == voterID)
        {
            voterIndex = i;
            break;
        }
    }

    // Check if the voter has already voted
    if (voted[voterIndex])
    {
        cout << "You have already voted.\n";
        return;
    }

    // Display the list of candidates
    cout << "Candidates:\n";
    for (int i = 0; i < candidateCount; ++i)
    {
        cout << "Candidate ID: " << candidateIDs[i] << "\n";
    }

    // Input candidate ID
    cout << "Enter the ID of the candidate you want to vote for: ";
    cin >> candidateID;

    // Validate candidate ID and record the vote
    bool validCandidate = false;
    for (int i = 0; i < candidateCount; ++i)
    {
        if (candidateIDs[i] == candidateID)
        {
            candidateVotes[i]++; // Increment the vote count for the candidate
            validCandidate = true;
            break;
        }
    }

    if (validCandidate)
    {
        voted[voterIndex] = true; // Mark the voter as having voted
        cout << "Your vote has been cast successfully!\n";
    }
    else
    {
        cout << "Invalid candidate ID.\n";
    }
}