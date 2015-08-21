    #include <iostream>
    #include<cstdlib>
    #include <ctime>
    #include "Robot.h"
    #include <vector>
    using namespace std;

    // default constructor
    Robot::Robot()
    {
            hitPoints = 0.0;
            armor = 0;
            weaponry = 0;

            hitPoints = (((float)rand()/RAND_MAX)*400 + 100);// randomly generate hitpoints between 100 and 500
            armor = rand()% 5+1;// randomly generate armor between 1 and 5
            weaponry = rand()%5 + 4; //randomly  generate weaponry between 4 and 8
    }
    // @return name
    string Robot::getName(){
    return name;
    }
    //@return hitpoints
    float Robot::getHitPoints()const{
    return hitPoints;
    }
    // @return armor
    int Robot::getArmor()const{
    return armor;
    }
    // @return weaponry
    int Robot::getWeaponry()const{
    return weaponry;
    }
    // sets the new name of the robot
    void Robot::setName(string newName){
     name = newName;
    }
    // sets the new hitpoints of the robot
    void Robot::setHitPoints(float& newHitPoints){
     hitPoints = newHitPoints;
    }
    // sets the new armor of the robot
    void Robot::setArmor(int& newArmor){
    armor = newArmor;
    }
    // sets the weaponry of the robot
    void Robot::setWeaponry(int& newWeaponry){
    weaponry = newWeaponry;
    }


    /* overloaded function.Sorts the Robot objects based on their
    hitpoints then by armor and then by weaponry
    @return true if the hitpoint or armor or weaponry of a robot is greater than the hit point
    of the other robot's hitpoint or armor or weaponry
    */
    bool Robot::operator <(const Robot& R) const{

         if (this->getHitPoints() > R.getHitPoints())return true;
         if (this->getHitPoints() < R.getHitPoints())return false;

         if (this->getArmor() > R.getArmor()) return true;
         if (this->getArmor() < R.getArmor()) return false;

         if (this->getWeaponry() > R.getWeaponry()) return true;
         else false;

    }

