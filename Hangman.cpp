#include "Hangman.h"
using namespace std;
Hangman::Hangman()
{
    wordlength = 0;
    numGuesses = 0;
    dictionary = nullptr;
}
Hangman::Hangman(int length,int numOfGuess)
{
    wordlength = length;
    numGuesses = numOfGuess;
    wordAnswer = "";
    dictionary = new string[dictSize];
    for(int i = 0;i<numOfGuess;i++)
    {
        guesses.at(0) = "";
    }
}

string Hangman::pattern()
{
    string res = "";
    if(guesses[0] == "")
    {
        while(res.length()<wordlength)
            res+="-";
    }
    else
    {
        for(int i = 0;i<dictionary->size();i++)
        {
            if(dictionary[i] == guesses[i])
            {
                res+= //needs work
            }
            else
            {
                
            }
        }
    }
    return res;
}

void Hangman::readFile(ifstream& file)// if user enters wordlength of 5 dictionary only picks words of length 5.
{
    string temp;
    int cnt = 0;
    while(file>> temp)
    {
        if(temp.length() == wordlength)
        {
            dictionary[cnt] = temp;
            cnt++;
        }
    }
}

void Hangman::record(string g)//records user guesses
{
    guesses.push_back(g);
}
int Hangman::guessesLeft()
{
    numGuesses--;
    return numGuesses;
}
void Hangman::pickAnswer()//picks a random word from the dictionary
{
    
}
string Hangman::getAnswer()
{
    return wordAnswer;
}
string Hangman::getGuesses()
{
    string out = "";
    for(int i = 0;i<guesses.size();i++)
    {
        out+=guesses[0]+", ";
    }
    return out;
}

























/**
HangmanManager::HangmanManager(list<string>dict,int len,int max)
{
    wordlength = len;
    maxGuesses = max;
    dictionary = dict;
}
set<string> HangmanManager::wordBank()
{
    set<string>words;
    for(string i : dictionary)
    {
        if(i.length()<=1)
        {
            words.insert(i);
        }
    }
    return words;
}
int HangmanManager::guessesLeft()
{
    if(userGuesses.empty())
    {
        return maxGuesses;
    }
    string last = ""; //change
    for(string i: dictionary)
    {
        if(!(i.find(last)))
        {
            return maxGuesses;
        }
    }
    return maxGuesses--;
}

string HangmanManager::pattern()
{
    string s = "";
    int p =0;
    if(userGuesses.empty())
    {
        while(s.length()<1)
            s+="-";
    }
    else
    {
        string last =""; //change
        for(string i : dictionary)
        {
            if(i.find(last))//change
            {
                
                while (p<1)
                {
                    if(last.find(i[p]))
                        s+=i[p];
                    else
                        s+="-";
                    p++;
                }
            }
        }
    }
    o.emplace(s,"");
    return s;
}

int HangmanManager::record(string guess)
{
    int c =0;
    //int m = INT_MAX;
    set<string> pwords;
    userGuesses.insert(guess);
    if(userGuesses.size() == 1)
    {
        for(string i : dictionary)
        {
            if(i.find(guess) == 1)
            {
                pwords.insert(i);
            }
        }
    }
    else if(userGuesses.size()>1)
    {
        for(string i : dictionary)
        {
            if(i.find(guess)!= -1)
            {
                pwords.insert(i);
            }
        }
        o.emplace(pattern(),pwords);
    }
    for(int i = 0; i<wordlength;i++)
    {
        string x = pattern();
        if(guess.find(x[i]))
        {
            c++;
        }
    }
    guessesLeft();
    return c;
}
void HangmanManager::playGame()
{
    while(guessesLeft() >0 and pattern().find("-"))
    {
        cout<< "guesses: "<< guessesLeft();
        
        string gs = "";
      
        cout<< "guessed: "<< gs <<endl;
        cout<< "current: "<<  pattern()<<endl;
        cout<< "Your guess? "<<endl;
        string g = "";
        cin >> g;
        
        if(userGuesses.count(g))
        {
            cout<<"You already guessed that"<<endl;
        }
        else
        {
            int count =  record(g);
            if(count == 0)
            {
                cout<< "Sorry, there are no "<<g<<"'s"<<endl;
            }
            else if(count == 1)
            {
                cout<< "Yes, there is one "<<g<<endl;
            }
            else
            {
                cout<< "Yes, there are "<<count<<" "<<g<<"'s"<<endl;
            }
        }
        cout<<endl;
    }
}
void HangmanManager::showResults()
{
    set<string>::iterator first =  wordBank().begin();
    string answer = *first;
    cout<<"answer = "<<answer<<endl;
    if( guessesLeft()>0)
    {
        cout<<"You beat me"<<endl;
    }
    else
    {
        cout<<"Sorry, you lose"<<endl;
    }
 **/


