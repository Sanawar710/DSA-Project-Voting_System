// Hashing implementation
#include "Hashing.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Save-Information.h"
#include "Singly-Linked-List.h"

HashMap::HashMap(int tableSize) : size(tableSize)
{
    table.resize(size);
}

int HashMap::getSize()
{
    return size;
}

int HashMap::hashFunction(long long int CNIC)
{
    return CNIC % size;
}

Singlelinklist &HashMap::getBucket(int index)
{
    return table[index];
}

bool HashMap::registeration(std::string filename, std::string name, long long int CNIC)
{
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line))
    {
        std::istringstream info(line);
        std::string fileName, fileCNIC;

        std::getline(info, fileName, ',');
        std::getline(info, fileCNIC);

        if (stoll(fileCNIC) == CNIC)
        {
            std::cout << "Candidate with CNIC " << CNIC << " already exists in the file!" << std::endl;
            file.close();
            return false;
        }
    }
    file.close();

    int index = hashFunction(CNIC);
    Node_LinkedList *current = table[index].head;

    while (current != NULL)
    {
        if (current->CNIC == CNIC)
        {
            std::cout << "Candidate with CNIC " << CNIC << " already exists in the hash table!" << std::endl;
            return false;
        }
        current = current->next;
    }

    table[index].insert(name, CNIC);
    saveInfo(filename, name, CNIC);
    std::cout << "Registered successfully!" << std::endl;
    return true;
}

bool HashMap::delete_by_CNIC(long long int CNIC)
{
    int index = hashFunction(CNIC);

    if (table[index].deletion(CNIC))
        return true;

    return false;
}