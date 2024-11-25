#include <iostream>

using namespace std;

// For Arrays
void merge(int array[], int left, int right);    // Funtion Prototype. Later, used in merge sort algorithm
int partition(int array[], int left, int right); // Funtion Prototype. Later, used in quick sort algorithm

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

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size - 1; j++) // j is equal to i + 1 because the previous elements of the array are already sorted
        {
            if (array[j] < minIndex)
            {
                minIndex = j; // Update minimum index if a element less than the previous one is found in the unsorted part of array
            }
        }
        swap(array[i], array[minIndex]); // Swap elements if element smaller than minimum index is found
    }
}

void insertionSort(int array[], int size)
{
    int key, j;

    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Calculates mid point of the array

        // Recursive Call
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void quickSort(int array[], int left, int right)
{
    int partitionIndex;
    if (left < right)
    {
        partitionIndex = partition(array, left, right);
        // Recursive Call
        quickSort(array, left, partitionIndex - 1);  // Sorts left half
        quickSort(array, partitionIndex + 1, right); // Sorts right half
    }
}

int partition(int array[], int left, int right)
{
    int pivot = array[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= right && array[i] <= pivot)
        {
            i++;
        }

        while (j >= left && array[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(array[i], array[j]);
        }
    }

    swap(array[left], array[j]);
    return j;
}

void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    i = left;
    k = 0;
    j = mid + 1;
    int size = right - left + 1;
    int tempArray[size];

    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
        {
            tempArray[k] = array[i];
            i++, k++;
        }
        else
        {
            tempArray[k] = array[j];
            j++, k++;
        }
    }

    // Copy the remaining elements into the array
    while (i <= mid)
    {
        tempArray[k] = array[i];
        i++, k++;
    }

    while (j <= right)
    {
        tempArray[k] = array[j];
        j++, k++;
    }

    for (int i = left, k = 0; i <= right; i++, k++)
    {
        array[i] = tempArray[k];
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int array[] = {12, 34, 11, 102, 19, 92};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: ";
    printArray(array, size);

    cout << endl;

    bubbleSort(array, size);
    cout << "Array after bubble sort: ";
    printArray(array, size);

    cout << endl;

    selectionSort(array, size);
    cout << "Array after selection sort: ";
    printArray(array, size);
    return 0;
}