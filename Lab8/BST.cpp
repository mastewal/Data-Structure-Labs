#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include "BST.h"


// default constructor
BST::BST()
{
    breadth_counter = 0;
    depth_counter = 0;
    root = NULL;
}
 /*A function that inserts data read from file in to the tree i.e it creates BS tree
        @ param: the number read from the file*/
void BST::insert(int number)
{


    Node* n = new Node;// create new node and point n to the newly created node
    Node* parent; // create a node  pointer named parent
    n->data = number;// assign the value from the parameter to data
    n->left = NULL;
    n->right = NULL;
    parent = NULL;

  // check if the tree has element i.e if it is new tree
  if(root == NULL)
    root = n;
  else
  {
    Node* current;// create new node pointer
    current = root;
/* compare the data and with the value in the node pointed by current node pointer and
insert it to the right if  value of data is greater and to the left if it is lower */
    while(current)
    {
        parent = current;
        if(n->data > current->data)
            current = current->right;
        else
            current = current->left;
    }

    if(n->data < parent->data)
       parent->left = n;
    else
       parent->right = n;
  }
}
/* A depth first search function. @ param Node* a pointer to Node ,
        @param int: the number to be searched */
void BST:: depth_first(Node* root, int num){


Node* current = root;

if (root== NULL)
    return;

    // Create an empty stack
    stack<Node*> myStack;
    //push root to the stack
    myStack.push(root);
// loop either until the stack is empty or the number searched is found
    while (!myStack.empty() && current->data != num)
    {

        current= myStack.top();
        cout << current->data <<" ";
        myStack.pop();


        // Push left  and right children of the popped node to the stack
        if (current->left)
            myStack.push(current->left);

        if (current->right)
            myStack.push(current->right);

      depth_counter++;

    }
   // print out the result
    if (current->data != num){
       cout <<"\n" << num<< " is not found"<< endl;
    }
    else
        cout <<" Found in "<<depth_counter << " steps"<<endl;
    }



 /* A breadth first search function. @ param Node* a pointer to Node ,
        @param int: the number to be searched */
void BST:: breadth_first(Node* root, int num){

  if (root == NULL){
    return;
}
    // Create a queue
   queue<Node*> myQueue;

   // Push the root
   myQueue.push(root);
    Node* current;

// loop either until the queue is empty or the number searched is found
 while( ! myQueue.empty() && current->data != num )
   {
       // Dequeue a node from front
     current = myQueue.front();
       cout << current->data << " " ;

       // push the right and the left children to the right and the queue
       if ( current->left != NULL )
            myQueue.push(current->left);

       if ( current->right != NULL )
         myQueue.push(current->right);

       // Pop the front element
       myQueue.pop();
       breadth_counter++;
}
// print out message if the number is not in the tree or the number of steps it took if found
    if (current->data != num){
        cout <<"\n" << num<< " is not found"<< endl;
    }
    else
        cout <<" Found in "<<breadth_counter << " steps"<<endl;
    }


// compare the efficiency both BST and DST techniques based on the number of steps it took to get a number
void BST::compare_techniques(){

    if (breadth_counter< depth_counter){
        cout << "\nBreadth First Search is efficient"<< endl;
    }
    if(breadth_counter == depth_counter){
        cout << "\nBoth have Equal efficiency"<< endl;
    }
    else if(breadth_counter>depth_counter) {
            cout << "\nDepth First Search is efficient"<<endl;
        }
}

// prints the result form breadth_first function. @param the number to be searched
void BST:: print_Breadth_first(int num){

breadth_first(root, num);
}
 // prints the result form depth_first function. @param the number to be searched
void BST:: print_Depth_first(int num){
depth_first(root, num);
}
