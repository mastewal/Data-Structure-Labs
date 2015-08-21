/*Lab#: 0
Course: CS 5123
Name: Mastewal Abawa


 This program takes a string input from the user and do the following tasks:
- Reverse the string input
- Check if the string input is palindrome or not
- Determine the length of the string input
- Print out the first half of the string input
- Print out the first letter of the string input
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    // declare a string variable to be entered by the user
    string word;

    // prompt the user to enter the input
    cout << "Please enter your word " << endl;

    // Allows the user to enter the input
    cin >> word;

 //print out the reverse of the input string
   cout << "The word " << word << " back ward is:";
                cout <<string(word.rbegin(), word.rend())<<endl;


// check if the input string is palindrome or not and print the result
     if (word == string(word.rbegin(), word.rend()) ){
        cout << "\nThis word is palindrome"<< endl;
     }
     else {
         cout << "\nThis word is not palindrome" << endl;
     }

    // print out the length of the input string
    cout << "\nThe word is " << word.length()<< " characters long" << endl;

    // print out the first half of the input string
    cout << "\nThe first half of the word is ";
        for (int i = 0; i< word.length()/2; i++ ){
            cout << word.at(i);
        }

// print out the first letter of the input string
    cout << "\n\nThe first letter is: " << word.at(0) << endl;

}



