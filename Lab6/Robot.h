#ifndef ROBOT_H
#define ROBOT_H
using namespace std;

class Robot
{
    public:
        Robot();// default constructor
        // getter functions
        string getName();// @returns name
        float getHitPoints() const;//@returns hitPoints
        int getArmor() const;// @returns armor
        int getWeaponry() const;// @returns weaponry
        // setter functions
        void setName(string );// sets new name to the robot
        void setHitPoints(float&);// sets new hitpoints to the robot
        void setArmor(int&);//sets armor
        void setWeaponry(int&);// sets weaponry

        /* overloaded function.Sorts the robot objects based on their
        hitpoints then by armor and then by weaponry
        @return true if the hitpoint or armor or weaponry of a robot is greater than the hit point
        of the other robot's hitpoint or armor or weaponry
        */
        bool operator <(const Robot& R2) const;

    private:
        string name;// a variable that store the name of a robot
        float hitPoints;// a variable that store the hitPoints of a robot
        int armor;// a variable that store the armor of a robot
        int weaponry;// a variable that store the weaponry of a robot
};


#endif // ROBOT_H
