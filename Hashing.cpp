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

    /// @brief This function is used to delete information of the candidate from the hash table and the file
    /// @param filename The name of the file in which we store the information
    /// @param CNIC The national id / CNIC of the candidate
    /// @return Returns true if deletion is successful, else false
    bool deleteInfo(string filename, long long int CNIC)
    {
        ifstream file(filename); // Opening the original file
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file " << filename << endl;
            return false; // Returning false if the file cannot be opened
        }

        ofstream tempFile("modifiedCandidates.txt"); // Temporary file to store the modified information
        if (!tempFile.is_open())
        {
            file.close();
            return false; // Returning false if the temporary file cannot be created
        }

        string line;
        bool found = false; // Flaging to check if the CNIC is found

        while (getline(file, line)) // Reading each line from the file
        {
            istringstream info(line); // 'istringstream' to parse the line
            string name, strCNIC;

            getline(info, name, ','); // Extracting name
            getline(info, strCNIC);   // Extracting CNIC

            long long int cnic = stoll(strCNIC); // Converting CNIC from string to long long int

            if (CNIC == cnic)
            {
                found = true; // Marking as found if the CNIC matches
            }
            else
            {
                tempFile << line << endl; // Writing the line to the temporary file if CNIC doesn't match
            }
        }

        file.close();
        tempFile.close();

        if (found)
        {
            if (remove(filename.c_str()) != 0) // Deleting the original file
            {
                return false;
            }

            if (rename("modifiedCandidates.txt", filename.c_str()) != 0) // Renaming the temporary file
            {
                return false;
            }

            return true; // Returning true if deletion and renaming are successful
        }
        remove("modifiedCandidates.txt"); // Cleaning up temporary file if CNIC not found
        return false;                     // Return false if CNIC not found
    }
};

#endif