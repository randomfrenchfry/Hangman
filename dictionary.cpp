//
// Created by Daniel Aguila on 2019-04-30.
//

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
    file.open("/Users/danielaguila/Documents/Hangman/dictionary.txt");

    string temp;
    int cnt = 0;
    while(file>> temp)
    {
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp.length() == wordLen)
        {
            cnt++;
        }
    }
    this->size = cnt;
    return size;
}
