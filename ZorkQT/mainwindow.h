#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Room.h"
#include "item.h"
#include <QMainWindow>
#include<QPushButton>
#include <iostream>
#include <string>
using namespace std;

//bit structure- allows me to pack members inside a single byte and reduce overall size
struct Quantities{
        unsigned int knivesAvailable : 4;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
       Room *a, *b, *c, *d, *e,*f,*g,*h,*gameOver;
       WordleRoom *wordleRoom;
      static vector<Room*> Rooms;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static Room *getCurrentRoom();
    Room* nextRoom;
    static void deleteAll();
    static void addItem(Item*);
    static vector<Item*> getAllItems();

private slots:


    void on_Quit_clicked();  

    void on_northButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_southButton_clicked();

    void on_fight_clicked();

    void on_Search_clicked();

    void on_Unlock_clicked();

    void on_SolveWordle_clicked();

    void on_Map_2_clicked();

private:
           Ui::MainWindow *ui;
           QPushButton *push_button2;
           void startGame();
           void createRooms();
           void goRoom(string direction);         
           static vector<Room*> getRooms();
           static void setRooms(vector<Room*> rooms);
           static Room* currentRoom;
           static vector<Room*> allRooms;
           //array
           static bool knivesAvailable[1];

};
#endif // MAINWINDOW_H
