#ifndef VOTERINTERFACE_H
#define VOTERINTERFACE_H

#include <string>
#include "Hashing.h"

class VoterInterface
{
private:
    Hashing candidateTable;

public:
    VoterInterface(int tableSize);

    void Menu();

    void addVoter(class Singlelinklist *&head, std::string name, long long int &CNIC);

    void deleteVoter(class Singlelinklist *&head, long long int &CNIC);

    void castVote(long long int CNIC);

    void viewResult();
};

#endif // VOTERINTERFACE_H
