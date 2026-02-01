#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <string>

struct Node_LinkedList
{
	std::string name;
	long long int CNIC;
	int votes;
	Node_LinkedList *next;
};

class Singlelinklist
{
public:
	Node_LinkedList *head;

	Singlelinklist();

	void insert(std::string name, long long int CNIC);

	bool deletion(long long int CNIC);

	void traversal();
};

#endif // SINGLY_LINKED_LIST_H
