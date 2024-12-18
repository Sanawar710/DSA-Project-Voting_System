#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <sstream> // This header file allows us to include 'istringstream' function

using namespace std;

void saveInfo(string filename, string name, long long int CNIC) // A general function to save information in files
{
    ofstream file(filename, ios::app); // Opening the file in append mode

    if (file.is_open())
    {
        file << name << "," << CNIC << endl; // Storing the values in a comma separated format
        file.close();
        cout << "\nCandidate information saved to file successfully.\n";
    }
    else
    {
        cerr << "\nUnable to open file.\n";

        char option;
        do
        {
            cout << "\nDo you want to create a new file with the same name? (y/n): ";
            cin >> option;
        } while (option != 'y' && option != 'n');

        if (option == 'y')
        {
            ofstream new_file(filename);

            if (new_file.is_open())
            {
                new_file << name << "," << CNIC << endl;
                new_file.close();
                cout << "\nNew file created and information saved successfully.\n";
            }
            else
            {
                cerr << "\n Unable to create new file.\n";
            }
        }
    }
}

void deleteInfo(string filename, long long int CNIC)
{
    ifstream file(filename);                               // Opening the original file
    ofstream tempFile("modifiedCandidates.txt", ios::app); // Temporary file to store the modified information

    string line;

    while (getline(file, line)) // Gets information from each line from the file
    {
        istringstream info(line); // 'istring' function allows us to read the file in a formatted way

        string name, strCNIC;

        getline(file, name, ','); // Reads name from the file
        getline(file, strCNIC);   // Reads CNIC from the file

        long long int cnic = stoll(strCNIC); // Converts the data type of 'strCNIC' from 'string' to 'long long int'

        if (CNIC != cnic)
        {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove(filename.c_str());             // Deleting the original file
    rename("temp.txt", filename.c_str()); // Renaming the temporary file to the name of the original file
}

void viewInfo(string filename) // A general function to view information in files
{
    string line; // Helps us to read an entire line from the file

    ifstream file(filename, ios::in); // Opening the file to read information

    cout << " Name   |  CNIC\n";
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
}

#endif