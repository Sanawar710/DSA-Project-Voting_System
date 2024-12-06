#include <iostream>
#include <map> // Included to use unordered maps.
               // Unordered map is similar to Python's dictionary
               // It stores data in key-value pair. We can access a value against a key
using namespace std;

struct Candidate
{
    string name;
    int votes;
    long long int CNIC;
};

map<int, Candidate> candidateTable;

bool registerCandidate(map<int, Candidate> &candidateTable, string name , int id)
{
    // Check if a candidate with the same ID already exists
    if (candidateTable.find(id) != candidateTable.end())
    {
        cout << "Candidate with ID " << id << " already exists!" << endl;
        return false;
    }

    // Insert data if it does not exist already
    Candidate newCandidate = {name, 0, id};
    candidateTable[id] = newCandidate;

    cout << "Candidate " << name << " registered successfully!" << endl;

    return true;
}

void displayCandidates(map<int, Candidate> &candidateTable)
{
    map<int, Candidate>::iterator iter; // Initialized an iterator to traverse throught the map

    for (iter = candidateTable.begin(); iter != candidateTable.end(); iter++)
    {
        cout << "Candidate's Name: " << iter->second.name
             << "\nCandidate's ID: " << iter->second.CNIC<<endl;
    }
}