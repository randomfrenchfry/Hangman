#include "Hangman.h"
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
Hangman::Hangman()
{
    wordlength = 0;
    numGuesses = 0;
    wordAnswer = "";
    strGuesses = "";
    outPattern = "";
}
Hangman::Hangman(int length,int numOfGuess):dictionary(dictionSize),guesses(numOfGuess)
{
    wordlength = length+1; //end line character is included for each word
    numGuesses = numOfGuess;
    wordAnswer = "";
    strGuesses = "";
    outPattern = "";
    class dictionary dict(wordlength);
    dictionSize = (dict.getSize());
}

string Hangman::pattern(int in)
{
  
    while(outPattern.length()<wordlength-1)
        outPattern+="-";
    if(wordAnswer.find(guesses.back())!=-1 && in>0)
    {
        outPattern.replace(in-1, guesses.back().length(), guesses.back());
    }
    return outPattern;
}

void Hangman::readFile(string filename)// if user enters wordlength of 5 dictionary only picks words of length 5.
{
    fstream file;
    file.open(filename);
    
    string temp="";
    int c = 0;
    while(getline(file,temp))
    {
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp.length() == wordlength)
        {
            dictionary.push_back(temp);
            c++;
        }
    }
    file.close();
    srand(time(NULL));
    //cout<<"Size: " << dictionSize;
    int tempN = rand() % (dictionSize);
    wordAnswer = dictionary.at(tempN);
    //cout << wordAnswer;
    
}

int Hangman::record(string g)//records user guesses
{
    guesses.push_back(g);
    int c = 0;
    if(g.length() == wordlength)
    {
        if(g == wordAnswer)
        {
            c+= wordlength-1;
        }
    }
    else
    {
        if(g.length() == 1 && wordAnswer.find(g)!=-1)
            c+=1;
        else if(g.length()>1 && wordAnswer.find(g)!=-1)
        {
            for(int i = 0;i<wordlength;i++)
            {
                if(wordAnswer[i] == g[i])
                    c++;
            }
        }
    }
    numGuesses--;
    return c;
}
int Hangman::guessesLeft()
{
    return numGuesses;
}
//void Hangman::pickAnswer()//picks a random word from the dictionary
//{
//    srand(time(NULL));
//    class dictionary dict(wordlength);
//    //cout<<dict.getSize();
//    long int temp = rand() % (dict.getSize()); ------
//    for(int i =0;i<=temp;i++){
//        dictionary++;
//    }
//    cout << *dictionary;
//}
string Hangman::getAnswer()
{
    return wordAnswer;
}
string Hangman::getGuesses()
{
    if(strGuesses.find(guesses.back())==-1)
        strGuesses+=guesses.back();
    return strGuesses;
}

