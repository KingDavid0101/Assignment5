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




/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Final Project
** File: 	spellcheck.cpp
** Description: A program the checks the spelling of a word within a file, 
**				then prints out the words it cannot find within the word list.
**
** Author: 	John Corcillo, David Kingman, Deeana Aguiar
** Date: 	9/4/2026
** -------------------------------------------------------------------------*/


//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>

//using namespace std;

//ofstream data type represents the output file stream and is used 
//              to create files and to write information to files.
//ifstreams data type represents the input file stream and is used 
//              to read information from files.
//              object is used to open a file for reading purposes only


//int main() {
    //Opening dictionary file
    //    ifstream dictionary;                            //declaring a variable of ifstream data type for dictionary
    //    dictionary.open("dictionary.txt");              //using .open() function to stream dictionary file location
    //    if (dictionary.fail())                          //condition if dictionary file fails to open
    //    {
    //        cout << "Error: Could not open dictionary file." << endl;
    //        return 1;
    //    }


    // Define a vector of strings called words
    //    vector<string> words;                           //empty vector to hold dictionary words


    // For each word in the dictionary file, append the word to the words vector
    //    string dictWord;                                //variable to hold each string from dictionary
    //    while (dictionary >> dictWord)                  //condition to extract from the dictionary
    //    {
    //        words.push_back(dictWord);                  //dictionary word gets appended to word string
    //    }
    //    dictionary.close();






    // Open the file to be checked
    //    ifstream checking;                              //declaring variable of ifstream data type for file to be checked
    //    checking.open("words.txt");                      //opening file to be checked
    //    if (checking.fail())                            //condition if file to be checked fails to open
    //    {
    //        cout << "Error: Could not open file to be checked." << endl;
    //        return 1;
    //    }

    // Go through each word in the file to be checked
    //    string checkWord;
    //    while (checking >> checkWord)                   //while extracting from word.txt file 
    //    {
    //        bool found = false;                         //condition is set to false
    //        for (string w : words)                      //create new variable for word variable to go through loop so 
                                                                //there is no shadowing
    //        {
    //            if (w == checkWord)                     //if words within both files match, it breaks the loop and 
                                                                //doesnt get printed to the screen
    //            {
    //                found = true;
    //                break;
    //            } 
    //        }

            // If the word is not contained in the words vector (which was loaded with dictionary words)
    //        if (!found) 
    //        {
                // Print the word that was misspelled
    //            cout << "Misspelled: " << checkWord << endl;
    //        }
    //        
    //        else
    //        {
    //            cout << "Nothing in file is misspelled." << endl;
    //        }
    //    }

    //    checking.close();
    //    return 0;
//}
