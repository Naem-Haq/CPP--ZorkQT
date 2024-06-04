#ifndef WORDLE_H
#define WORDLE_H
#include <QDialog>
#include <iostream>
#include <string>
#include <fstream>

using std::string;

namespace Ui {
class Wordle;
}

class Wordle : public QDialog
{
    Q_OBJECT

public:
    explicit Wordle(QWidget *parent = nullptr);
    ~Wordle();
    void clearConsole();
        void addStringToConsole(string input);
        void addQStringToConsole(QString input);
        void overwriteConsole(string input);
        void updateBackground(string path);
        void parseInput(string input);


private slots:


    void on_Quit_clicked();

    void on_input_textChanged();

private:
    Ui::Wordle *ui;

};

#endif // WORDLE_H
