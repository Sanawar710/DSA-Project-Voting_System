#include <iostream>

using namespace std;

/// @brief The algorithm for Linear Search
/// @param array The array in which we want to search element
/// @param size The size of the array
/// @param targetElement The element which we want to search
/// @return Returns true if the element is found, else false
bool linearSearch(int array[], int size, int targetElement)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == targetElement)
            return true;
    }
    return false;
}

/// @brief This is the algorithm for Binary Search
/// @param array The array in which we want to search element
/// @param size The size of the array
/// @param targetElement The element which we want to search
/// @return Returns true if the element is found, else false
bool binarySearch(int array[], int size, int targetElement)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // To avoid overflow

        if (array[mid] == targetElement)
            return true; // Target found at index mid

        if (array[mid] < targetElement)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    return false;
}