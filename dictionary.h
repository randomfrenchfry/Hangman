#include <fstream>
#include <string>

#ifndef HANGMAN_DICTIONARY_H
#define HANGMAN_DICTIONARY_H
using namespace std;

class dictionary {
public:
    dictionary();
    dictionary(int wordLen);
    int getSize(string);
private:
    int size;
    int wordLen;
};


#endif //HANGMAN_DICTIONARY_H
