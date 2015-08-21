#include "HashItem.h"
#include "Hasher.h"
#include <iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;


// overloaded constructor
HashItem::HashItem(int key){

   this->key = key;
   this -> next = NULL;

}

// getter functions
 int HashItem:: getKey(){
     return key;
 }


HashItem* HashItem:: getNext(){
    return next;
}

// setter functions
void HashItem:: setKey(int key){
this->key = key;
}

void HashItem:: setNext(HashItem* next){
this->next = next;
}
