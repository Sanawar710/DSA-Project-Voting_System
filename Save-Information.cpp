#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <sstream> // This header file allows us to include 'istringstream' function

using namespace std;

/// @brief A general function to save information in files
/// @param filename The file in which the information is stored
/// @param name The name of the person
/// @param CNIC The CNIC/Natioanl ID of the person
/// @return Return true if the file is opened successfully and information is saved
bool saveInfo(string filename, string name, long long int CNIC)
{
    ofstream file(filename, ios::app); // Opening the file in append mode

    if (file.is_open())
    {
        file << name << "," << CNIC << endl; // Storing the values in a comma separated format
        file.close();

        cout << "\nInformation saved to file successfully.\n";

        return true;
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

                return true;
            }
            else
            {
                cerr << "\n Unable to create new file.\n";
                return false;
            }
        }
    }
    return false;
}

/// @brief A general function to delete information in files
/// @param filename The file in which the information is stored
/// @param name The name of the person
/// @param CNIC The CNIC/Natioanl ID of the person
/// @return Return true if the file is opened successfully and information is saved
bool deleteInfo(string filename, long long int CNIC)
{
    ifstream file(filename); // Opening the original file

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return false; // Return false if the file cannot be opened
    }

    ofstream tempFile("modifiedFile.txt"); // Temporary file to store the modified information

    if (!tempFile.is_open())
    {
        cerr << "Error: Unable to create temporary file." << endl;
        file.close();
        return false; // Return false if the temporary file cannot be created
    }

    string line;
    bool found = false; // Flag to check if the CNIC is found

    while (getline(file, line)) // Read each line from the file
    {
        istringstream info(line); // 'istringstream' to parse the line
        string name, strCNIC;

        getline(info, name, ','); // Extract name
        getline(info, strCNIC);   // Extract CNIC

        long long int id = stoll(strCNIC); // Convert CNIC from string to long long int

        if (CNIC == id)
        {
            found = true; // Mark as found if the CNIC matches
        }
        else
        {
            tempFile << line << endl; // Write the line to the temporary file if CNIC doesn't match
        }
    }

    file.close();
    tempFile.close();

    if (found)
    {
        if (remove(filename.c_str()) != 0) // Delete the original file
        {
            return false;
        }

        if (rename("modifiedFile.txt", filename.c_str()) != 0) // Rename the temporary file
        {
            return false;
        }

        return true; // Return true if deletion and renaming are successful
    }

    remove("modifiedFile.txt"); // Clean up temporary file if CNIC not found
    return false;               // Return false if CNIC not found
}

/// @brief A general function to search information in files
/// @param filename The file in which the information is stored
/// @param CNIC The CNIC/Natioanl ID of the person
/// @return Return true if the CNIC is found in the file
bool searchbyID(string filename, long long int CNIC)
{
    ifstream file(filename); // Opening the file in read mode

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return false; // Return false if the file cannot be opened
    }

    string line;

    while (getline(file, line)) // Read each line from the file
    {
        istringstream info(line); // 'istringstream' to parse the line
        string name, strCNIC;

        getline(info, name, ','); // Extract name
        getline(info, strCNIC);   // Extract CNIC

        long long int id = stoll(strCNIC); // Convert CNIC from string to long long int

        if (CNIC == id)
        {
            return true;
        }
    }

    file.close();
    return false;
}

/// @brief A general function to view all the contents of the file
/// @param filename The file which consists the information
void viewInfo(string filename)
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