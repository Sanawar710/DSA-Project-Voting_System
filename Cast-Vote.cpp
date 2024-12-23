#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <iostream>
#include <unistd.h>
#include "Save-Information.cpp"
#include "Voter-Interface.cpp"

extern int TableSize;       // Declare TableSize
extern HashMap Voter_Table; // Declare Voter_Table

/// @brief Helper function to validate if a voter ID exists in the given file
/// @param filename The file in which the voter ID is to be searched
/// @param voterID The ID of the voter to be searched
/// @return Returns true if the voter ID is found, else false
bool isValidVoter(const std::string &filename, long long int voterID)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open " << filename << std::endl;
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name, cnicStr;

        // Extract name and CNIC from the CSV line
        if (std::getline(ss, name, ',') && std::getline(ss, cnicStr))
        {
            try
            {
                long long int cnic = std::stoll(cnicStr);
                if (cnic == voterID)
                {
                    file.close();
                    return true;
                }
            }
            catch (const std::invalid_argument &)
            {
                std::cerr << "Error: Invalid CNIC format in file." << std::endl;
                file.close();
                return false;
            }
            catch (const std::out_of_range &)
            {
                std::cerr << "Error: CNIC value out of range in file." << std::endl;
                file.close();
                return false;
            }
        }
    }

    file.close();
    return false;
}

/// @brief The function to check if the voter has already voted
/// @param candidatesFile The file which stores the information of the candidates
/// @param votingLogFile The file which stores the information of the people who have voted
void processVote(std::string candidatesFile, std::string votingLogFile)
{
    long long int CNIC;
    std::string candidateName;

    std::cout << "Enter the name of the candidate you want to vote for: " << std::endl;
    std::getline(std::cin, candidateName);

    std::cout << "Enter the name of the candidate you want to vote for: ";
    std::cin >> CNIC;
    std::cin.ignore();
    // Find candidate in the hash table
    for (int i = 0; i < tableSize; i++)
    {
        searchbyID(candidatesFile, CNIC);

        Node_LinkedList *current = Voter_Table.table[i].head;
        while (current != NULL)
        {
            if (current->CNIC == CNIC)
            {
                current->votes++; // Increment vote count
                saveInfo(votingLogFile, candidateName, current->CNIC);
                std::cout << "Your vote has been successfully cast for " << CNIC << "." << std::endl;
                return;
            }
            current = current->next;
        }
    }

    std::cout << "Candidate not found! Please check the name and try again." << std::endl;
}

#endif