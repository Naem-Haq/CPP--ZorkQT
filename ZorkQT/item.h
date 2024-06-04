#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string name;
    bool required;

public:
    Item();
       Item(string name, bool  required);
       string getItemName();
       bool isRequired();
       void deleteThis();
};

#endif /*ITEM_H_*/
