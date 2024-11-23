#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Credentials // Used when we will use credentials from the user
{
    string name;
    string password;
};

class Admin
{
public:
    bool Authenicate(string username, string Password)
    {
        vector<string> admins = {"admin1", "admin2", "admin3"}; // Stores the usernames of all the admins
        string password = "ABC";

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
             << "\n2) Add Candidate to Election"
             << "\n3) Cast Vote"
             << "\n4) Change Election's Deadline"
             << "\n5) View Election Results"
             << "\n6) Exit"
             << "\nSelect an option: ";
    }
};

Credentials loginTerminal()
{
    Credentials cred;

    cout << "Enter your Username: " << endl;
    cin >> cred.name;

    cout << "Enter your Password: " << endl;
    cin >> cred.password;

    return cred;
}

int main()
{
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

    return 0;
}