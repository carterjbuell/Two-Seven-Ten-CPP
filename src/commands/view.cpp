#include "../../include/commands/view.h"
#include "../../include/dealer.h"
#include <iostream>

bool ViewCommand::execute() {
  if (table) {
    Dealer::instance()->viewTable();
  } else {
    Dealer::instance()->view();
  }
  return true;
}

void ViewCommand::help() {
    std::cout << "view - show the cards in your hand\n";
    std::cout << "view table - show the cards on the table\n";
}

ViewCommand::ViewCommand(const std::deque<std::string> &params)
    : CommandImpl(), table(false) {
  // Parse command parameters
  if (params.size() > 1)
    throw std::length_error("invalid number of parameters (0 or 1)");
  if (!params.empty()) {
    std::string tmp = params[0];
    for (char &i : tmp) {
      i = tolower(i);
    }
    if (tmp == "table")
      table = true;
    else
      throw std::invalid_argument("invalid command argument");
  }
}