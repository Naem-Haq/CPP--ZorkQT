#ifndef ROOM_H_
#define ROOM_H_
#include <map>
#include <string>
#include <vector>
#include "item.h"

using std::vector;
using namespace std;
using std::vector;

// Abstract class holding properties that rooms will have,ie. if it has an item and what type of room it will be
// using abstract class as base class for Room to inherit
class RoomProps{
public:
    //pure virtual function-
      virtual bool hasItems() = 0;
      enum roomType : int {PUZZLE = 1, REGULAR= 2};
};


//friend class of Mainwindow allowing it to access its private and protected members
class Room : public RoomProps {
    friend class MainWindow;


protected:
     vector <Item*> itemsInRoom;
     string description;
     map<string, Room*> exit;
     string exitString();
     roomType typeOfRoom;

public:
     //default parameters for the Room object
     Room(string description=" ",roomType=REGULAR, bool item=false); //constructor
     Room(const Room &R1);

     virtual ~Room();

     //a room can have an item,used a union in order to save some space in memory
     union {
              Item *roomItems;
    };

     //used for operator overloading
     void operator+(Item *item1);

     bool hasItem;
     int numberOfItems();
     void addItemsToRoom(Item *item1);
     void addItem(Item *item1);
     Item* getItemFromRoom();
     vector<Item*> getItems();
     bool checkItem();
     void setHasItem(bool flag);
     bool hasItems() override;

     void setExits(Room *north, Room *east, Room *south, Room *west);
     string shortDescription(); //name of the room
     //virtual as different room names to be displayed depending on type of room
     virtual string getShortDescription();
     //string longDescription(); //objective
     Room* nextRoom(string direction);
     roomType getroomType();

};

//inheritence-WordleRoom is sub class of Room
class WordleRoom : public Room{
public:
    WordleRoom(string description,roomType=PUZZLE);
};

#endif
