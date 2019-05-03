#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "dictionary.h"
using namespace std;

#ifndef HangmanManager_H
#define HangmanManager_H
//size of the dictionary = 127142
class Hangman: public dictionary
{
public:
    Hangman();//default
    Hangman(int,int,string);// length of word, number of guesses
    string pattern(int); //---a--
    bool readFile(); //returns a string of guesses made by the user
    int record(string); //records the guess in a
    int guessesLeft(); //returns the number of guessesLeft numGuess--
    string getAnswer();//return a string of
    string getGuesses();//return a string output of the guesses made [a,b,c,d,e,...]
    
private:
    
    int numGuesses;//number of user guesses
    int wordlength;//inputed by the user
    int long dictionSize;//dictionary size
    string fileName;
    string wordAnswer;//random word chosen
    string strGuesses; //guesses output string
    string outPattern; //-a- cat pattern
    vector<string> dictionary; //words
    vector<string> guesses; //guesses made by the user
};

#endif
