#ifndef CASTVOTE_H
#define CASTVOTE_H

#include <string>

bool isValidVoter(const std::string &filename, long long int voterID);

void processVote(std::string candidatesFile, std::string votingLogFile);

#endif // CASTVOTE_H
