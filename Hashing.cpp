#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include "Save-Information.cpp"
#include "Singly-Linked-List.cpp"

using namespace std;

// struct Candidate3
// {
//     string name;
//     int votes;
//     long long int CNIC;
// };

class HashMap
{
private:
    vector<Singlelinklist> table; // Hash table implemented using a vector of singly linked lists
    int size;                     // Size of the hash table

    /// @brief Hash function to calculate the index
    /// @param CNIC The CNIC of the candidate
    /// @return Returns the hash index
    int hashFunction(long long int CNIC)
    {
        return CNIC % size; // Simple modulus-based hash function
    }

public:
    /// @brief Constructor to initialize the hash table with a fixed size
    /// @param tableSize The size of the table
    HashMap(int tableSize) : size(tableSize)
    {
        table.resize(size); // Initialize the table with empty lists
    }

    /// @brief Registers a candidate in the hash table and verifies against file data
    /// @param name The name of the candidate
    /// @param CNIC The CNIC of the candidate
    /// @return Returns false if the candidate already exists, otherwise true
    bool registerCandidate(string name, long long int CNIC)
    {
        // Check if the candidate exists in the file
        ifstream file("Candidates.txt");
        string line;

        while (getline(file, line))
        {
            istringstream info(line);
            string fileName, fileCNIC;

            getline(info, fileName, ',');
            getline(info, fileCNIC);

            if (stoll(fileCNIC) == CNIC) // Convert file CNIC from string to long long and compare
            {
                cout << "Candidate with CNIC " << CNIC << " already exists in the file!" << endl;
                file.close();
                return false;
            }
        }
        file.close();

        // Checking if the candidate exists in the hash table
        int index = hashFunction(CNIC);
        Node_LinkedList *current = table[index].head;

        while (current != NULL)
        {
            if (current->CNIC == CNIC)
            {
                cout << "Candidate with CNIC " << CNIC << " already exists in the hash table!" << endl;
                return false;
            }
            current = current->next;
        }

        table[index].insert(name, CNIC);
        saveInfo("Candidates.txt", name, CNIC);
        cout << "Candidate " << name << " registered successfully!" << endl;
        return true;
    }

    /// @brief Deletes a candidate from the hash table and the file
    /// @param CNIC The CNIC of the candidate to delete
    void deleteCandidate(long long int CNIC)
    {
        int index = hashFunction(CNIC);

        if (table[index].deletion(CNIC) != NULL)
        {
            cout << "Candidate with CNIC " << CNIC << " deleted successfully from the hash table!" << endl;

            // Assuming deleteInfo returns true if deletion from the file is successful
            if (deleteInfo("candidates.txt", CNIC))
            {
                cout << "Candidate with CNIC " << CNIC << " deleted successfully from the file!" << endl;
            }
            else
            {
                cout << "Failed to delete candidate with CNIC " << CNIC << " from the file!" << endl;
            }
        }
        else
        {
            cout << "Candidate with CNIC " << CNIC << " not found in the hash table!" << endl;
        }
    }
};

#endif