#include <iostream>
#include <unordered_map> // Included to use unordered maps.
                         // Unordered map is similar to Python's dictionary
                         // It stores data in key-value pair. We can access a value against a key
using namespace std;

struct Candidate
{
    string name;
    string party;
    int votes;
    int id;
};

unordered_map<int, Candidate> candidateTable;

bool registerCandidate(unordered_map<int, Candidate> &candidateTable, int id, string name, string party)
{
    // Check if a candidate with the same ID already exists
    if (candidateTable.find(id) != candidateTable.end())
    {
        cout << "Candidate with ID " << id << " already exists!" << endl;
        return false;
    }

    // Insert data if it does not exist already
    Candidate newCandidate = {name, party, 0, id};
    candidateTable[id] = newCandidate;

    cout << "Candidate " << name << " registered successfully!" << endl;

    return true;
}
 
void displayCandidates(unordered_map<int, Candidate> &candidateTable)
{
    unordered_map<int, Candidate>::iterator iter; // Initialized an iterator to traverse throught the map
    
    for (iter = candidateTable.begin(); iter != candidateTable.end(); iter++)
    {
        cout << "Candidate's Name: " << iter->second.name
             << "\nCandidate's ID: " << iter->second.id
             << "\nCandidate's Party: " << iter->second.party << endl;
    }
}

int main()
{
    return 0;
}