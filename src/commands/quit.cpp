#include "../../include/commands/quit.h"
#include <iostream>
#include <memory>

bool QuitCommand::execute() {
  std::cout << "Quitting Game...Goodbye!!!\n";
  return false;
}

void QuitCommand::help() { std::cout << "quit - quit the game\n"; }

QuitCommand::QuitCommand(const std::deque<std::string> &) : CommandImpl() {}
