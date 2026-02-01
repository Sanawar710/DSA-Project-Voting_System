#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>

struct Node_LinkedList;
class Singlelinklist;

class HashMap
{
public:
    std::vector<Singlelinklist> table; // Hash table implemented using a vector of singly linked lists
    int size;                          // Size of the hash table

    HashMap(int tableSize);

    int getSize();

    int hashFunction(long long int CNIC);

    Singlelinklist &getBucket(int index);

    bool registeration(std::string filename, std::string name, long long int CNIC);

    bool delete_by_CNIC(long long int CNIC);
};

#endif // HASHMAP_H
// Header wrapper for Hashing.cpp
#ifndef HASHING_H
#define HASHING_H

#include "Hashing.cpp"

#endif // HASHING_H
