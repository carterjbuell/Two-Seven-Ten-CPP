#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "command.h"
#include <deque>
#include <string>

class Dealer;
class CommandFactory {
public:
  CommandFactory() = default;
  Command makeCommand(const std::string &input);
  Command makeHelp(const std::deque<std::string> &params);
  Command makeQuit(const std::deque<std::string> &params);
  Command makePlay(const std::deque<std::string> &params);
  Command makeView(const std::deque<std::string> &params);

private:
  Dealer *dealer;
};
#endif // COMMAND_FACTORY_H
