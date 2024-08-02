#ifndef BOT_H
#define BOT_H

#include "deck.h"
#include "set"

class Bot {
public:
  Bot() = default;
  Bot(const Bot &) = delete;
  Bot &operator=(const Bot &) = delete;
  ~Bot() = default;
  void botTurn();

private:
  Deck botDeck;
  std::multiset<char> hand;
  std::multiset<char> hidden;
  std::multiset<char> shown;
};

#endif // BOT_H
