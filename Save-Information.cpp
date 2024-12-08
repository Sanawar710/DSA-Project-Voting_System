#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void saveInfo(string filename, string name, long long int CNIC)
{
    ofstream file(filename, ios::app); // Opening the file in append mode

    if (file.is_open())
    {
        file << name << "," << CNIC << endl; // Storing the values in a comma separated format
        file.close();
        cout << "\nCandidate information saved to file successfully.\n";
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
            }
            else
            {
                cerr << "\n Unable to create new file.\n";
            }
        }
    }
}

int main()
{
    char option;

    cin >> option;

    if (option == 'y')
    {
        saveInfo("Candidates.txt", "Bob", 8189391);
    }

    return 0;
}