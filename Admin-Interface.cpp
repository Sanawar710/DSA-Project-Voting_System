#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

struct Credentials // Used when we will use credentials from the user
{
    string name;
    string password;
};

Credentials loginTerminal()
{
    Credentials cred;

    cout << "Enter your Username: " << endl;
    cin >> cred.name;

    cout << "Enter your Password: " << endl;
    cin >> cred.password;

    return cred; // Returns username and password as a structure
}

class Admin
{
private:
    // Stored the username and password of admins for security purposes
    vector<string> admins = {"admin1", "admin2", "admin3"}; // Stores the usernames of all the admins
    string password = "ABC";

public:
    bool Authenicate(string username, string Password)
    {
        for (const string &admin : admins) // Iterates through the vector to compare the usernames of the admin
        {
            if (username == admin && Password == password) // Validates the username and password
            {
                return true;
            }
        }
        return false; // Executes in the case if the username and password do not match
    }

    void Menu()
    {
        // Menu for the admin to manage the options
        cout << "Voting System Admin Menu:"
             << "\n1) Start Election"
             << "\n2) Add Candidate to Elections"      // Done
             << "\n3) Delete Candidate from Elections" // Done
             << "\n4) Change Election's Deadline"      // Partly Done
             << "\n5) View Election Results"
             << "\n6) View Candidate's Information"
             << "\n7) Exit" // Will be implemented in main when user enters the input
             << "\nSelect an option: ";
    }

    /// @brief This function is used to implement and enforce deadline. Needs a little modification right now.
    void deadLine()
    {
        float hours;

        cout << "Enter the Deadline for Ending Elections (in hours): ";

    negativeTime: // The control will be redirected to this label if the entered input of time is negative
        cin >> hours;

        // Validating the input
        if (hours <= 0)
        {
            cout << "Time must be greater than 0. Please re-enter: ";
            goto negativeTime; // Returns the control to the label 'negativeTime'
        }

        time_t currentTime = time(0);                       // Getting current system time
        time_t deadlineTime = currentTime + (hours * 3600); // Adding input hours in seconds

        // Enforcing the deadline
        while (true)
        {
            currentTime = time(0); // Continuously checks the current time

            if (currentTime >= deadlineTime)
            {
                cout << "Deadline reached! Elections are now closed." << endl;
                break;
            }
        }
    }

    /// @brief This function is used to add the information of the new candidates in the system
    /// @param Candidates Accepts the pair of name and CNIC as a pair in list. Will later use the node of list created by structure or classes
    void addCandidates(list<pair<string, long long int>> &Candidates)
    {
        string name;
        long long int CNIC;

        cout << "Enter the name of the candidate: ";
        cin >> name;

        cout << endl;

        cout << "Enter the CNIC of the candidate (without dashes): ";
        cin >> CNIC;

        Candidates.push_back(make_pair(name, CNIC)); // Inserting the pair of name and CNIC at the end of the list
    }

    /// @brief This function implements the functionality to delete the information of a certain candidates
    /// @param Candidates Accepts the pair of name and CNIC as a pair in list. Will later use the node of list created by structure or classes
    /// @param name It is name of the candidate whoose information we want to delete
    /// @param CNIC It is CNIC/National ID of the candidate whoose information we want to delete
    void deleteCandidate(list<pair<string, long long int>> &Candidates, string name, long long int CNIC)
    {
        for (auto it = Candidates.begin(); it != Candidates.end(); ++it) // Used an iterator to traverse through the list
        {
            if (it->first == name && it->second == CNIC) // Checks if the record in the list matches with the entered record
            {
                Candidates.erase(it); // Deletes the information of the candidate if the record is found
                cout << "Candidate deleted successfully." << endl;
                return;
            }
        }

        cout << "Candidate not found." << endl;
    }
};

int main()
{
    // Testing

    // Admin A;
    // // A.deadLine();
    // Credentials cred;
    // cred = loginTerminal();

    // if (A.Authenicate(cred.name, cred.password)) // Displays the menu if the login is successful
    // {
    //     A.Menu();
    // }
    // else
    // {
    //     cout << "Login Failed." << endl;
    // }
    // list<pair<string,long long int>> Candidates;
    // A.Menu();
    // A.addCandidates(Candidates);
    return 0;
}