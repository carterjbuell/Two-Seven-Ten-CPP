// Created by Carter Buell on 5/7/2024

#ifndef DECK_H
#define DECK_H

#include "vector"
#include <string>

class Deck {
public:
  Deck() = default;
  Deck(const Deck &) = delete;
  Deck &operator=(const Deck &) = default;
  ~Deck() = default;
  std::string drawCard();
  std::string checkTop();
  void emptyDeck();
  void addCard(const std::string &card);
  std::string cardBelowSeven();
  void shuffle();
  size_t size();

private:
  std::vector<std::string> cards;
};

#endif // DECK_H
