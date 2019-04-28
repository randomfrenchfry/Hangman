#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#ifndef HangmanManager_H
#define HangmanManager_H
static int dictSize = 127142; //size of the dictionary
class Hangman
{
public:
    Hangman();//bs
    Hangman(int,int);// length of word, number of guesses
    ~Hangman();// destructor for the dictionary
    string pattern(); //---a--
    void readFile(ifstream&); //returns a string of guesses made by the user
    void record(string guess); //records the guess in a
    int guessesLeft(); //returns the number of guessesLeft numGuess--
    void pickAnswer(); //picks random word answer
    string getAnswer();//return a string of
    string getGuesses();//return a string output of the guesses made [a,b,c,d,e,...]
    
private:
    
    int numGuesses;
    int wordlength;
    string wordAnswer;//random word chosen
    string *dictionary; //words
    vector<string> guesses; //guesses made by the user
};

#endif
