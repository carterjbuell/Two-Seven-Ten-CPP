#include "../../include/commands/factory.h"
#include "../../include/commands/help.h"
#include "../../include/commands/play.h"
#include "../../include/commands/quit.h"
#include "../../include/commands/view.h"
#include <stdexcept>

// Source:
// https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
size_t split(const std::string &txt, std::deque<std::string> &strs, char ch) {
  size_t pos = txt.find(ch);
  size_t initialPos = 0;
  strs.clear();

  // Decompose statement
  while (pos != std::string::npos) {
    strs.push_back(txt.substr(initialPos, pos - initialPos));
    initialPos = pos + 1;
    pos = txt.find(ch, initialPos);
  }

  // Add the last one
  strs.push_back(
      txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

  return strs.size();
}

Command CommandFactory::makeCommand(const std::string &input) {
  std::deque<std::string> params;
  split(input, params, ' ');
  if (input != "") {
    for (size_t i = 0; i < params.size(); ++i) {
      for (size_t j = 0; j < params[i].size(); j++) {
        params[i][j] = std::tolower(params[i][j]);
      }
    }

    std::string command;
    command = params.front();
    params.pop_front();
    if (command == "help") {
      return makeHelp(params);
    } else if (command == "quit") {
      return makeQuit(params);
    } else if (command == "play") {
      return makePlay(params);
    } else if (command == "view") {
      return makeView(params);
    } else {
      throw std::logic_error("unrecognized command");
    }
  } else {
    throw std::logic_error("use quit command to exit");
  }
}

Command CommandFactory::makeHelp(const std::deque<std::string> &params) {
  return Command(new HelpCommand(params));
}

Command CommandFactory::makeQuit(const std::deque<std::string> &params) {
  return Command(new QuitCommand(params));
}

Command CommandFactory::makePlay(const std::deque<std::string> &params) {
  return Command(new PlayCommand(params));
}

Command CommandFactory::makeView(const std::deque<std::string> &params) {
  return Command(new ViewCommand(params));
}
