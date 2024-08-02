#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include "command_impl.h"

class PlayCommand final : public CommandImpl {
public:
  ~PlayCommand() override = default;
  PlayCommand(const PlayCommand &) = default;
  PlayCommand &operator=(const PlayCommand &) = default;

  bool execute();

  static void help();

  friend class CommandFactory;

private:
  explicit PlayCommand(const std::deque<std::string> &params);
  std::string playedCard;
};

#endif // PLAYCOMMAND_H
