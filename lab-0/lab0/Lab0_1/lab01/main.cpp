#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    string reversedWord;
    cout << "Please enter your word " << endl;
    cin >> word;


cout << "The word " << word << " back ward is:";
    for (int i =0; i <word.length(); i++) {`

            reversedWord[i]= word[word.length()-i-1];
            cout << reversedWord[i];

    }



    cout << "\nThe word is " << word.length()<< " characters long" << endl;

    cout << "The first half of the word is ";
        for (int i = 0; i< word.length()/2; i++ ){
            cout << word.at(i);
        }

    cout << "\nThe first letter is: " << word.at(0) << endl;

}
