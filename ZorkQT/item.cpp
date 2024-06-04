#ifndef ITEM_H_
#define ITEM_H_
#include "item.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

Item::Item()
{

}

Item::Item(string name, bool required)
{
    this->name = name;
    this->required = required;
}

string Item::getItemName()
{
    return name;
}


bool Item::isRequired()
{
    return required;
}

void Item::deleteThis()
{
    delete this;
}
#endif /*ITEM_H_*/
