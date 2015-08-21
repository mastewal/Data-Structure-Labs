/* Lab#: 6
Course: CS 5123
Name: Mastewal Abawa

This program created a Robot warrior class. The class has the following attributes:
    - Name
    - A randomly generated number of hit points (100-500),
    - A randomly generated number of armor (a defensive modifier: 1-5),
    - A randomly generated number of weaponry (an offensive multiplier: 4-8)

 5 robots are created in the main program and they fight by the rule: "If a
 robot has a lower armor than the weaponry of the robot that comes next to it,
 the hit point of the latter will be the hit point of the
 former plus 5 times its own weaponry and the hit point of the former
 will be decreased by 5 times its own weaponry"

 The robots are sorted by the highest hit points, then by armor, then by weapons before
 and after the fight and if a robot/s scored more than 550 points, it will be announced as
 the winner.
  */




#include <iostream>
#include<cstdlib>
#include <ctime>
#include "Robot.h"
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
    srand(time(NULL));// declare random number generator seed value

    float gainerHitPoints = 0;// hit points to be gained after the fight
    float looserHitPoints = 0;// hit points lost after the fight

// instantiate 5 robots and set their name
    Robot R1;
        R1.setName("Atlanta ");

    Robot R2;
        R2.setName("Menilik ");

    Robot R3;
        R3.setName("Lincoln ");

    Robot R4;
        R4.setName("Tewodros");

    Robot R5;
        R5.setName("Marietta");

//declare myRobots vector
    vector<Robot> myRobots;
// push the robots into  myRobots vector
    myRobots.push_back(R1);
    myRobots.push_back(R2);
    myRobots.push_back(R3);
    myRobots.push_back(R4);
    myRobots.push_back(R5);

//display the rank of the robots with their score before the fight
    cout <<"\nRank Before the fight"<<endl;
    cout <<"\nName\t"<<setw(13)<< "\tHitPoints"<< setw(13)<<"Weaponry"<< setw(13)<<"Armor"<<endl;

        sort(myRobots.begin(),myRobots.end());// sorts the robot object using the overloaded function
        // loop through each element of the vector and print out the attribute of each element
        for(unsigned int i = 0; i < myRobots.size(); i++){

            cout <<myRobots[i].getName()<<setw(13)<<myRobots[i].getHitPoints()<<setw(13)<<
                   myRobots[i].getArmor()<< setw(13)<< myRobots[i].getWeaponry() <<  endl;
        }


 /* loop through each element of the vector and compare their weaponry and armor
 and then set their hit points based on the rule of the fight*/

    for (int i =0; i<myRobots.size(); i++){

        if (myRobots[i].getArmor()< myRobots[i+1].getWeaponry())
        {
            gainerHitPoints= myRobots[i].getHitPoints()+5*myRobots[i+1].getWeaponry();
            looserHitPoints = myRobots[i].getHitPoints()-5*myRobots[i].getWeaponry();
            myRobots[i+1].setHitPoints(gainerHitPoints);
            myRobots[i].setHitPoints(looserHitPoints);
        }

    }

    sort(myRobots.begin(),myRobots.end());// sort the robots after the fight

    cout <<"\nRank after the fight"<<endl;// print out the rank after the fight

    cout <<"\nName\t"<<setw(13)<< "\tHitPoints"<< setw(13)<<"Weaponry"<< setw(13)<<"Armor"<<endl;

        for(unsigned int i = 0; i < myRobots.size(); i++){

            cout <<myRobots[i].getName()<<setw(13)<<myRobots[i].getHitPoints()<<setw(13)<<
                   myRobots[i].getArmor()<< setw(13)<< myRobots[i].getWeaponry() <<  endl;

        }

       // If a robot/s score above 550 hit points announce it as a winner
        for(unsigned int i = 0; i < myRobots.size(); i++){

                   if (myRobots[i].getHitPoints()>550){

        cout << "\n The winner is ..."<< myRobots[i].getName()<<endl;
    }
        }
    }
