#include "Hangman.h"
#include "dictionary.h"
int playGame(Hangman man)
{
    //functions to play the game
    //man.pickAnswer();
    //cout<<man.getAnswer();
    int correct = 0;
    int index = 0;
    while(man.guessesLeft()>0 && (man.pattern(index).find("-")!=-1))
    {
        cout<<"Number of Guesses : "<<man.guessesLeft()<<endl;
        
        cout<< "Attempted Guesses : "<<man.getGuesses()<<endl;
        cout<< "Currently Solved  : "<< man.pattern(index)<<endl;
        string g;
        cout<<"Your guess? ";
        cin>>g;
        cout<<endl;
        if(man.getGuesses().find(g)!=-1)
        {
            cout<<"You already guessed that. Please enter a different letter."<<endl;
        }
        else
        {
            int cnt = man.record(g);
            if(cnt == 0)
                cout<<"Sorry there are no "<<g<<"'s"<<endl;
            else if(cnt == 1)
            {
                cout<<"Yes, there is one " <<g<<endl;
                correct++;
            }
            else if(cnt == man.getAnswer().length()-1)
            {
                cout<<"Wow you're good."<<endl;
                correct+=cnt;
            }
            else
            {
                cout<< "Yes, there are "<< cnt<<" "<<g<<"'s"<<endl;
                correct+=cnt;
            }
            
        }
        cout<<endl;
        index++;
    }
    return correct;
    //Game Design
}
void showResults(Hangman man,int correct)
{
    cout<<"The answer was: "<<man.getAnswer()<<endl;
    if(correct == man.getAnswer().length()-1)
        cout<<"You Won!!"<<endl;
    else
        cout<<"You Lose."<<endl;
        
}
void tryFile(bool res)
{
    
    if(res == false)
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
            
            //3cout<<endl;
            int wordLen, maxG = 0;
            cout<< "What length word do want to use? "; //poop
            cin>>wordLen;
            cout<<"How many wrong answers allowed? ";
            cin>>maxG;
            cout<<endl;
            
            ifstream dict;
            string filename;
            cout<< "Enter dictionary.txt file (Please include full path) "<<endl;
            cin.ignore();
            getline(cin,filename);
            //cout<<filename<<endl;
            //filename = "/Users/victorrangel/Library/Mobile Documents/com~apple~CloudDocs/xcode/HW/Hangman/Hangman/dictionary.txt";
            //cout<<filename<<endl;
            Hangman hangman(wordLen,maxG,filename);
            
            //dict.open(filename);
            bool res = hangman.readFile();
            tryFile(res);
            //dict.close();
            int correct = playGame(hangman);
            showResults(hangman,correct);
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
