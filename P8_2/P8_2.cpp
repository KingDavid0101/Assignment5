/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class:       CSC 242
** Assignment:  Assignment 5
** File:        source.cpp
** Description: This program checks the spelling of words in a file by
**              comparing them to a dictionary word list.
**
** Author:      David Kingman
** Date:        September 9, 2026
** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> loadDictionary()
{
    vector<string> words;
    ifstream dictionaryFile("words.txt");

    string word;

    while (dictionaryFile >> word)
    {
        words.push_back(word);
    }

    dictionaryFile.close();

    return words;
}
bool wordInDictionary(const vector<string>& words, const string& word)
{
    for (const string& dictionaryWord : words)
    {
        if (dictionaryWord == word)
        {
            return true;
        }
    }

    return false;
}
// Checks each word in the file and displays words not found in the dictionary.
void checkSpelling(const vector<string>& dictionary, const string& fileName)
{
    ifstream inputFile(fileName);

    string word;

    while (inputFile >> word)
    {
        if (!wordInDictionary(dictionary, word))
        {
            cout << word << endl;
        }
    }

    inputFile.close();
}
int main()
{
    string fileName;

    vector<string> dictionary = loadDictionary();

    cout << "Enter the name of the file to check: ";
    cin >> fileName;

    checkSpelling(dictionary, fileName);

    return 0;
}
