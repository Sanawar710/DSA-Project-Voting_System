#include "Hashing.h"
#include "Admin-Interface.h"
#include "Voter-Interface.h"
#include "Graphs.h"
#include "Stack.h"
#include "Singly-Linked-List.h"
#include "Queues.h"
#include "Save-Information.h"
#include "Binary-Search-Tree.h"
#include "Cast-Vote.h"
#include "Searching-Algorithms.h"
#include <ctime>

// Global Variable for Deadline
// Initialize to one year from now so voters can use the program without admin first setting a deadline
time_t deadline = time(0) + 31536000;

int main()
{
    // Creating Objects
    AdminInterface A;
    VoterInterface V(10);
    Singlelinklist *Candidates, *Voters;

    std::cout << "Welcome to the Voting System !" << std::endl;

    int choice;

    sleep(1);

    std::cout << "\nDo you want to access the Admin Terminal or the Voter Terminal? (0/1): " << std::endl;
    std::cin >> choice;

    if (choice == 0)
    {
        std::cout << std::endl; // For indentation on terminal

        sleep(1);

        Credentials creds;
        creds = loginTerminal();

        if (A.Authenticate(creds.name, creds.password))
        {
            sleep(1);

            std::cout << "\nLogin Successful\n"
                      << std::endl;

            sleep(1);

            A.Menu();

            int option;

            sleep(1);

            std::cout << "Enter the option you want to choose (on a scale of 1-7): " << std::endl;
            std::cin >> option;

            switch (option)
            {
            case 1:
            {

                deadline = A.deadLine();
                sleep(1);
                std::cout << "You are being redirected to the voter terminal." << std::endl;
                goto voterTerminal;

                break;
            }

            case 2:
            {
                std::string name;
                long long int CNIC;

                std::cin.ignore(); // Clear input buffer

                sleep(1);

                std::cout << "\nEnter the name of the candidate: " << std::endl;

                std::cout << "\nEnter the CNIC of the candidate (without dashes): ";
                std::cin >> CNIC;

                sleep(1);

                A.addCandidates(Candidates, name, CNIC);
                break;
            }

            case 3:
            {
                long long int CNIC;

                sleep(1);

                std::cout << "\nEnter the CNIC of the candidate (without dashes): " << std::endl;
                std::cin >> CNIC;
                A.deleteCandidates(Candidates, CNIC);
                break;
            }

            case 4:
                A.viewCandidates(Candidates);
                break;

            case 5:
                sleep(1);

                std::cout << "Election's Result: \n";
                V.viewResult();

                break;

            case 6:
                sleep(1);

                std::cout << "Voter's Information: " << std::endl;
                A.viewVoters(Voters);

                break;

            case 7:
                sleep(1);

                std::cout << "Exiting the system. Thank you for managing the voting process." << std::endl;
                exit(0);
                break;

            default:
                sleep(1);

                std::cout << "\nYou have entered an invalid input\n"
                          << std::endl;
                break;
            }
        }
    }
    else
    {
        sleep(1);

        std::cout << "\nLogin Failed!" << std::endl;
        std::cout << "Invalid Username or Password\n." << std::endl;
    }
    if (choice == 1)
    {
        sleep(1);

    voterTerminal:
        bool condition = true;
        time_t currentTime;

        // Enforcing the deadline
        while (condition)
        {
            currentTime = time(0); // Continuously checks the current time

            if (currentTime >= deadline)
            {
                std::cout << "\nDeadline reached! Elections are now closed." << std::endl;
                condition = false;
                exit(0);
            }

            V.Menu();

            int option;

            sleep(1);

            std::cout << "Enter the option you want to choose (on a scale of 1-5): " << std::endl;
            std::cin >> option;

            switch (option)
            {
            case 1:
            {
                long long int CNIC;

                sleep(1);

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

                std::cin.ignore();
                std::cout << "\nEnter your name: \n";
                std::getline(std::cin, name);

                sleep(1);

                std::cout << "\nEnter your CNIC: \n";
                std::cin >> CNIC;

                sleep(1);

                V.addVoter(Voters, name, CNIC);

                break;
            }

            case 3:
            {
                std::string name;
                long long int CNIC;

                sleep(1);

                std::cout << "\nEnter your CNIC: \n";
                std::cin >> CNIC;

                V.deleteVoter(Voters, CNIC);

                break;
            }

            case 4:

                break;
            case 5:

                sleep(1);

                std::cout << "Exiting the system. Thank you for voting." << std::endl;
                exit(0);
                break;

            default:

                sleep(1);

                std::cout << "You have entered an invalid input" << std::endl;
                break;
            }
        }
    }
    return 0;
}