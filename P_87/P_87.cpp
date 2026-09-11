/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class:       CSC 242
** Assignment:  Assignment 5
** File:        source.cpp
** Description: This program encrypts and decrypts a file using a
**              random monoalphabet cipher based on a keyword.
**
** Author:      David Kingman, John Corcillo, Deeana Aguiar
** Date:        September 9, 2026
** -------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Creates the cipher alphabet from the keyword.
string createCipherAlphabet(const string& keyword) // Function written by David Kingman
{
    string cipherAlphabet = "";
    string alphabet = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    // Add each keyword letter only once.
    for (char letter : keyword)
    {
        if (cipherAlphabet.find(letter) == string::npos)
        {
            cipherAlphabet += letter;
        }
    }

    // Add the remaining letters from the reversed alphabet.
    for (char letter : alphabet)
    {
        if (cipherAlphabet.find(letter) == string::npos)
        {
            cipherAlphabet += letter;
        }
    }

    return cipherAlphabet;
}

// Encrypts a single character using the cipher alphabet.
char encryptCharacter(char character, const string& cipherAlphabet) // Function written by David Kingman
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Find the character in the normal alphabet.
    size_t position = alphabet.find(character);

    // If the character is a letter, replace it with the cipher letter.
    if (position != string::npos)
    {
        return cipherAlphabet[position];
    }

    // Leave spaces, numbers, and punctuation unchanged.
    return character;
}

// Decrypts a single character using the cipher alphabet.
char decryptCharacter(char character, const string& cipherAlphabet) // Function written by John Corcillo
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Find the character in the cipher alphabet.
    size_t position = cipherAlphabet.find(character);

    // If the character is a letter, replace it with the original letter.
    if (position != string::npos)
    {
        return alphabet[position];
    }

    // Leave spaces, numbers, and punctuation unchanged.
    return character;
}

// Encrypts or decrypts an entire file.
void processFile(const string& inputFileName, const string& outputFileName, //Function written by Deeana Aguiar
    const string& cipherAlphabet, bool encrypt)
{
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    char character;

    while (inputFile.get(character))
    {
        if (encrypt)
        {
            outputFile << encryptCharacter(character, cipherAlphabet);
        }
        else
        {
            outputFile << decryptCharacter(character, cipherAlphabet);
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() //Written by David Kingman
{
    string keyword;
    string inputFileName;
    string outputFileName;
    char choice;

    cout << "Enter the keyword: ";
    cin >> keyword;

    cout << "Enter E to encrypt or D to decrypt: ";
    cin >> choice;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    string cipherAlphabet = createCipherAlphabet(keyword);

    if (choice == 'E' || choice == 'e')
    {
        processFile(inputFileName, outputFileName, cipherAlphabet, true);
        cout << "File encrypted successfully." << endl;
    }
    else if (choice == 'D' || choice == 'd')
    {
        processFile(inputFileName, outputFileName, cipherAlphabet, false);
        cout << "File decrypted successfully." << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

