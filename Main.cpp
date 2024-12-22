// Included the cpp files which include functions for our voting system
#include "Hashing.cpp"
#include "Admin-Interface.cpp"
#include "Voter-Interface.cpp"
#include "Graphs.cpp"
#include "Stack.cpp"
#include "Singly-Linked-List.cpp"
#include "Queues.cpp"
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

    std::cout << "Welcome to the Voting System !" << std::endl;

    int choice;

    sleep(3);

    std::cout << "\nDo you want to access the Admin Terminal or the Voter Terminal? (0/1): " << std::endl;
    std::cin >> choice;

    if (choice == 0)
    {
        std::cout << std::endl; // For indentation on terminal

        sleep(3);

        Credentials creds;
        creds = loginTerminal();

        if (A.Authenticate(creds.name, creds.password))
        {
            sleep(3);

            std::cout << "\nLogin Successful\n"
                      << std::endl;

            sleep(3);

            A.Menu();

            int option;

            sleep(3);

            std::cout << "Enter the option you want to choose (on a scale of 1-7): " << std::endl;
            std::cin >> option;

            switch (option)
            {
            case 1:
            {

                deadline = A.deadLine();

                std::cout << "You are being redirected to the voter terminal." << std::endl;
                goto voterTerminal;

                break;
            }

            case 2:
            {
                std::string name;
                long long int CNIC;

                std::cin.ignore(); // Clear input buffer

                sleep(3);

                std::cout << "\nEnter the name of the candidate: ";

                std::cout << "\nEnter the CNIC of the candidate (without dashes): ";
                std::cin >> CNIC;

                sleep(3);

                A.addCandidates(Candidates, name, CNIC);
                break;
            }

            case 3:
            {
                long long int CNIC;

                sleep(3);

                std::cout << "\nEnter the CNIC of the candidate (without dashes): ";
                std::cin >> CNIC;
                A.deleteCandidates(Candidates, CNIC);
                break;
            }

            case 4:
                A.viewCandidates(Candidates);
                break;

            case 5:
                sleep(3);

                std::cout << "Election's Result: \n";
                V.viewResult();

                break;

            case 6:
                sleep(3);

                std::cout << "Voter's Information: " << std::endl;
                A.viewVoters(Voters);

                break;

            case 7:
                sleep(3);

                std::cout << "Exiting the system. Thank you for managing the voting process." << std::endl;
                break;

            default:
                sleep(3);

                std::cout << "You have entered an invalid input" << std::endl;
                break;
            }
        }
    }
    else
    {
        sleep(3);

        std::cout << "\nLogin Failed!" << std::endl;
        std::cout << "Invalid Username or Password." << std::endl;
    }
    if (choice == 1)
    {
        sleep(3);

    voterTerminal:
        bool condition = true;
        time_t currentTime;

        // Enforcing the deadline
        while (condition)
        {
            currentTime = time(0); // Continuously checks the current time

            if (currentTime >= deadline)
            {
                std::cout << "Deadline reached! Elections are now closed." << std::endl;
                condition = false;
            }

            V.Menu();

            int option;

            sleep(3);

            std::cout << "Enter the option you want to choose (on a scale of 1-5): " << std::endl;
            std::cin >> option;

            switch (option)
            {
            case 1:
            {
                long long int CNIC;

                sleep(3);

                std::cout << "Enter your CNIC: " << std::endl;
                std::cin >> CNIC;
                std::cin.ignore();

                V.castVote(CNIC);

                break;
            }

            case 2:
            {
                std::string name;
                long long int CNIC;

                std::cout << "\nEnter your name: \n";
                std::getline(std::cin, name);
                std::cin.ignore();

                sleep(3);

                std::cout << "\nEnter your CNIC: \n";
                std::cin >> CNIC;

                sleep(3);

                V.addVoter(Voters, name, CNIC);

                break;
            }

            case 3:
            {
                std::string name;
                long long int CNIC;

                sleep(3);

                std::cout << "\nEnter your CNIC: \n";
                std::cin >> CNIC;

                V.deleteVoter(Voters, CNIC);

                break;
            }

            case 4:

                break;
            case 5:

                sleep(3);

                std::cout << "Exiting the system. Thank you for voting." << std::endl;
                break;

            default:

                sleep(3);

                std::cout << "You have entered an invalid input" << std::endl;
                break;
            }
        }
    }
    return 0;
}