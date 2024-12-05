#include <iostream>
#include <string>
using namespace std;

// Function to check if a voter ID is valid
bool isValidVoter(int voterIDs[], int count, int id)
{
    for (int i = 0; i < count; ++i)
    {
        if (voterIDs[i] == id)
            return true;
    }
    return false;
}

// Function to process a vote from a voter
void processVote(int voterIDs[], int voterCount, bool voted[], int candidateIDs[], int candidateVotes[], int candidateCount)
{
    int voterID, candidateID;

    // Input voter ID
    cout << "Enter your voter ID: ";
    cin >> voterID;

    // Validate voter ID
    if (!isValidVoter(voterIDs, voterCount, voterID))
    {
        cout << "You are not registered to vote.\n";
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
            candidateVotes[i]++;
            validCandidate = true;
            break;
        }
    }

    if (validCandidate)
    {
        voted[voterIndex] = true;
        cout << "Your vote has been cast successfully!\n";
    }
    else
    {
        cout << "Invalid candidate ID.\n";
    }
}

// Main function for voting system
int main()
{
    // Registered voters
    const int voterCount = 5;
    int voterIDs[voterCount] = {101, 102, 103, 104, 105};
    bool voted[voterCount] = {false};

    // Candidates and their votes
    const int candidateCount = 3;
    int candidateIDs[candidateCount] = {201, 202, 203};
    int candidateVotes[candidateCount] = {0};

    // Input number of voters participating
    int numVoters;
    cout << "Enter the number of voters who want to vote: ";
    cin >> numVoters;

    // Process votes for each voter
    for (int i = 0; i < numVoters; ++i)
    {
        cout << "\nVoting for voter " << i + 1 << ":\n";
        processVote(voterIDs, voterCount, voted, candidateIDs, candidateVotes, candidateCount);
    }

    // Display final voting results
    cout << "\nFinal Vote Count:\n";
    for (int i = 0; i < candidateCount; ++i)
    {
        cout << "Candidate ID: " << candidateIDs[i] << ", Votes: " << candidateVotes[i] << "\n";
    }

    return 0;
}