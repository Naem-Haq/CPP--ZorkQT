#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wordle.h"
#include "ZorkUL.h"
#include "Command.h"


 vector<Room*> MainWindow::Rooms;
 Room *MainWindow::currentRoom;
 bool MainWindow::knivesAvailable[1];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    setWindowIcon(QIcon(":/images/logo.png"));   
    setWindowTitle("Welcome to Zork 2:Electric Boogaloo");
    setFixedSize(geometry().width(),geometry().height());

     startGame();

}

void MainWindow::startGame()
{

     createRooms();
     ui->photoWidget->setCurrentIndex(0);
     ui->interactWidget->setCurrentIndex(1);
     ui->itemWidget_2->setCurrentIndex(0);
}
/**
 * creates all rooms and place them into "Rooms"
 * also sets the exits for these rooms and intialises two items and places them into rooms
 */
void MainWindow::createRooms()
{
   // vector<Room*> MainWindow::Rooms;
    a = new Room("A - Dark Street/Start Point");
    wordleRoom = new WordleRoom("The ultimate Wordle door");
    b = new Room("B - Bar Entrance");
    c = new Room("C - Bar");
    d = new Room("D - Alleyway");
    e = new Room("E - 24/7 Shop");
    f = new Room("F - Danger Alley");
    g = new Room("G - End screen");
    h = new Room("H - Inside of store");

    //(N, E, S, W)
    a->setExits(wordleRoom, NULL, NULL, NULL);
    wordleRoom->setExits(b,NULL,a,NULL);
    b->setExits(c, e, wordleRoom, d);
    c->setExits(NULL, NULL, b, NULL);
    d->setExits(f,b, NULL, NULL);
    e->setExits(h, NULL, NULL, b);
    f->setExits(gameOver,NULL, d, NULL);
    g->setExits(NULL, NULL, NULL, NULL);
    h->setExits(NULL,NULL,e,NULL);
    gameOver->setExits(NULL,NULL,NULL,NULL);    
    currentRoom = a;

    Rooms.push_back(a);
    Rooms.push_back(wordleRoom);
    Rooms.push_back(b);
    Rooms.push_back(c);
    Rooms.push_back(d);
    Rooms.push_back(e);
    Rooms.push_back(f);
    Rooms.push_back(g);
    Rooms.push_back(h);
    Rooms.push_back(gameOver);


    Item *key;
    Item *knife;
    key = new Item("Key", true);
    knife = new Item("Knife", true);
    wordleRoom->addItemsToRoom(knife);
    d->addItemsToRoom(key);
    currentRoom =a;
}

void MainWindow::setRooms(vector<Room *> rooms){
   MainWindow::Rooms = rooms;
}

vector<Room*> MainWindow::getRooms(){
    return MainWindow::Rooms;
}

void MainWindow::deleteAll(){
    currentRoom = NULL;

    for(auto& room : MainWindow::getRooms()){
        delete room;
    }
    MainWindow::getRooms().clear();
}

void MainWindow::goRoom(string direction)
{
    nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        ui->textEdit->setText(QString::fromStdString("Invalid Move"));
    }
    else
    {
        currentRoom = nextRoom;
        ui->textEdit->setText(QString::fromStdString("Current Room: " + currentRoom->shortDescription()));


    }

}

// Deletes "Room" and the ui when terminated
MainWindow::~MainWindow()
{
    for(auto& room :MainWindow::getRooms()){
            delete room;
        }
   MainWindow::getRooms().clear();

    delete ui;
}


void MainWindow::on_Quit_clicked()
{
   MainWindow::close();
}

/**
 * when the north button is pressed checks which room you are in
 * and changes the textWidget,photoWidget and interactWidget accordingly
 * also goes in direction of button pressed
 *
 */
void MainWindow::on_northButton_clicked()
{
    if (currentRoom == a) {
   ui->photoWidget->setCurrentIndex(1);
    ui->textWidget->setCurrentIndex(1);
    if(wordleRoom->hasItem){
     ui->interactWidget->setCurrentIndex(4);
}
    }
    if (currentRoom == wordleRoom )  {

         ui->photoWidget->setCurrentIndex(2);
         ui->textWidget->setCurrentIndex(2);
         ui->interactWidget->setCurrentIndex(1);

     }
    if (currentRoom == b )  {

         ui->photoWidget->setCurrentIndex(3);
         ui->textWidget->setCurrentIndex(3);
        if(d->checkItem()==false){
       ui->interactWidget->setCurrentIndex(3);
     }
}
if (currentRoom == d) {
        ui->photoWidget->setCurrentIndex(5);
         ui->textWidget->setCurrentIndex(5);
         ui->interactWidget->setCurrentIndex(0);
    } if (currentRoom ==e) {
        ui->photoWidget->setCurrentIndex(8);
         ui->textWidget->setCurrentIndex(8);
    }
     if (currentRoom ==g) {
             MainWindow::close();
         }
     goRoom("North");
}

/**
 * when the west button is pressed checks which room you are in
 * and changes the textWidget,photoWidget and interactWidget accordingly
 * also goes in direction of button pressed
 *
 */
void MainWindow::on_westButton_clicked()
{

     if (currentRoom == b ) {
         ui->photoWidget->setCurrentIndex(4);
         ui->textWidget->setCurrentIndex(4);
         if(d->hasItem){
             ui->interactWidget->setCurrentIndex(2);
        }
      }
     if (currentRoom == e) {
         ui->photoWidget->setCurrentIndex(2);
         ui->textWidget->setCurrentIndex(2);
}
 goRoom("West");
}


/**
 * when the east button is pressed checks which room you are in
 * and changes the textWidget,photoWidget and interactWidget accordingly
 * also goes in direction of button pressed
 *
 */
void MainWindow::on_eastButton_clicked()
{

     if (currentRoom == b) {
         ui->photoWidget->setCurrentIndex(7);
         ui->textWidget->setCurrentIndex(7);
     }
           if (currentRoom == d) {
               ui->photoWidget->setCurrentIndex(2);
               ui->textWidget->setCurrentIndex(2);
}
 goRoom("East");
}

/**
 * when the south button is pressed checks which room you are in
 * and changes the textWidget,photoWidget and interactWidget accordingly
 * also goes in direction of button pressed
 *
 */
void MainWindow::on_southButton_clicked()
{
    if (currentRoom == b) {
         ui->photoWidget->setCurrentIndex(1);
         ui->textWidget->setCurrentIndex(1);
         if(wordleRoom->hasItem){
          ui->interactWidget->setCurrentIndex(4);
     }

    }
    if (currentRoom == c) {
         ui->photoWidget->setCurrentIndex(2);
         ui->textWidget->setCurrentIndex(2);
         ui->interactWidget->setCurrentIndex(1);
    } if (currentRoom == wordleRoom ) {
        ui->photoWidget->setCurrentIndex(0);
         ui->textWidget->setCurrentIndex(0);
         ui->interactWidget->setCurrentIndex(1);
    }
      if (currentRoom == g) {
         ui->photoWidget->setCurrentIndex(3);
         ui->textWidget->setCurrentIndex(3);
    }
      if (currentRoom == f) {
          ui->photoWidget->setCurrentIndex(4);
          ui->textWidget->setCurrentIndex(4);
          ui->interactWidget->setCurrentIndex(1);
         if(d->hasItem){
             ui->interactWidget->setCurrentIndex(2);
        }

    } if (currentRoom == h) {
         ui->photoWidget->setCurrentIndex(7);
         ui->textWidget->setCurrentIndex(7);
    }
         goRoom("South");

}


/**
 * if player has completed wordle they will be allowed pass the fight and win game
 * if player has not completed wordle they will lose game and go to gameOver screen
 */
void MainWindow::on_fight_clicked()
{
    if(wordleRoom->checkItem()==false){
        ui->photoWidget->setCurrentIndex(6);
        ui->textWidget->setCurrentIndex(6);
        ui->interactWidget->setCurrentIndex(1);
        goRoom("g");
        ui->gridWidget->deleteLater();

    } else {
     ui->photoWidget->setCurrentIndex(9);
     ui->textWidget->setCurrentIndex(9);
     ui->gridWidget->deleteLater();
    }
    goRoom("gameOver");
}

/**
 * if in correct room and key is present a key image will appear in inventory screen
 */

void MainWindow::on_Search_clicked()
{

    if(currentRoom->checkItem()){
            if (currentRoom->getItemFromRoom()->getItemName() == "Key"){
          ui->itemWidget->setCurrentIndex(1);

}
           currentRoom->setHasItem(false);
           ui->interactWidget->setCurrentIndex(1);

    }
}

/**
 * if search has already been pressed unlock button will appear
 * if in correct room key will work and you will be brought to victory screen
 * Option to move rooms will then be removed
 */
void MainWindow::on_Unlock_clicked()
{
   if(currentRoom==c){
       ui->photoWidget->setCurrentIndex(6);
       ui->textWidget->setCurrentIndex(6);
       ui->interactWidget->setCurrentIndex(1);
       ui->gridWidget->deleteLater();
       goRoom("g");

   }

}

/**
 * if in correct room when button is pressed a new wordle window will open up
 * item will also be removed from room
 */

void MainWindow::on_SolveWordle_clicked()
{

   if(currentRoom == wordleRoom){
  Wordle wordle;
  wordle.setModal(true);
  wordle.exec();
  currentRoom->setHasItem(false);
  ui->itemWidget_2->setCurrentIndex(1);
    }

}
/**
 * if button is pressed an image of the map will show on screen
 */
void MainWindow::on_Map_2_clicked()
{
  ui->photoWidget->setCurrentIndex(10);
}

