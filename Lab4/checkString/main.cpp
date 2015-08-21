/*
Name: Mastewal Abawa
Lab#: 4
course Name: Advanced Programming and Data Structures
Course# :cs 5123

A program that will take a string as an argument and :
   - checks whether or not the number of parentheses in the string
     is balanced or not (utilizing a stack)
   - Extract the variables (non parentheses) in the string to a queue,
     play them back from the queue into a string and return that.
*/

#include<string>
#include <iostream>
#include <stack>
#include "check_String.h"
#include <queue>
#include <fstream>
using namespace std;

int main()
{
    check_String S1; // instantiate check_String Object

    string expression; //  declare a string parameter called expression

   // Open the file named Lab4.txt
   ifstream myFile;
   myFile.open("Lab4.txt");

// print out a message if the file does not exist
   if (myFile.fail())
      {
          cout<< "File Not found"<< endl;
      }else {
            // Read the file  line by line until the end of the file is reached
                while (!myFile.eof() ){

                myFile>> expression; // store each line as the value of the variable expression

                cout << expression; // print out expression to the screen

                // call the is_balanced function and test whether expression is balanced or not
                     if(S1.is_balanced(expression)){
                        cout << " is balanced\n";

                    }else {
                     cout << " is not balanced \n";
                     }
                     // print out the variables by calling the store_variables function
                     cout <<"The variables are: ";
                     cout<< S1.store_varaibles(expression)<<endl;
                     cout<< "-----------------------------------"<<endl;
                }// the end of while

            myFile.close();// close the file opened
                  }

}
