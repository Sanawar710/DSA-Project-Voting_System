#include <iostream>

using namespace std;

/// @brief The algorithm for Linear Search
/// @param array The array in which we want to search element
/// @param size The size of the array
/// @param targetElement The element which we want to search
/// @return Returns true if the element is found, else false
bool linearSearch(string array[], int size, string targetElement)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == targetElement)
            return true;
    }
    return false;
}