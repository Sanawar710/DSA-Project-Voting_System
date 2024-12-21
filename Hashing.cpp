#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include "Save-Information.cpp"
#include "Singly-Linked-List.cpp"

using std::cout, std::cin, std::endl;

class HashMap
{
public:
    vector<Singlelinklist> table; // Hash table implemented using a vector of singly linked lists
    int size;                     // Size of the hash table

    int getSize()
    {
        return size;
    }

    /// @brief Hash function to calculate the index
    /// @param CNIC The CNIC of the candidate
    /// @return Returns the hash index
    int hashFunction(long long int CNIC)
    {
        return CNIC % size; // Simple modulus-based hash function
    }

    Singlelinklist& getBucket(int index)
    {
        return table[index];
    }

    /// @brief Constructor to initialize the hash table with a fixed size
    /// @param tableSize The size of the table
    HashMap(int tableSize) : size(tableSize)
    {
        table.resize(size); // Initialize the table with empty lists
    }

    /// @brief Registers a person in the hash table and verifies against file data
    /// @param name The name of the candidate
    /// @param CNIC The CNIC of the candidate
    /// @return Returns false if the candidate already exists, otherwise true
    bool registeration(string filename, string name, long long int CNIC)
    {
        // Check if the candidate exists in the file
        ifstream file(filename);
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
        saveInfo(filename, name, CNIC);
        cout << "Registered successfully!" << endl;
        return true;
    }

    bool delete_by_CNIC(long long int CNIC)
    {
        int index = hashFunction(CNIC);

        if (table[index].deletion(CNIC))
            return true;

        return false;
    }
};

#endif