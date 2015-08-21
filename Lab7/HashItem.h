#ifndef HASHITEM_H
#define HASHITEM_H

using namespace std;

class HashItem
{
    public:

        //overloaded constructor
        HashItem(int key);

        int getKey();// @returns key
        HashItem* getNext();// @ returns next

        void setKey(int);// sets new key
        void setNext(HashItem*);// sets next


    private:
        int key;// the key value
        HashItem *next; // a pointer to the next item



};

#endif // HASHITEM_H
