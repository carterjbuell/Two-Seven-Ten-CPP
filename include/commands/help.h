#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "command_impl.h"
#include <memory>

class HelpCommand final : public CommandImpl {
public:
  HelpCommand() = delete;
  ~HelpCommand() override = default;
  HelpCommand(const HelpCommand &) = default;
  HelpCommand &operator=(const HelpCommand &) = default;

  bool execute();

  static void help();

  friend class CommandFactory;

private:
  explicit HelpCommand(const std::deque<std::string> &params);

  std::string commandName;
};

#endif // HELPCOMMAND_H
