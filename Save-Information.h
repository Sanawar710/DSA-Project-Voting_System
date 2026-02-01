#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <string>

bool saveInfo(std::string filename, std::string name, long long int CNIC);

bool deleteInfo(std::string filename, long long int CNIC);

bool searchbyID(std::string filename, long long int CNIC);

void viewInfo(std::string filename);

#endif // FILEHANDLING_H
// Header wrapper for Save-Information.cpp
#ifndef SAVE_INFORMATION_H
#define SAVE_INFORMATION_H

#include "Save-Information.cpp"

#endif // SAVE_INFORMATION_H
