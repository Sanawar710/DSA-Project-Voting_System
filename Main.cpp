// Included the cpp files which include functions for our voting system
#include "Hashing.cpp"
#include "Admin-Interface.cpp"
#include "Graphs.cpp"
#include "Stack.cpp"
#include "Singly-Linked-List.cpp"
#include "Queues.cpp"
#include "Sorting-Algorithms.cpp"
#include "Sorting-Votes.cpp"
#include "Save-Information.cpp"
#include "Binary-Search-Tree.cpp"
#include "Cast-Vote.cpp"
#include "Searching-Algorithms.cpp"

time_t deadline; // Global Variable for Setting Deadline

int main()
{
    // Creating Objects
    AdminInterface A;
    Singlelinklist *Candidates, *Voters;

    cout << "Welcome to the Voting System !" << endl;

    int choice;

    cout << "\nDo you want to access the Admin Terminal or the Voter Terminal? (0/1): " << endl;
    cin >> choice;

    if (choice == 0)
    {
        cout << endl; // For indentation on terminal

        Credentials creds;
        creds = loginTerminal();

        if (A.Authenicate(creds.name, creds.password))
        {
            cout << "\nLogin Successful\n"
                 << endl;
            A.Menu();

            int option;

            cout << "Enter the option you want to choose (on a scale of 1-10): " << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                break;

            case 2:
            {
                string name;
                long long int CNIC;

                cin.ignore(); // Clear input buffer

                cout << "Enter the name of the candidate: ";
                getline(cin, name); // Used to take input name (used incase if some one uses a space in their name)

                cout << "\nEnter the CNIC of the candidate (without dashes): ";
                cin >> CNIC;

                A.addCandidates(Candidates, name, CNIC);
                break;
            }

            case 3:
                long long int CNIC;

                cout << "\nEnter the CNIC of the candidate (without dashes): ";
                cin >> CNIC;
                A.deleteCandidates(Candidates, CNIC);
                break;

            case 4:
                deadline = A.deadLine(); // Later used while casting votes when the election is started
                break;

            case 5:
                A.viewCandidates(Candidates);
                break;

            case 6:
                cout << "Election's Result: \n";
                A.viewResult();
                break;

            case 7:
                cout << "Voter's Information: " << endl;
                A.viewVoters(Voters);
                break;

            case 8:
                cout << "Exiting the system. Thank you for managing the voting process." << endl;
                break;

            default:
                break;
            }
        }
        else
        {
            cout << "\nLogin Failed" << endl;
        }
    }
    else if (choice == 1)
    {
        Credentials creds;
        loginTerminal();
    }

    return 0;
}