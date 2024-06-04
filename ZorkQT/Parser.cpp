#include "Parser.h"

Parser::Parser() {
    commands = new CommandWords();
}

Parser::~Parser(){
    delete commands;
}

//used for the wordle code
Command* Parser::convertToCommand(string input){
    string word = "";
    vector<string> words;

    // Size type is an int used for the size of the string
    string::size_type pos = 0, last_pos = 0;
    // find first space.
    pos = input.find_first_of(' ', last_pos);
    // npos = no string found.
    if (pos == string::npos ) {
        // Gets only the first word
        words.push_back(input);
    } else {
        words.push_back(input.substr(0, pos));
        words.push_back(input.substr(pos + 1, input.size() - pos - 1));
    }

    if (words.size() == 1) //checks if only one word was entered
        word = words[0]; //gets word


    //  rest of the input line is ignored.
    // Now check whether this word is known. If so, create a command with it.
    // If not, create an empty string for unknown command.

    return new Command(word);
}
