#include "HashItem.h"
#include "Hasher.h"
#include <iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

//overloaded constructor
Hasher::Hasher(int myTableSize)
{
    tableSize = myTableSize;
    controlSize = 0 ;
    maxsize = 0;
    maxsize = tableSize *0.75;
    collision = 0;
    steps = 0;

    table = new HashItem*[tableSize];/* instantiate a table that will contain HashItem pointers
                                     having size equal to tableSize*/

            // fill the table with NULL values
            for (int i = 0; i < tableSize; i++){
                  table[i] = NULL;
            }
}


// @returns index : calculate index by dividing key with tableSize
int Hasher:: myHash (int key){

int index = 0;

index = key% tableSize;

return index;
}

// chaining collision handler function
void Hasher:: chaining(int key){

   int index = myHash(key);
           /* if the table has NULL elements at the given index generate new HashItem
              else assign the value to HashItem pointer and point the HashItem pointer
              to the next element if the next element is not NULL
           */
            if (table[index] == NULL){
                  table[index] = new HashItem(key);

            }
            else {
                  HashItem *item = table[index];
                  while (item->getNext() != NULL){
                        item = item->getNext();
                  }
                  // chains hash items having the same index together
                  if (item->getKey() != key){
                        item->setNext(new HashItem(key));
                  }
            }

        }
//  linear probing collision handler function
void Hasher:: linearProbing(int key){

 int index = myHash(key);

            /*if the element at the given index is not NULL and its key value is
            equal to the key passed as parameter increment the index by 1*/
            while (table[index] != NULL && table[index]->getKey() != key){
                  index =((index+1) % tableSize);
                  steps++;
                 }
                 // if the table at the given index is not Null delete it
                  if (table[index] != NULL){
                  delete table[index];
            }
            // generate new HashItem
            table[index] = new HashItem(key);
            controlSize++;

         if (controlSize >= maxsize){
        resizeTable();
     }

}
// double hashing collision handler function
/*if the element at the given index is not NULL and its key value is
            equal to the key passed as parameter rehash it and increment the index by 1*/
void Hasher:: doubleHash(int key){

int index = myHash(key);

            while (table[index] != NULL && table[index]->getKey() != key){
                  index =((index) % 7) +1;
                  steps++;
                   }
            if (table[index] != NULL){
                  delete table[index];
            }

            table[index] = new HashItem(key);
            controlSize++;

             if (controlSize >= maxsize){
        resizeTable();
     }


}


// a function that resizes the table when it reaches 75% full

int Hasher::resizeTable(){

            int oldTableSize = tableSize; // declare oldtableSize and pass tablesize to it
            tableSize = 2*tableSize;// multiply tablesize by 2 and get new size

            maxsize = (int) (tableSize * 0.75);// declare maxsize which is 0.75 times oldtablesize

            table = new HashItem* [tableSize];//generate new table using the new table size

            //set all elements of the table at the given index to NULL
           for (int i = 0; i < tableSize; i++){
                  table[i] = NULL;
            }


}
// return steps
int Hasher:: getSteps(){
return steps;
}
// calculate and return the number of collusion
int Hasher::calculateCollision(int key){

      int index = myHash(key);

       if(getSteps() ==1){
        collision = 1;
       }
      if (table[index] != NULL && table[index]->getKey() != key){

                collision++;
            }
return collision;
}
//print the elements contained in each index
void Hasher:: printTable(int key){

int index = myHash(key);

HashItem *HIptr = table[index];

        cout <<"\nIndex " <<index + getSteps() << " contains: ";

            while(HIptr != NULL){

                cout << HIptr ->getKey() << "\t";
                HIptr = HIptr->getNext();

 }
 }
