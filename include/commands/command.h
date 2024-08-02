#ifndef COMMAND_H
#define COMMAND_H

#include "../../include/commands/command_impl.h"
#include <memory>

class CommandImpl;

class Command {
public:
  Command() = delete;
  Command(const Command &) = delete;
  Command &operator=(const Command &) = delete;
  ~Command() = default;
  bool execute() const;

private:
  friend class CommandFactory;
  explicit Command(CommandImpl *impl);
  std::shared_ptr<CommandImpl> bridge;
};

#endif // COMMAND_H
