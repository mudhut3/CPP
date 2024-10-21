/*
Harrison Groves
Palindrome project cpp
October 16, 2024
 */ 

#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;


string removePunct(string str); 


string convertToLower(string str);


string reverse(string str);

void display(vector<string> vstrings);


bool isPalindrome(string str);


int main() 
{
    vector<string> palindromes;      
    vector<string> not_palindromes;  

    string input;

    while (true) 
    {
        cout << "Enter your Palindrome or type quit: ";
        getline(cin, input);  // get full line of input from the user

        // Check if the user wants to quit
        if (input == "quit") 
        {
            break;  // exit loop if the user types quit
        }

        // Check if the string is a palindrome
        if (isPalindrome(input)) 
        {
            palindromes.push_back(input);  // add to palindromes if true
        } else 
        {
            not_palindromes.push_back(input);  // add to not_palindromes if false
        }
    }
	cout << "\nPalindromes:\n";
    display(palindromes);  // display the palindromes 

    cout << "\nNot Palindromes:\n";
    display(not_palindromes);  // display the non_palindromes 

    return 0;
}

string removePunct(string str) {
    string result = "";  // Create a new string to store the result without punctuation or spaces
    for (int i = 0; i < str.length(); i++) 
    { 
        if (!ispunct(str[i]) && !isspace(str[i])) // only append to the result if character is not punctuation and not a space
        {
            result += str[i];
        }
    }
    return result;  // return the string without punctuation and spaces
}

string convertToLower(string str)       // Precondition: a string that may have mixed case in it.
{
        for(int i = 0; i < str.length();i++)
    {
        if(isupper(str.at(i)))  
        {
            str[i] = tolower(str.at(i));           
        }
    }
    return str;  
}                                       // Postcondition: returns a lowercase string

string reverse(string str)              // Precondition: a string to be reversed
{
    int strEnd = str.length();
    int strMid = strEnd / 2;
    for (int i = 0; i < strMid; i++) 
    {
        char temp = str[i];                  
        str[i] = str[strEnd - i - 1];   // swap characters at positions i and n-i-1 , the corresponding position at the end, -1 to account for 0 indexing of string/array
        str[strEnd - i - 1] = temp;
    }
    return str;                         // Postcondition: returns a string that is the reverse of the input string.
}

void display (vector<string> vstrings)  // Precondition: a vector of strings to print
{
   for(int i = 0; i < vstrings.size(); i++)
   {
    cout << "\t" << vstrings[i] << endl;
   }
}                                       // Postcondition: strings are printed one per line.

bool isPalindrome(string str)
{
    str = removePunct(str);

    str = convertToLower(str);

    string reversedStr = reverse(str);  // reversed string for comparison to original 
   
    return str == reversedStr;          // compare both strings to check if palindrome
}
