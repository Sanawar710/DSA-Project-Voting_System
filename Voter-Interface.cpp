#include <iostream>
#include "Save-Information.cpp"
#include "Hashing.cpp"
#include "Binary-Search-Tree.cpp"
#include "Singly-Linked-List.cpp"
#include "Cast-Vote.cpp"

using namespace std;

const int TableSize = 10; // Max size of information that we can store in the hash table
// Global Objects
HashMap Voter_Table(TableSize);
BST *Voter_Records;

class VoterInterface
{
public:
    void Menu()
    {
        // Menu for the voters to choose from the options
        cout << "\nVoting System Voter Menu:\n"
             << "1)Cast Vote\n"
             << "2)Register Yourself\n"
             << "3)Unregister Yourself\n"
             << "4)Exit\n"
             << endl;
    }

    /// @brief This function is used to add the voter's information in the linked list, hash table and the text file
    /// @param head The starting node of the linked list
    /// @param name The name of the file
    /// @param CNIC The CNIC / National ID of the user
    void addVoter(Singlelinklist *&head, string name, long long int &CNIC)
    {
        Voter_Table.registeration("Voters.txt", name, CNIC);
        head->insert(name, CNIC); // Inserting the pair of name and CNIC at the end of the list
        saveInfo("Voters.txt", name, CNIC);
        Voter_Records->insertRecord(Voter_Records, CNIC);

        cout << name << " with CNIC " << CNIC << " has been registered successfully." << endl;
    }

    /// @brief This function is used to delete the voter's information from the linked list, hash table and the text file
    /// @param head The starting node of the linked list
    /// @param name The name of the file
    /// @param CNIC The CNIC / National ID of the user
    void deleteVoter(Singlelinklist *&head, long long int &CNIC)
    {
        head->deletion(CNIC);
        deleteInfo("Voters.txt", CNIC);
        Voter_Table.delete_by_CNIC(CNIC);
        Voter_Records->deleteRecord(Voter_Records,CNIC);
    }

    /// @brief This function is used to cast vote to the candidates
    /// @param CNIC The CNIC / National ID of the user
    void castVote(long long int CNIC)
    {
        if (isValidVoter(CNIC))
        {
            processVote("Candidate.txt", "VotingLog.txt");
        }
    }
};