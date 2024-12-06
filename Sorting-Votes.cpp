#include <iostream>

using namespace std;

void bubbleSort(string names[], int votes[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (votes[j] < votes[j + 1])
            {
                // Descending order
                // Swap votes
                int tempVote = votes[j];
                votes[j] = votes[j + 1];
                votes[j + 1] = tempVote;

                // Swap names
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}

void displayResult(string names[], int votes[], int size)
{
    // Display results
    cout << "Ranked Candidates:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << i + 1 << ". " << names[i] << " - " << votes[i] << " votes" << endl;
    }
}

int main()
{
    // Arrays to hold candidate names and votes
    string names[] = {"Alice", "Bob", "Charlie"};
    int votes[] = {120, 150, 90};
    int n = 3; // Number of candidates

    // Sort candidates using bubble sort
    bubbleSort(names, votes, n);
    displayResult(names, votes, n);
    return 0;
}