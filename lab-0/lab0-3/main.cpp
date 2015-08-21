/* Lab#: 0
Course: CS 5123
Name: Mastewal Abawa

A program that calculates the:
- sum of two numbers
- power a number
- maximum of five numbers
- minimum of five numbers
- average of five numbers
*/

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

// prototype the functions
float sum(float numbers[], int sizeOfNumbers );
double sqr(float x);
double power(float x, float y);
float maximum(float numbers[], int sizeOfNumbers );
float minimum(float numbers[], int sizeOfNumbers );
float average(float numbers[], int sizeOfNumbers );

int main()
{
  // Declare the parameters to be used in the functions
    float x = 0.0f; // used both in the sqr and power functions
    float y = 0.0f; // used in the power function

    int sizeOfNumbers = 0; // the size of the numbers array
    float numbers[sizeOfNumbers]; // declare an array named numbers

    int functionType = 0; // the type of the functions

    // Prompt the user to enter the type of the function s/he want to use
    cout<< "If you want to add numbers enter 1!"<< endl;
    cout<< "If you want to square a number enter 2!"<< endl;
    cout<< "If you want to calculate the power enter 3!"<< endl;
    cout<< "If you want to get the maximum enter 4!"<< endl;
    cout<< "If you want to get the minimum enter 5!"<< endl;
    cout<< "If you want to calculate the average enter 6!"<< endl;

    // Allow the user to enter the type of the function
    cin >> functionType;

        // switch statement that control the type of function to be used
         switch(functionType ){

               //  If the user choose to add numbers
               case 1:
                   cout << "Enter the number of numbers you want to add " << endl;
                   cin >> sizeOfNumbers ;

                        for (int i = 0; i< sizeOfNumbers; i++){
                            cout << "enter the "<< i + 1 << " Number" << endl;
                            cin >> numbers[i];
                        }

                    cout<< "The sum is: "<<sum(numbers, sizeOfNumbers)<< endl;
                            break;

            // If the user opts to calculate square root
            case 2:
                   cout << "please insert the  number"<< endl;
                   cin >> x;

                   cout << "The square root is: " <<sqr(x)<< endl;
                break;

            // If the user wants to find the power
            case 3:
                   cout << "please insert the  base"<< endl;
                   cin >> x;

                   cout << "please insert the power"<< endl;
                   cin >> y;

                   cout << "The power is: "<< power(x,y)<< endl;
                break;

            // If the user wants to know the maximum of numbers
            case 4:
                   cout << "Enter the number of numbers you want to compare " << endl;
                   cin >> sizeOfNumbers ;

                        for (int i = 0; i< sizeOfNumbers; i++){
                            cout << "enter the "<< i + 1 << " Number" << endl;
                            cin >> numbers[i];
                        }

                    cout<< "The maximum number is: "<< maximum(numbers, sizeOfNumbers )<< endl;

                 break;

            // If the user wants to know the minimum of numbers
            case 5:
                   cout << "Enter the number of numbers you want to compare " << endl;
                   cin >> sizeOfNumbers ;

                        for (int i = 0; i< sizeOfNumbers; i++){
                            cout << "enter the "<< i + 1 << " Number" << endl;
                            cin >> numbers[i];
                        }

                    cout<< "The minimum number is: "<< minimum(numbers, sizeOfNumbers )<< endl;
                break;

            // If the user wants to know the average of numbers
            case 6:
                   cout << "Enter the number of numbers you want to get the average " << endl;
                   cin >> sizeOfNumbers ;

                        for (int i = 0; i< sizeOfNumbers; i++){
                            cout << "enter the "<< i + 1 << " Number" << endl;
                            cin >> numbers[i];
                        }

                    cout<< "The average is: "<< average(numbers, sizeOfNumbers )<< endl;
                break;

            // if the user entered invalid function name
                default:
                   cout << "You inserted invalid function name" << endl;
                break;
         }

}

    //A function to calculate the sum of floating numbers
    float sum(float numbers[], int sizeOfNumbers ){

            float total = 0.0f;

                for (int i = 0; i< sizeOfNumbers; i++){
                        total += numbers[i];
                }
    return total;
    }


        // A function to  determine the square root of a number
        double sqr(float x){

            double squareRoot = sqrt(x);
            return squareRoot;
        }

        //  A function to calculate power (x is the base and y is the power)
        double power(float x, float y){

            double power = pow(x,y);
            return power;
        }


        // A function to calculate the maximum of  numbers
       float maximum(float numbers[], int sizeOfNumbers ){

         float maximum = -99999.9f;

            for (int i=0; i<sizeOfNumbers; i++){
               if( numbers[i]> maximum){
                 maximum = numbers[i];
               }

            }
        return maximum;
        }

        // A function to calculate the maximum of numbers
        float minimum(float numbers[], int sizeOfNumbers ){

            float minimum = 99999.9f;

                for (int i=0; i<sizeOfNumbers; i++){
                   if( numbers[i]< minimum){
                    minimum = numbers[i];
                   }
            }
            return minimum;
        }

        // A function to calculate the average of 5 numbers
        float average(float numbers[], int sizeOfNumbers ){

           double average = 0.0;
           double total = 0.0;

                for (int i=0; i<sizeOfNumbers; i++){
                   total += numbers[i];

                   average = total/sizeOfNumbers;
            }
            return average;
        }
