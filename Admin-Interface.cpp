#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <iostream>
#include <unistd.h> // For sleep function
#include <ctime>
#include "Singly-Linked-List.cpp"
#include "Hashing.cpp"
#include "Searching-Algorithms.cpp"

const int tableSize = 10; // Max size of information that we can store in the hash table
HashMap Candidate_Table(tableSize);

struct Credentials // Used when we will use credentials from the user
{
    std::string name;
    std::string password;
};

/// @brief This function is used to input the username and the password of the user
/// @return Returns the username and password as structure to the 'authenticate' function in 'Admin' class
Credentials loginTerminal()
{
    Credentials cred;

    std::cin.ignore();
    std::cout << "Enter your Username: " << std::endl;
    std::getline(std::cin, cred.name);

    sleep(3);
    std::cout << "\nEnter your Password: " << std::endl;
    std::getline(std::cin, cred.password);

    return cred; // Returns username and password as a structure
}
void EasterEgg()
{
    sleep(3);

    std::cout << "\nEasteregg found!" << std::endl;
    std::cout << "\n    ******    " << std::endl;
    std::cout << "  **      **  " << std::endl;
    std::cout << " **        ** " << std::endl;
    std::cout << "**          **" << std::endl;
    std::cout << "**          **" << std::endl;
    std::cout << " **        ** " << std::endl;
    std::cout << "  **      **  " << std::endl;
    std::cout << "    ******    " << std::endl;
    exit(0);
}

class AdminInterface
{
private:
    // Stored the username and password of admins for security purposes
    std::string admins[3] = {"admin1", "admin2", "admin3"};
    std::string password = "ABC";

public:
    /// @brief This function is used to verify the username and password entered by the user
    /// @param username Username entered by the user or the admin
    /// @param Password Password entered by the user or the admin
    /// @return Return true if username and password is verified. Otherwise, false
    bool Authenticate(std::string username, std::string Password)
    {
        bool found = linearSearch(admins, 3, username);

        if (found && Password == password)
            return true;
        else if (username == "Sanawar" || username == "Fatima" || username == "Abdul Wadood")
            EasterEgg();

        return false; // Executes in the case if the username and password do not match with the one in the array
    }

    /// @brief The function to display the menu for admin terminal
    void Menu()
    {
        sleep(3);
        // Menu for the admin to choose from the options
        std::cout << "\nVoting System Admin Menu:"
                  << "\n1) Start Election"
                  << "\n2) Add Candidate to Elections"
                  << "\n3) Delete Candidate from Elections"
                  << "\n4) View Candidate's Information"
                  << "\n5) View Voter's Information"
                  << "\n6) View Election Results"
                  << "\n7) Exit"
                  << std::endl;
    }

    /// @brief This function is used to implement and enforce deadline. Needs a little modification right now.
    /// @return Returns the deadline time as entered by the admin
    time_t deadLine()
    {
        float hours;
        sleep(3);
        std::cout << "\nEnter the Deadline for Ending Elections (in hours): ";

    negativeTime: // The control will be redirected to this label if the entered input of time is negative
        std::cin >> hours;

        // Validating the input
        if (hours <= 0)
        {
            sleep(3);
            std::cout << "\nTime must be greater than 0. Please re-enter: ";
            goto negativeTime; // Returns the control to the label 'negativeTime'
        }

        time_t currentTime = time(0);                       // Getting current system time
        time_t deadlineTime = currentTime + (hours * 3600); // Adding input hours in seconds

        return deadlineTime;
    }

    /// @brief This function is used to add the information of the new candidates in the system
    /// @param Candidates Accepts the pair of name and CNIC as a pair in list. Will later use the node of list created by structure or classes
    void addCandidates(Singlelinklist *&head, std::string name, long long int CNIC)
    {
        Candidate_Table.registeration("Candidates.txt", name, CNIC); // Registers the candidate in hash table in a sorted manner

        head->insert(name, CNIC); // Inserting the pair of name and CNIC at the end of the list
        sleep(3);
        std::cout << name << " with CNIC " << CNIC << " has been registered successfully." << std::endl;
    }

    /// @brief This function implements the functionality to delete the information of a certain candidates
    /// @param Candidates Accepts the pair of name and CNIC as a pair in list. Will later use the node of list created by structure or classes
    /// @param name It is name of the candidate whoose information we want to delete
    /// @param CNIC It is CNIC/National ID of the candidate whoose information we want to delete
    void deleteCandidates(Singlelinklist *head, long long int CNIC)
    {
        head->deletion(CNIC);                 // Delete information from the linked list
        deleteInfo("Voters.txt", CNIC);       // Delete information from the file
        Candidate_Table.delete_by_CNIC(CNIC); // Delete information from the Hash Table
    }

    /// @brief The function to view the candidates' information
    /// @param head THe head of the list in which we have stored the information of the candidates
    void viewCandidates(Singlelinklist *head)
    {
        int option;

        sleep(3);
        std::cout << "Do you want to view information through Linked List or File? (0/1)" << std::endl;
    invalidOption:
        std::cin >> option;

        if (option == 0)
        {
            head->traversal();
        }
        else if (option == 1)
        {
            viewInfo("Candidates.txt");
        }
        else
        {

            std::cout << "You have entered an invalid option." << "\nPlease re-enter the option." << std::endl;
            goto invalidOption;
        }
    }

    /// @brief The function to view the information of the voters
    /// @param head The head of the list in which the information of the voters is stored
    void viewVoters(Singlelinklist *head)
    {
        int option;
        sleep(3);
        std::cout << "Do you want to view information through Linked List or File? (0/1)" << std::endl;
    invalidOption:
        std::cin >> option;

        if (option == 0)
        {
            head->traversal();
        }
        else if (option == 1)
        {
            viewInfo("Voters.txt");
        }
        else
        {
            sleep(3);
            std::cout << "You have entered an invalid option." << "\nPlease re-enter the option." << std::endl;
            goto invalidOption;
        }
    }
};

#endif