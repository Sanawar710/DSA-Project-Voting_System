#include <iostream>
#include <vector>
#include <list>
#include <string>

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
             << "\n2) Add Candidate to Elections"
             << "\n3) Delete Candidate from Elections"
             << "\n4) Change Election's Deadline"
             << "\n5) View Election Results"
             << "\n6) Exit"
             << "\nSelect an option: ";
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