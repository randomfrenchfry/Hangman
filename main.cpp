#include "Hangman.h"
#include "dictionary.h"
void playGame(Hangman man)
{
    //functions to play the game
    man.pickAnswer();
    cout<<man.getAnswer();
    while(man.guessesLeft()>0 && (man.pattern().find("-")!=-1))
    {
        cout<<"guesses : "<<man.guessesLeft()<<endl;

        cout<< "guessed : "<<man.getGuesses()<<endl;
        cout<< "current : "<< man.pattern()<<endl;
        string g;
        cout<<"Your guess? ";
        cin>>g;
        if(man.getGuesses().find(g)!=-1)
        {
            cout<<"You already guessed that"<<endl;
        }
        else
        {
            int cnt = man.record(g);
            if(cnt == 0)
                cout<<"Sorry there are no "+g+"'s"<<endl;
            else if(cnt == 1)
                cout<<"Yes, there is one" +g<<endl;
            else
                cout<< "Yes, there are "<< cnt<<" "+g+"'s"<<endl;

        }
        cout<<endl;
    }

    //Game Design
    cout << "   -_      _-_     _-   _------     -         _-----   _-------_    _-----_   _-----_   _------  " << endl;
    cout << "     -_  _-   -_ _-     -____       -        -         -       -   -       - -       -  -____    " << endl;
    cout << "       -        -       -______     -______   -_____   -_______-   _        _        _  -______  " << endl;
    cout << "=================================================================================================" << endl;
    cout << "                                     ---------    _--------_                                     " << endl;
    cout << "                                         -        _        -                                     " << endl;
    cout << "                                         -        -________-                                     " << endl;
    cout << "=================================================================================================" << endl;
    cout << "          -      -    _----_   -_    -   _-----    _-----_  _-----_      _----_   -_    -        " << endl;
    cout << "          --------   _------_  _ -_  -  -   ---_  -       _ _      -    _------_  _ -_  -        " << endl;
    cout << "          -      -  -        _ _   - _   -_____-  _        -       -   -        _ _   - _        " << endl;
    cout << "=================================================================================================" << endl;
}
void showResults(Hangman man)
{
    //to show the result of the game
    cout<<"The answer was "<<man.getAnswer()<<endl;
    if(man.guessesLeft()>0)
        cout<<"You beat me"<<endl;
    else
        cout<<"Sorry, you lose"<<endl;
}
void tryFile(ifstream& file)
{

    if(!(file.is_open()))
    {
        throw runtime_error("File does not exist. Please Enter full path of .txt file");
    }

}
int main() {
    string userRes = "c";
    while(userRes != "q")
    {

        try
        {
            cout<<"Welcome to the hangman game"<<endl;
            cout<<endl;
            int wordLen, maxG = 0;
            cout<< "What length word do want to use? "; //poop
            cin>>wordLen;
            cout<<"How many wrong answers allowed? ";
            cin>>maxG;
            cout<<endl;

            Hangman hangman(wordLen,maxG);
            ifstream dict;
            string filename;
            cout<< "Enter dictionary or word Bank .txt file "<<endl;
            cin>>filename;

            filename = "/Users/victorrangel/Library/Mobile Documents/com~apple~CloudDocs/xcode/HW/Hangman/Hangman/dictionary.txt";
            dict.open(filename);
            dict.close();
            playGame(hangman);
            showResults(hangman);
            //delete [] hangman;
        }
        catch (runtime_error &excpt)
        {
            cout<< excpt.what()<<endl;

        }
        cout << endl << "Enter any key for another game ( or 'q' to quit ): "; //maybe
        cin>>userRes;
}
}