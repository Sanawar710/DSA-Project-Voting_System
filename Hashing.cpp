#include <iostream>
#include <map> // Included to use unordered maps.
               // Unordered map is similar to Python's dictionary
               // It stores data in key-value pair. We can access a value against a key
using namespace std;

struct Candidate3
{
    string name;
    int votes;
    long long int CNIC;
};

// Change the key type of the map to long long int to match CNIC's type
map<long long int, Candidate3> candidateTable;

/// @brief This function is used to insert values in a Hash-Table for Candidates
/// @param candidateTable The table in which we want to insert table
/// @param name The name of the table
/// @param id The national id / CNIC of the candidate
/// @return Returns false if candidate exists already, else true
bool registerCandidate(map<long long int, Candidate3> &candidateTable, string name, long long int id)
{
    // Check if a candidate with the same ID already exists
    if (candidateTable.find(id) != candidateTable.end())
    {
        cout << "Candidate with ID " << id << " already exists!" << endl;
        return false;
    }

    // Insert data if it does not exist already
    Candidate3 newCandidate = {name, 0, id};
    candidateTable[id] = newCandidate;

    cout << "Candidate " << name << " registered successfully!" << endl;

    return true;
}

void displayCandidates(map<long long int, Candidate3> &candidateTable)
{
    map<long long int, Candidate3>::iterator iter; // Initialized an iterator to traverse through the map

    for (iter = candidateTable.begin(); iter != candidateTable.end(); iter++)
    {
        cout << "Candidate's Name: " << iter->second.name
             << "\nCandidate's CNIC: " << iter->second.CNIC << endl;
    }
}