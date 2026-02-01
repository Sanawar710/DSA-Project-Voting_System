// Searching algorithms implementation
#include "Searching-Algorithms.h"

bool linearSearch(std::string array[], int size, std::string targetElement)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == targetElement)
            return true;
    }
    return false;
}