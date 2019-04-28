#include "Hangman.h"
void playGame(Hangman man)
{
    //functions to play the game
}
void showResults(Hangman man)
{
    //to show the result of the game
}
int main()
{
    ifstream file;
    file.open("/Users/victorrangel/Library/Mobile Documents/com~apple~CloudDocs/xcode/HW/Hangman/Hangman/dictionary.txt");
    int c = 0;
    string text;
    while(getline(file,text))
    {
        c++;
    }
    file.close();
    cout<< c;
    
}
