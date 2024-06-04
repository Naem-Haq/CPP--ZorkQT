#include "Command.h"

/**
 * Create a command object. First word must be supplied, but
 *  can be null. The command word should be null to
 * indicate that this was a command that is not recognised by this game.
 * A c++ reference as the commandWord is a string initialised to firstWord
 *
 */

Command::Command(const string& firstWord) {
    this->commandWord = firstWord;

}

/**
 * Return the command word (the first word) of this command. If the
 * command was not understood, the result is null.
 */
string Command::getCommandWord() {
    return this->commandWord;
}




/**
 * Return true if this command was not understood.
 */
bool Command::isUnknown() {
    return (commandWord.empty());
}


