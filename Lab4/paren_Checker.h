#ifndef PAREN_CHECKER_H
#define PAREN_CHECKER_H

using namespace std;

class paren_Checker
{
    public:
        paren_Checker();//constructor


        /* A function to determine whether a character is one of the opening parentheses
           (defined in constant OPEN)
           @param ch character to be tested
           @return true if the character is an opening parenthesis
        */
        bool is_open(char);

        /* A function to determine whether a character is one of the closing parentheses
           (defined in constant CLOSE)
           @param ch character to be tested
           @return true if the character is a closing parenthesis
        */
        bool is_close(char);

        // Test the input string that it contains balanced parentheses
        //@param expression a string containing the expression to be examined
        //@return true if all the parentheses match
        bool is_balanced(const string&);

        /* Test the input string that it contains Variables (from A to Z or a to z)
        and stores the variables in queue
        @param expression a string containing the expression to be examined
        @return the variables if any exists*/
        char store_varaibles (const string& expression);



    private:
         string OPEN ;// a string of open parentheses
         string CLOSE ;// a string of closed parentheses
         string VARIABLES; // a string of capital letters from A to Z
         string VARIABLES2; // a string of small letters from a to z


};

#endif // PAREN_CHECKER_H
