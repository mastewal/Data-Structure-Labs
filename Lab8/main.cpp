/*
Lab#: 8
Course: CS 5123
Name: Mastewal Abawa

This program:
- Reads data from file and then creates a binary search tree
- prompts the user to insert the number to be searched
- searches the number using both breadth first and depth first techniques
- return the number if found and the number of steps to search using both search techniques
- print out the numbers in the visited nodes
- compare which of the two search techniques was more efficient
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include "BST.h"

using namespace std;

int main()
{
    int number;// the number to be searched
    int data; // the number to be read from file and inserted in to the tree

    BST BST1; // instantiate a BST object


    //open file for reading
	ifstream infile;
	infile.open("search.txt");

	//check to see if the file opened correctly
	if(infile.fail())
	{
		cout << "File not found!" << endl;
		return 0 ;
	}
// Read the file and  insert the data in to the tree
	while (infile >>data){
        BST1.insert(data);
	}

// prompt the user to to enter the number to be searched
cout << "Enter the number to be searched:"<<endl;
cin>> number;
// print out the results
cout << "Breadth First:"<<endl;
BST1.print_Breadth_first(number);
cout << "\nDepth First:"<<endl;
BST1.print_Depth_first(number);
BST1.compare_techniques();// prints the result of which technique is efficient


return 0;
}
