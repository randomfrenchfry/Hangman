#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "dictionary.h"
using namespace std;

#ifndef HangmanManager_H
#define HangmanManager_H
//static int dictSize = 127142; //size of the dictionary
class Hangman: public dictionary
{
public:
    Hangman();//bs
    Hangman(int,int);// length of word, number of guesses
    //~Hangman();// destructor for the dictionary
    string pattern(int); //---a--
    void readFile(string); //returns a string of guesses made by the user
    int record(string); //records the guess in a
    int guessesLeft(); //returns the number of guessesLeft numGuess--
    //void pickAnswer(); //picks random word answer
    string getAnswer();//return a string of
    string getGuesses();//return a string output of the guesses made [a,b,c,d,e,...]
    
private:
    
    int numGuesses;
    int wordlength;
    int long dictionSize;
    string wordAnswer;//random word chosen
    string strGuesses; //guesses output string
    string outPattern; //-a- cat pattern
    vector<string> dictionary; //words
    vector<string> guesses; //guesses made by the user
};

#endif
