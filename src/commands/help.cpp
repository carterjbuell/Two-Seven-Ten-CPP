
#include "../../include/commands/help.h"
#include "../../include/commands/play.h"
#include "../../include/commands/quit.h"
#include "../../include/commands/view.h"
#include <iostream>

bool HelpCommand::execute() {
  if (commandName.empty()) {
    std::cout << "Available commands:\n";
    std::cout << "help - list all commands\n";
    std::cout << "help [command] - display help for a given command\n";
    std::cout << "quit - quit the game\n";
    std::cout << "view - show the cards in your hand\n";
    std::cout << "view table - show the cards on the table\n";
    std::cout << "play [card] - plays a card. Ex: play A or play 2 (not case sensitive)\n";
    std::cout << "play hidden - plays a hidden card (only when all visible cards have been played\n";
  } else {
    if (commandName == "help")
      HelpCommand::help();
    else if (commandName == "quit")
      QuitCommand::help();
    else if (commandName == "view")
      ViewCommand::help();
    else if (commandName == "play")
      PlayCommand::help();
    else
      throw std::logic_error("unknown command: " + commandName);
  }
  return true;
}

void HelpCommand::help() {
  std::cout << "help - list all commands\n";
  std::cout << "help [command] - display help for a given command\n";
}

HelpCommand::HelpCommand(const std::deque<std::string> &params)
    : CommandImpl(), commandName() {
  // Parse command parameters
  if (params.size() > 1)
    throw std::length_error("invalid number of parameters (0 or 1)");
  if (!params.empty()) {
    commandName = params[0];
    for (char &i : commandName) {
      i = tolower(i);
    }
  }
}
