#include "dictionary.h"

dictionary::dictionary() {
    this->size = 0;
}
dictionary::dictionary(int wordLen) {
    this->size = 0;
    this->wordLen = wordLen;
}
int dictionary::getSize(){
    ifstream file;
    file.open("/Users/victorrangel/Library/Mobile Documents/com~apple~CloudDocs/xcode/HW/Hangman/Hangman/dictionary.txt"); //change this 
    
    string temp;
    long int  cnt = 0;
    while(getline(file,temp))
    {
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp.length() == wordLen)
        {
            cnt++;
        }
    }
    file.close();
    return cnt;
}
