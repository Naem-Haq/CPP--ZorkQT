#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "wordleCode.h"
#include "mainwindow.h"
#include "wordle.h"
#include "Parser.h"

#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
       //making static,only one instance of it
     static Parser *parser;


public:
    ZorkUL();
    void play();   
    static string convertCommand(Command command, Wordle *window);
    string go(string direction);   
    static void setParser(Parser* parser);
     static Parser* getParser();
    static bool compareIgnoreCase(string a, string b);
    static string stringToLower(string a);
};

#endif /*ZORKUL_H_*/
