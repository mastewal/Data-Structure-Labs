/*
Lab#: 0
Course: CS 5123
Name: Mastewal Abawa

A guessing game that will allow the user input a guess for a number
from 1 to 100. The program will compare the guess with a randomly
generated number
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    // declare random number generator seed value
    srand(time(NULL));

    // declare variables
    int counter = 0; // counts the number of guess
    int guess = 0; // the number guessed by the user
    string response;// the response of a player if s/he wants to play again
    bool correct = false;

    // Randomly generated secret number between 1 and 100
    int secret = rand()%100 + 1;

    // Greet the player when he/she starts the game and inform how to proceed
    cout << "Welcome to the number guess game!"<< endl;
	cout << "If you want to quit at the middle of the game enter -1 !" << endl;


    // while loop to allow the player guess the number 10 times unless s/he guessed correctly
    while ( !correct && (counter < 10) ){
            cout << "\nGuess a number between 1 and 100"<<endl;
            cin >> guess;
            counter++;
            cout << "You guessed " << counter << " time(s)"<< endl;
            cout << "You have remained "<<(10 - counter)<< " number of guesses"<< endl;

              // If the player reached the maximum allowed number of guess (10)
                if(counter >= 10){
                     cout << "You reached the maximum allowable number of guess"<< endl;
                     break;
                }

                // if the player wants to quit at the middle of the game s/he can press -1
                if (guess == -1){
                    cout << "you decided to quit the game!"<< endl;
                    break;
                }

                // if the player put non integer input s/he will be asked to check the input
                else if (cin.fail()) {
                    cout << "please check your input"<< endl;
                    break;
                    }

                // if guessed number is greater than randomly generated number
                else if (guess > secret){
                    cout << "Your Guess is higher than the randomly generated number"<< endl;
                }

                // if the player correctly guess the number
                else if (guess == secret){
                     cout << " congratulation! You Guessed it correctly !!"<< endl;
                     break;
                }

                // if guessed number is lower than randomly generated number
                else if (guess < secret){
                     cout << "Your Guess is lower than the randomly generated number"<< endl;

                }
        }


   // Ask the player if s/he wants to play again
   cout << "If you want to play again press Y!"<< endl;
   cin >> response;

   //The counter is set to zero for other round of play
   counter = 0;

   /* A do while loop that will allow the player to play again
   if s/he decided to do so*/
    do{

        cout << "\nGuess a number between 1 and 100"<<endl;
        cin >> guess;
        counter++;
        cout << "You guessed " << counter << " time(s)"<< endl;
        cout << "You have remained "<<(10-counter)<<" number of guesses"<< endl;

         // If the player reached the maximum allowed number of guess (10)
            if(counter >= 10){
                 cout << "You reached the maximum allowable number of guess"<< endl;
                 break;
            }

			// if the player wants to quit at the middle of the game s/he can press -1
			if (guess == -1){
				cout << "you decided to quit the game!"<< endl;
                break;
			}

			// if the player put non integer input s/he will be asked to check the input
			else if (cin.fail()) {
                cout << "please check your input"<< endl;
				break;
            }

			// if guessed number is greater than randomly generated number
            else if (guess > secret){
                cout << "Your Guess is higher than the randomly generated number"<< endl;
            }
			// if the player correctly guess the number
            else if (guess == secret){
                 cout << " congratulation! You Guessed it correctly !!"<< endl;
                 break;
            }

            // if guessed number is lower than randomly generated number
            else if (guess < secret){
                 cout << "Your Guess is lower than the randomly generated number"<< endl;
            }

      }

    while((response =="y" || response =="Y" ) && counter < 10 );

}
