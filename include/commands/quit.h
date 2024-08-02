#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H

#include "command_impl.h"

class QuitCommand final : public CommandImpl {
public:
  ~QuitCommand() override = default;
  QuitCommand(const QuitCommand &) = default;
  QuitCommand &operator=(const QuitCommand &) = default;

  bool execute() override;

  static void help();

  friend class CommandFactory;

private:
  explicit QuitCommand(const std::deque<std::string> &params);
};

#endif // QUITCOMMAND_H
