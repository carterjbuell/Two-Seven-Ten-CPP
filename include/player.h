#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "list"
#include "string"

class Player {
public:
  Player() = default;
  Player(const Player &) = delete;
  Player &operator=(const Player &) = default;
  ~Player() = default;
  bool botTurn(size_t botNum);
  bool playCard(const std::string &);
  bool playHidden();
  void fill(Deck &deck);
  void pickUpDeck(Deck &deck);
  static size_t getRank(const std::string &);

private:
  Deck playerDeck;
  std::list<std::string> hand;
  std::list<std::string> hidden;
  std::list<std::string> shown;
  friend class Dealer;
  static bool isValid(const std::string &card);
};

#endif // PLAYER_H
