// Cast Vote implementation
#include "Cast-Vote.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Save-Information.h"

extern int TableSize;
extern HashMap Voter_Table;

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

void processVote(std::string candidatesFile, std::string votingLogFile)
{
    long long int CNIC;
    std::string candidateName;

    std::cout << "Enter the name of the candidate you want to vote for: " << std::endl;
    std::getline(std::cin, candidateName);

    std::cout << "Enter the name of the candidate you want to vote for: ";
    std::cin >> CNIC;
    std::cin.ignore();

    for (int i = 0; i < TableSize; i++)
    {
        searchbyID(candidatesFile, CNIC);

        Node_LinkedList *current = Voter_Table.table[i].head;
        while (current != NULL)
        {
            if (current->CNIC == CNIC)
            {
                current->votes++;
                saveInfo(votingLogFile, candidateName, current->CNIC);
                std::cout << "Your vote has been successfully cast for " << CNIC << "." << std::endl;
                return;
            }
            current = current->next;
        }
    }

    std::cout << "Candidate not found! Please check the name and try again." << std::endl;
}