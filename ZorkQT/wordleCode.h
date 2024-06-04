#ifndef WORDLECODE_H
#define WORDLECODE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;



class WordleCode{
public:
    enum Status {WORDLE_STOP, WORDLE_CURRENT, WORDLE_FAILED, WORDLE_COMPLETED };

private:
    // All words that are possible
    static vector<string> allPossibleWords;
    static int triesLeft;    
    static Status wordleStatus;
    static void inititialiseWords(string filename);
    static string goalWord;


public:
    static string checkInput(const string& input);
    static vector<string> getAllWords();
    static Status getStatus();
    static void startWordleGame();
    static string checkGame();
    static void initialiseWordle();
    static bool isEqualIgnoreCase(char& first, char& second);
};

#endif // WORDLECODE_H
