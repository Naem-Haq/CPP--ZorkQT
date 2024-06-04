#include <iostream>
#include <fstream>
#include <string>
#include "ZorkUL.h"
#include "wordle.h"
#include "wordleCode.h"
#include "ui_wordle.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QKeyEvent>
#include <QScrollBar>


Wordle::Wordle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wordle)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/logo.png"));
     ui->outputConsole->setWordWrap(true);
     WordleCode::initialiseWordle();
     WordleCode::startWordleGame();
}

Wordle::~Wordle()
{
    delete ui;
}


void Wordle::clearConsole(){
    ui->outputConsole->clear();
}

void Wordle ::addStringToConsole(string input){
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + QString::fromStdString(input));
}

void Wordle::addQStringToConsole(QString input){
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + input);
}

void Wordle::overwriteConsole(string input){
    ui->outputConsole->clear();
    addStringToConsole(input);
}

// whatever you input is converted to a command and ran through the wordle code
void Wordle::parseInput(string input){
    Command *command = ZorkUL::getParser()->convertToCommand(input);
    // addStringToConsole(" " + your input + "\n");
    overwriteConsole(" " + input + "\n");
    string output = ZorkUL::convertCommand(*command, this);
    // if the command does not suit the wordle code print an error message
    if(output.compare("") == 0){        
        overwriteConsole("Error ");
        return;
    }
    overwriteConsole(output);
       delete command;
       ui->input->setFocus();
   }
/**
 * is the wordle game has been completed succesfully window can be closed and the game can be continued
 * otherwise pressing quite button will terminate the program as you have failed the game by giving up or dying
 */
void Wordle::on_Quit_clicked()
{    
   if (WordleCode::getStatus() == WordleCode::WORDLE_COMPLETED){
    Wordle::close();
   } else{
     exit(0);

   }
}

// basically handles what happens after the enter key is pressed after typing in the text edit box
void Wordle::on_input_textChanged()
{
    // Converting from QString to string    
       string input = ui->input->toPlainText().toStdString();
       // newLineIndex is for after enter is pressed
       size_t newlineIndex = input.find('\n');

       // not allowing you to enter more than one line
       if(newlineIndex == 0){
           ui->input->clear();
           return;
       }

       // Removing the line thats new from the string
       input = input.substr(0, newlineIndex);

       // Checks if there are any newlines/if the "enter" key is pressed
       if(newlineIndex != string::npos && input.size() > 0){           
           this->parseInput(input);
           ui->input->clear();
       }      
   }


