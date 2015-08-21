/* Lab#: 7
Course: CS 5123
Name: Mastewal Abawa

A program that will create a hash table using the following collusion handling techniques
- linear probing
- double hashing
- chaining
The program also calculate the number of collisions, the total steps to place each element
and the total number of entry

*/

#include "HashItem.h"
#include "Hasher.h"
#include <iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{

   // declare variables
   int key = 1; // the key value
   int myTableSize = 0;// the size of the table
   int hashType = 0;// hash type (1 for linear probing, 2 for double hashing,3 for chaining
   bool decidedToQuit = false; //a boolean to determine if the user want to quit hashing
   int numberOfElements =0;


   cout << "Enter Table Size: "<< endl;
   cin>> myTableSize;

   Hasher *h1 = new Hasher(myTableSize) ; // instantiate a pointer that points to new hasher object
   HashItem *ptr = new HashItem(key);
// prompt the user
   cout << "1 is for linear probing "<< endl;
   cout << "2 is for double hashing "<< endl;
   cout << "3 is for chaining "<< endl;
   cout << "-1 to quit "<< endl;

   cout << "Enter Hash Type: "<< endl;
   cin>> hashType;

// while  that will allow the user to  create hash table and insert values until s/he decided to quit
while (!decidedToQuit){
//switch statement that allows the user to switch between different hashing techniques
switch(hashType)
        {
        // linear probing
        case 1:
            cout<<"\n\nEnter key to be inserted: ";
            cin>> key;
                    if (key == -1){

                    cout << "\nYou decided to quit! Good Bye!"<<endl;
                    cout << "\n\nNumber of Elements: "<< numberOfElements<<endl;


                        exit(!decidedToQuit);
                    }
                    h1->linearProbing(key);
                    h1->printTable(key);
                    numberOfElements++;

            cout << "steps: "<< h1->getSteps()<< " collisions: "<< h1->calculateCollision(key)<<endl;
            break;
        // Double hash
          case 2:
            cout<<"\n\nEnter key to be inserted: ";
            cin>> key;
                    if (key == -1){
                        cout << "\nYou decided to quit! Good Bye!"<<endl;
                        cout << "\n\nNumber of Elements: "<< numberOfElements<<endl;
                        exit(!decidedToQuit);
                       }

                h1->doubleHash(key);
                h1->printTable(key);
                numberOfElements++;

                cout << "steps: "<< h1->getSteps()<< " collisions: "<< h1->calculateCollision(key)<<endl;

            break;
            // chaining
            case 3:
            cout<<"\n\nEnter key to be inserted: ";
            cin>> key;

                    if (key == -1){
                        cout << "\nYou decided to quit! Good Bye!"<<endl;
                        cout << "\n\nNumber of Elements: "<< numberOfElements<<endl;
                        exit(!decidedToQuit);

                    }


                h1->chaining(key);
                h1->printTable(key);
                numberOfElements++;

                cout << " collisions: "<< h1->calculateCollision(key)<<endl;
            break;

            default:
           cout<<"\n Hashing interrupted\n"<<endl;
           decidedToQuit = true;
           break;


}// end of switch statement


}// end of while loop


return 0;

}
