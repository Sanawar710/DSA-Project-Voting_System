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

// string voterFile,
void processVote(string candidateFile, string voteLogFile)
{
    string voterID, candidateID;
    // int voterIndex = -1, candidateIndex = -1;

    // Input voter ID (CNIC)
    cout << "Enter your CNIC (Voter ID): ";
    cin >> voterID;

    bool isValidVoter = searchbyID("Voters.txt", stoll(voterID));

    // Validate voter ID
    if (!isValidVoter)
    {
        cout << "\nYou are not registered to vote or your CNIC is invalid.\n";
        return;
    }

    // Check if the voter has already voted
    if (searchbyID(voteLogFile, stoll(voterID)))
    {
        cout << "You have already voted.\n";
        return;
    }

    // Display the list of candidates
    cout << "Candidates:\n";
    viewInfo(candidateFile); // Display candidate list using the viewInfo function

    // Input candidate ID (CNIC)
    cout << "Enter the CNIC of the candidate you want to vote for: ";
    cin >> candidateID;

    bool isValidCandidate = searchbyID("Candidates.txt", stoll(candidateID));
    // Validate candidate ID
    if (!isValidCandidate)
    {
        cout << "Invalid candidate CNIC.\n";
        return;
    }

    // Log the vote
    if (saveInfo(voteLogFile, "Voter", stoll(voterID))) // Add a placeholder for voter logging
    {
        cout << "Your vote has been cast successfully!\n";
    }
    else
    {
        cout << "Error: Unable to record your vote.\n";
    }
}