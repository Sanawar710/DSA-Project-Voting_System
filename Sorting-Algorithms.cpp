#include <iostream>
#include "Singly-Linked-List.cpp"

using std::cout, std::cin, std::endl;

/// @brief This function is used to merge the two sorted subarrays with each other
/// @param array The array that is being sorted
/// @param left The starting point (from where we want to sort the array)
/// @param mid The midpoint of the array which we want to sort
/// @param right The ending point (the point till which we want to sort array)
void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    // Copying the remaining elements in the array
    while (i < n1)
        array[k++] = L[i++];
    while (j < n2)
        array[k++] = R[j++];
}

/// @brief The merge sort function is used to sort array with O(log n) time complexity
/// @param array The array that is being sorted
/// @param left The starting point (from where we want to sort the array)
/// @param right The ending point (the point till which we want to sort array)
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

/// @brief Bubble Sort for Singly Linked List
/// @param head The starting point of the list
void bubbleSort(Node_LinkedList *head)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    bool swapped;
    Node_LinkedList *current;
    Node_LinkedList *lastSorted = NULL;

    do
    {
        swapped = false;
        current = head;

        while (current->next != lastSorted)
        {
            if (current->CNIC < current->next->CNIC)
            {
                swap(current->name, current->next->name);
                swap(current->CNIC, current->next->CNIC);
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}