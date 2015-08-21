/*
Name: Mastewal Abawa
Lab#: 1
course Name: Advanced Programming and Data Structures
Course# :cs 5123

A program that uses a struct and an array to store an array of players.
    -The struct holds players data such as:
        -a randomized string of letters of 6 characters for the name
        -a random int between 1 and 10 for the level
        -a random float from 50 to 100 for the power.

    -The array  holds 6 players
    -players data is saved to a file.
    -player data is read from the file and then an identical array is
     recreated and printed out.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

/* create a struct named myGame that holds a string of names,
 an int of level and a float of power */
struct myGame {string name;int level;float power;};

// prototype the functions
void printfile();
void writetofile();

int main()
{

        writetofile(); // call the writetofile function
        printfile();    // call the printfile function
}

//A function that writes the file "players.txt"
void writetofile(){
 // pseudo random number generator is initialized to null
    srand(time(NULL));
    //declare an array named player that has a data type named myGame
    myGame player[6];


        // open the file "players.txt"
        ofstream myfile;
        myfile.open("Players.txt");


      // Generate name, level and power randomly and write to the "players.txt" file

        for (int i = 0; i < 6; i++)// a for loop that loops for each of the six players
        {
        // a for loop that loops through each of the six characters of each of the six player's name
            for (int j = 0; j < 6; j++) /*Randomly generate a letter between a to z  6 times,
                                           append the letters and assign it to the variable name*/
            {
            player[i].name += 'a' +(rand()%26);
            }
        player[i].level = rand()%10 +1;/* Randomly generate a number between 1 and 10 and
                                          assign it to the variable level */
        player[i].power = rand()%50+50; /* Randomly generate a number between 50 and 100 and
                                          assign it to the variable power */

       // write each of the six players data into the file "players.txt"
       myfile << player[i].name<< "\t"<< player[i].level<< "\t"<<  player[i].power <<endl;
        }

        // close "players.txt" file
        myfile.close();
}
//A function that prints the file "players.txt"
void printfile(){
// open and read the "players.txt" file
      ifstream infile;
      infile.open("players.txt");

      // print out a message if the file is not found
      if (infile.fail())
      {
          cout<< "File Not found"<< endl;
      }

        // Declare variables that will store data from the file
        string name; // the name of the player
        int level =0; // the level of the player
        float power =0.0; // the power of the player

     // read the file and store the values into variables name, level and power
     while (infile >> name>> level >>power){
        cout << name<< "\t"<< level<< "\t"<<  power <<endl;

 }
 // close "players.txt" file
infile.close();

}



