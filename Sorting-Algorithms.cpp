#include <iostream>
#include "Singly-Linked-List.cpp" // Ensure this file contains your linked list implementation

using namespace std;

// Bubble Sort for Array
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}

// Selection Sort for Array
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        swap(array[i], array[minIndex]);
    }
}

// Insertion Sort for Array
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

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
        if (L[i] <= R[j])
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

// Merge Sort for Array
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

int partition(int array[], int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (array[j] < pivot)
            swap(array[++i], array[j]);
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}

// Quick Sort for Array
void quickSort(int array[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(array, left, right);
        quickSort(array, left, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, right);
    }
}

// Bubble Sort for Singly Linked List
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
            if (current->CNIC > current->next->CNIC)
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