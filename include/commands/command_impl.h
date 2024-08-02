#ifndef COMMAND_IMPL_H
#define COMMAND_IMPL_H

#include <deque>
#include <memory>
#include <ostream>

class Dealer;
class CommandImpl {
public:
  CommandImpl() = default;
  virtual ~CommandImpl() = default;
  virtual bool execute() = 0;
};

#endif // COMMAND_IMPL_H
