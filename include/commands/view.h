#ifndef VIEWCOMMAND_H
#define VIEWCOMMAND_H

#include "command_impl.h"

class ViewCommand final : public CommandImpl {
public:
  ~ViewCommand() override = default;
  ViewCommand(const ViewCommand &) = default;
  ViewCommand &operator=(const ViewCommand &) = default;

  bool execute() override;

  static void help();

  friend class CommandFactory;

private:
  explicit ViewCommand(const std::deque<std::string> &params);
  bool table;
};

#endif // VIEWCOMMAND_H
