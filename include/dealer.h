#ifndef DEALER_H
#define DEALER_H

#include "bot.h"
#include "dealer.h"
#include "deck.h"
#include "player.h"
#include "vector"

class Dealer {
public:
  static Dealer *instance();
  ~Dealer();
  Dealer(const Dealer &) = delete;
  Dealer &operator=(const Dealer &) = delete;
  void addCard(const std::string &card);
  bool playTurn(const std::string &card);
  std::string checkTop();
  void viewTable();
  void view();
  void boom();
  std::string cardBelowSeven();
  Deck mainDeck;

private:
  Dealer();
  static Dealer *inst;
  Player bot1;
  Player bot2;
  Player bot3;
  Player player;
  void winner(size_t playerNum);
};

#endif // DEALER_H
