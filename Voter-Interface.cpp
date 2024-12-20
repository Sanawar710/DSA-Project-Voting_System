#include <iostream>
#include "Save-Information.cpp"
#include "Hashing.cpp"
#include "Singly-Linked-List.cpp"

using namespace std;
const int tableSize = 10; // Max size of information that we can store in the hash table
HashMap Voter_Table(tableSize);

class VoterInterface
{
public:
     void Menu(){

     }
     
    /// @brief This function is used to add the voter's information in the linked list, hash table and the text file
    /// @param head The starting node of the linked list
    /// @param name The name of the file
    /// @param CNIC The CNIC / National ID of the user
    void addVoter(Singlelinklist *&head, string name, long long int CNIC)
    {
        Voter_Table.registeration("Voters.txt", name, CNIC);
        head->insert(name, CNIC); // Inserting the pair of name and CNIC at the end of the list
        saveInfo("Voters.txt", name, CNIC);

        cout << name << " with CNIC " << CNIC << " has been registered successfully." << endl;
    }

    /// @brief This function is used to delete the voter's information from the linked list, hash table and the text file
    /// @param head The starting node of the linked list
    /// @param name The name of the file
    /// @param CNIC The CNIC / National ID of the user
    void deleteVoter(Singlelinklist *&head, string name, long long int CNIC)
    {
        long long int CNIC;

        cout << "\nEnter the CNIC of the candidate (without dashes): ";
        cin >> CNIC;

        head->deletion(CNIC);
        deleteInfo("Voter.txt", CNIC);
        Voter_Table.delete_by_CNIC(CNIC);
    }
};