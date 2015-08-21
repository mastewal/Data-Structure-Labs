#ifndef BST_H
#define BST_H
using namespace std;

class BST
{
       private:
           // create Node of struct
            struct Node
            {
               Node* left;
               Node* right;
               int data;
            };

        Node* root;// create a node pointer
        int breadth_counter;// counts the number of steps in bread first search
        int depth_counter;// counts the number of steps in depth first search


    public:
        //default constructor
        BST();
        /*A function that inserts data read from file in to the tree i.e it creates BS tree
        @ param: the number read from the file*/
        void insert(int);
        /* A depth first search function. @ param Node* a pointer to Node ,
        @param int: the number to be searched */
        void depth_first(Node*, int);
        /* A breadth first search function. @ param Node* a pointer to Node ,
        @param int: the number to be searched */
        void breadth_first(Node*, int);
        // prints the result form breadth_first function. @param the number to be searched
        void print_Breadth_first(int);
        // prints the result form depth_first function. @param the number to be searched
        void print_Depth_first(int);
        // compare the efficiency both BST and DST techniques based on the number of steps it took to get a number
        void compare_techniques();



};

#endif // BST_H
