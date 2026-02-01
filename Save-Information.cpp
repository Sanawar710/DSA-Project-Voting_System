// File handling implementations
#include "Save-Information.h"

#include <iostream>
#include <fstream>
#include <sstream>

bool saveInfo(std::string filename, std::string name, long long int CNIC)
{
    std::ofstream file(filename, std::ios::app);

    if (file.is_open())
    {
        file << name << "," << CNIC << std::endl;
        file.close();

        std::cout << "\nInformation saved to file successfully.\n";

        return true;
    }
    else
    {
        std::cerr << "\nUnable to open file.\n";

        char option;

        do
        {
            std::cout << "\nDo you want to create a new file with the same name? (y/n): ";
            std::cin >> option;
        } while (option != 'y' && option != 'n');

        if (option == 'y')
        {
            std::ofstream new_file(filename);

            if (new_file.is_open())
            {
                new_file << name << "," << CNIC << std::endl;
                new_file.close();

                std::cout << "\nNew file created and information saved successfully.\n";

                return true;
            }
            else
            {
                std::cerr << "\n Unable to create new file.\n";
                return false;
            }
        }
    }
    return false;
}

bool deleteInfo(std::string filename, long long int CNIC)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    std::ofstream tempFile("modifiedFile.txt");

    if (!tempFile.is_open())
    {
        std::cerr << "Error: Unable to create temporary file." << std::endl;
        file.close();
        return false;
    }

    std::string line;
    bool found = false;

    while (std::getline(file, line))
    {
        std::istringstream info(line);
        std::string name, strCNIC;

        std::getline(info, name, ',');
        std::getline(info, strCNIC);

        long long int id = stoll(strCNIC);

        if (CNIC == id)
        {
            found = true;
        }
        else
        {
            tempFile << line << std::endl;
        }
    }

    file.close();
    tempFile.close();

    if (found)
    {
        if (remove(filename.c_str()) != 0)
        {
            return false;
        }

        if (rename("modifiedFile.txt", filename.c_str()) != 0)
        {
            return false;
        }

        return true;
    }

    remove("modifiedFile.txt");
    return false;
}

bool searchbyID(std::string filename, long long int CNIC)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    std::string line;

    while (getline(file, line))
    {
        std::istringstream info(line);
        std::string name, strCNIC;

        std::getline(info, name, ',');
        std::getline(info, strCNIC);

        long long int id = stoll(strCNIC);

        if (CNIC == id)
        {
            return true;
        }
    }

    file.close();
    return false;
}

void viewInfo(std::string filename)
{
    std::string line;

    std::ifstream file(filename, std::ios::in);

    std::cout << " Name   |  CNIC\n";
    while (!file.eof())
    {
        std::getline(file, line);
        std::cout << line << std::endl;
    }
}