// Included the cpp files which include functions for our voting system
#include "Hashing.cpp"
#include "Admin-Interface.cpp"
#include "Voter-Interface.cpp"
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

time_t deadline; // Global Variable for Deadline

int main()
{
    // Creating Objects
    AdminInterface A;
    VoterInterface V(10);
    Singlelinklist *Candidates, *Voters;

    cout << "Welcome to the Voting System !" << endl;

    int choice;

    sleep(3);

    cout << "\nDo you want to access the Admin Terminal or the Voter Terminal? (0/1): " << endl;
    cin >> choice;

    if (choice == 0)
    {
        cout << endl; // For indentation on terminal

        sleep(3);

        Credentials creds;
        creds = loginTerminal();

        if (A.Authenticate(creds.name, creds.password))
        {
            sleep(3);

            cout << "\nLogin Successful\n"
                 << endl;

            sleep(3);

            A.Menu();

            int option;

            sleep(3);

            cout << "Enter the option you want to choose (on a scale of 1-8): " << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                // {
                //     // A.startElections();

                //     bool condition = true;
                //     time_t currentTime;
                //     time_t deadlineTime = A.deadLine();

                //     // Enforcing the deadline
                //     while (condition)
                //     {
                //         currentTime = time(0); // Continuously checks the current time

                //         if (currentTime >= deadlineTime)
                //         {
                //             cout << "Deadline reached! Elections are now closed." << endl;
                //             condition = false;
                //         }
                //     }
                // }

                break;
                // }

            case 2:
            {
                string name;
                long long int CNIC;

                cin.ignore(); // Clear input buffer

                sleep(3);

                cout << "Enter the name of the candidate: ";
                getline(cin, name); // Used to take input name (used incase if some one uses a space in their name)
                cin.ignore();

                cout << "\nEnter the CNIC of the candidate (without dashes): ";
                cin >> CNIC;

                sleep(3);

                A.addCandidates(Candidates, name, CNIC);
                break;
            }

            case 3:
                long long int CNIC;

                sleep(3);

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
                sleep(3);

                cout << "Election's Result: \n";
                V.viewResult();

                break;

            case 7:
                sleep(3);

                cout << "Voter's Information: " << endl;
                A.viewVoters(Voters);

                break;

            case 8:
                sleep(3);

                cout << "Exiting the system. Thank you for managing the voting process." << endl;
                break;

            default:
                sleep(3);

                cout << "You have entered an invalid input" << endl;
                break;
            }
        }
        else
        {
            sleep(3);

            cout << "\nLogin Failed!" << endl;
            cout << "Invalid Username or Password." << endl;
        }
    }
    else if (choice == 1)
    {
        sleep(3);

        V.Menu();

        int option;

        sleep(3);

        cout << "Enter the option you want to choose (on a scale of 1-5): " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            long long int CNIC;

            sleep(3);

            cout << "Enter your CNIC: " << endl;
            cin >> CNIC;
            cin.ignore();

            V.castVote(CNIC);

            break;
        }

        case 2:
        {
            string name;
            long long int CNIC;

            cout << "\nEnter your name: \n";
            getline(cin, name);
            cin.ignore();

            sleep(3);

            cout << "\nEnter your CNIC: \n";
            cin >> CNIC;

            sleep(3);

            V.addVoter(Voters, name, CNIC);

            break;
        }

        case 3:
        {
            string name;
            long long int CNIC;

            sleep(3);

            V.deleteVoter(Voters, CNIC);

            break;
        }

        case 4:

            break;
        case 5:

            sleep(3);

            cout << "Exiting the system. Thank you for voting." << endl;
            break;

        default:

            sleep(3);

            cout << "You have entered an invalid input" << endl;
            break;
        }
    }

    return 0;
}