#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <iostream>
#include <unistd.h> // For sleep function
#include <ctime>
#include "Singly-Linked-List.h"
#include "Hashing.h"
#include "Searching-Algorithms.h"

// Forward declarations and extern globals
extern HashMap Candidate_Table;

struct Credentials // Used when we will use credentials from the user
{
	std::string name;
	std::string password;
};

inline Credentials loginTerminal()
{
	Credentials cred;

	std::cin.ignore();
	std::cout << "Enter your Username: " << std::endl;
	std::getline(std::cin, cred.name);

	sleep(1);
	std::cout << "\nEnter your Password: " << std::endl;
	std::getline(std::cin, cred.password);

	return cred; // Returns username and password as a structure
}

inline void EasterEgg()
{
	sleep(1);

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
	bool Authenticate(std::string username, std::string Password)
	{
		bool found = linearSearch(admins, 3, username);

		if (found && Password == password)
			return true;
		else if (username == "Sanawar" || username == "Fatima" || username == "Abdul Wadood")
			EasterEgg();

		return false;
	}

	void Menu()
	{
		sleep(1);
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

	time_t deadLine()
	{
		float hours;
		sleep(1);
		std::cout << "\nEnter the Deadline for Ending Elections (in hours): ";

	negativeTime:
		std::cin >> hours;

		if (hours <= 0)
		{
			sleep(1);
			std::cout << "\nTime must be greater than 0. Please re-enter: ";
			goto negativeTime;
		}

		time_t currentTime = time(0);
		time_t deadlineTime = currentTime + (hours * 3600);

		return deadlineTime;
	}

	void addCandidates(Singlelinklist *&head, std::string name, long long int CNIC)
	{
		Candidate_Table.registeration("Candidates.txt", name, CNIC);

		head->insert(name, CNIC);
		sleep(1);
		std::cout << name << " with CNIC " << CNIC << " has been registered successfully." << std::endl;
	}

	void deleteCandidates(Singlelinklist *head, long long int CNIC)
	{
		head->deletion(CNIC);
		deleteInfo("Voters.txt", CNIC);
		Candidate_Table.delete_by_CNIC(CNIC);
	}

	void viewCandidates(Singlelinklist *head)
	{
		int option;

		sleep(1);
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

	void viewVoters(Singlelinklist *head)
	{
		int option;
		sleep(1);
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
			sleep(1);
			std::cout << "You have entered an invalid option." << "\nPlease re-enter the option." << std::endl;
			goto invalidOption;
		}
	}
};

#endif // ADMININTERFACE_H
