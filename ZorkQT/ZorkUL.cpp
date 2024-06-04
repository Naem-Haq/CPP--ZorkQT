#include <iostream>
#include "Room.h"
#include "mainwindow.h"
#include "wordle.h"
#include "item.h"
#include <cstdlib>
#include <QApplication>
#include <QTextStream>
#include <QDebug>
using namespace std;
#include "ZorkUL.h"

//defining the static variable
Parser *ZorkUL::parser;

int main(int argc, char *argv[]) {

        QApplication a(argc, argv);
        MainWindow w;

        Parser* parser = new Parser();
        WordleCode *worldleCode = new WordleCode();
        ZorkUL::setParser(parser);
        w.show();

      // w.setWindowState(Qt::WindowMaximized);
        delete worldleCode;
        delete ZorkUL::getParser();
        return a.exec();
    }

/**
 * Given a command in the wordle game the code goes through the process of executing that command
 */
string ZorkUL::convertCommand(Command command, Wordle *window) {
    string output = "";
    // In the Wordle game, the command input is used as a try in Wordle
    if(WordleCode::getStatus() == WordleCode::WORDLE_CURRENT){
        output += WordleCode::checkInput(command.getCommandWord());

        if(WordleCode::getStatus() == WordleCode::WORDLE_CURRENT){
            return output;
        }
        // If it's a success, the following text is displayed and the player can press the quit button safely
        else if(WordleCode::getStatus() == WordleCode::WORDLE_COMPLETED){
            output += " After a minute a knife is dispensed from the machine,you pick it up wearily and continue on your way. Press exit to continue. ";
        }
    }   
    return output;
}


void ZorkUL::setParser(Parser *parser){
   ZorkUL::parser = parser;
}

//making function inline as its called many times and is small
inline Parser* ZorkUL::getParser(){
    return ZorkUL::parser;
}


//no longer using the teleport function but left code in

/*void ZorkUL::teleport(string room){
    if (room.compare("rand")==0){
        unsigned int roomSize = rooms.size();
        unsigned int randRoom = rand() % roomSize;
        currentRoom = rooms[randRoom];
    }
    else{
           for (unsigned int i = 0; i < rooms.size(); i++)
           {
               if (rooms[i]->shortDescription().compare(room) == 0)
                   currentRoom = rooms[i];
           }
}
}*/
//Room ZorkUL::randomRoom() {
 //   int choice = rand() % 10;
//    return rooms[choice];
//}

