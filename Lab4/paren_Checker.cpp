#include<string>
#include <iostream>
#include <stack>
#include <queue>
#include "paren_Checker.h"
#include <cstdlib>
#include <ctime>
using namespace std;

paren_Checker::paren_Checker()
{
 OPEN = "({["; // A string of open parentheses
 CLOSE = ")}]"; // A string of closed parentheses
srand(time(NULL)); // Random number generator seed value

 for (int j = 0; j < 26; j++)
            {
            VARIABLES += 'A' + j;// Randomly generate from A to Z (capital letters)
            VARIABLES2 += 'a' + j; // Randomly generate from a to z(small letters)
            }
};


/* A function to determine whether a character is one of the opening parentheses
   (defined in constant OPEN)
   @param ch character to be tested
   @return true if the character is an opening parenthesis
*/

bool paren_Checker:: is_open(char ch){

    return OPEN.find(ch) != string::npos;
}

/* A function to determine whether a character is one of the closing parentheses
   (defined in constant CLOSE)
   @param ch character to be tested
   @return true if the character is a closing parenthesis
*/
bool paren_Checker::is_close(char ch){
    return CLOSE.find(ch) != string ::npos;
}
// Test the input string that it contains balanced parentheses
//@param expression a string containing the expression to be examined
//@return true if all the parentheses match
 bool paren_Checker:: is_balanced(const string& expression){

 // A stack for the open parentheses that have not been matched
 stack <char> s;
 bool balanced = true;
 string:: const_iterator iter = expression.begin();

 while (balanced && (iter != expression.end())){

    char next_ch = *iter;

    if (is_open(next_ch)){
        s.push(next_ch);
    }else if (is_close(next_ch)){
      if (s.empty()){
        balanced = false;
      }else{
        char top_ch = s.top();
        s.pop();
        balanced = OPEN.find(top_ch)== CLOSE.find(next_ch);
       }
     }
     ++ iter;
 }
 return balanced && s.empty();
 }
/* Test the input string that it contains Variables (from A to Z or a to z)
and stores the variables in queue
@param expression a string containing the expression to be examined
@return the variables if any exists*/
char paren_Checker::store_varaibles (const string& expression){

    // a queue of variables (non parentheses values)i.e from A to Z or a to z
    queue <char> q;

    string:: const_iterator iter = expression.begin();

for ( int i = 0 ; i< expression.size(); i++){

        char next_ch = *iter;
        /* if a variable exists, it will be pushed to the queue
         and then printed out*/
        if ((VARIABLES.find(next_ch) != string::npos)||
           ((VARIABLES2.find(next_ch)) != string::npos)){

        q.push(next_ch);
        cout << q.front();// print out the queue
        q.pop();
        }
        ++iter;

        }

        }
