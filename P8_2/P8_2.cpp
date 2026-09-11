/**-------------------------------------------------------------------------- -
**I attest that this following code represents my own work and is subject to
* *the plagiarism policy found in the course syllabus.
* *
**Class: 	CSC 242
* *Assignment : Final Project
* *File : spellcheck.cpp
* *Description : A program the checks the spelling of a word within a file,
** then prints out the words it cannot find within the word list.
**
** Author : John Corcillo, Deeana Aguiar
** Date : 9 / 4 / 2026
* *------------------------------------------------------------------------ - */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()                                                                       //Portion written by John Corcillo
{
    {
    //Opening dictionary file
    ifstream dictionary("dictionary.txt");          //opening to stream dictionary file location
    if (dictionary.fail())                          //condition if dictionary file fails to open
    {
        cout << "Error: Could not open dictionary file." << endl;
        return;
    }


    // Define a vector of strings called words
    vector<string> words;                           //empty vector to hold dictionary words


    // For each word in the dictionary file, append the word to the words vector
    string dictWord;                                //variable to hold each string from dictionary
    while (dictionary >> dictWord)                  //condition to extract from the dictionary
    {
        words.push_back(dictWord);                  //dictionary word gets appended to word string
    }
    dictionary.close();                             //closing dictionary since all words have been extracted


                                                                                //Portion written by Deeana Aguiar
    // Open the file to be checked
    ifstream checking(filename);                    //opening
    if (checking.fail())                            //condition if file to be checked fails to open
    {
        cout << "Error: Could not open file to be checked." << endl;
        return;
    }

    // Go through each word in the file to be checked
    string checkWord;
    while (checking >> checkWord)                   //extracting from words.txt file
    {
        bool found = false;
        for (const string& w : words)               //create new variable for word variable to go through loop so 
                                                            //there is no shadowing
        {
            if (w == checkWord)                     //if words within both files match, it breaks the loop and 
                                                            //doesnt get printed to the screen
            {
                found = true;
                break;
            }
        }
        // If the word is not contained in the words vector (which was loaded with dictionary words
        if (!found)
        {
            // Print the word
            cout << "Misspelled: " << checkWord << endl;
        }
    }

    checking.close();
}
