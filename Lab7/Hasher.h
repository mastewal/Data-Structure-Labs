#ifndef HASHER_H
#define HASHER_H

using namespace std;

class Hasher
{
    public:
        //overloaded constructor
        Hasher(int);

        void chaining(int);// chaining collision handler function
        void linearProbing(int);// linear probing collision handler function
        void doubleHash(int);//double hashing collision handler function
        void printTable(int);// a function that prints the values in the key during entry
        int myHash (int);//  a function that calculates the index of a given key and @returns index
        int resizeTable();// a function that resizes the table  and @returns table size
        int getSteps();// @returns steps
        int calculateCollision(int);// @return collision




    private:
        HashItem **table; // a hashItem pointer of pointers that creates a table
         int tableSize ;// table size
         int controlSize ;//  the size of the table filled with values
         int maxsize;// a variable to control the table not to store more than 75% of table size
         int collision;// the number of collisions
         int steps;// the number of steps before an element is inserted

};

#endif // HASHER_H
