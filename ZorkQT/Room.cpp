#include "Room.h"
#include "ZorkUL.h"
#include <string.h>
#include "item.h"

Room::Room(string description,roomType, bool hasItem) {
    this->description = description;
    this->hasItem = hasItem;
}

//initialiser list setting what the description is
WordleRoom::WordleRoom(string description,roomType roomType)
    : Room( description,roomType){

}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exit["North"] = north;
    if (east != NULL)
        exit["East"] = east;
    if (south != NULL)
        exit["South"] = south;
    if (west != NULL)
        exit["West"] = west;
}

string Room::shortDescription() {
    return description;
}

//string Room::longDescription() {
//    return "room = " + description + ".\n"  + exitString();
//}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exit.begin(); i != exit.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string dir) {
    map<string, Room*>::iterator next = exit.find(dir); //returns an iterator for the "pair"
    if (next == exit.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

//Copy constructor
Room::Room(const Room &R1){
    if(hasItem){
        return;

    }
    else{
        this->itemsInRoom = R1.itemsInRoom;

    }
}

string Room::getShortDescription() {
    return description;
}


//making inline as used more than once
inline vector<Item*> Room::getItems(){
    return this->itemsInRoom;
}


Item* Room::getItemFromRoom()
{
    return roomItems;
}

Room::roomType Room::getroomType(){
    return this->typeOfRoom;
}

void Room::addItemsToRoom(Item *item1)
{
    this->roomItems = item1;
    this->hasItem = true;

}

//operator overloading to add item to room
void Room::operator+(Item *item1){
    this->addItemsToRoom(item1);
}

bool Room::checkItem()
{
    return hasItem;
}

void Room::setHasItem(bool flag)
{
    this->hasItem = flag;
}

Room::~Room(){
    for(auto& item : this->getItems()){
        delete item;
    }

    if(this->hasItem){
        delete roomItems;
    }

    this->getItems().clear();

}

bool Room::hasItems(){
    if(itemsInRoom.size() == 0){
        return false;
    }
    else{
        return true;
    }
}
