#include "dictionary.h"

dictionary::dictionary() {
    this->size = 0;
}
dictionary::dictionary(int wordLen) {
    this->size = 0;
    this->wordLen = wordLen;
}
int dictionary::getSize(string name){
    ifstream file;
    file.open(name); //change this 
    
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
