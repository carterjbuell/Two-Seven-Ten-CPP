#include "../include/deck.h"
#include <algorithm>
#include <chrono>
#include <random>

// adds a card to the top of the deck
void Deck::addCard(const std::string &card) { cards.push_back(card); }

// takes a card off the top of the deck
// returns the card that was drawn
std::string Deck::drawCard() {
  if (!cards.empty()) {
    std::string top = cards.back();
    cards.pop_back();
    return top;
  }
  return "";
}

// returns the card at the top
std::string Deck::checkTop() {
  if (cards.empty())
    return "";
  return cards.back();
}

// shuffles the deck
void Deck::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(std::begin(cards), std::end(cards),
               std::default_random_engine(seed));
}

// returns size of deck
size_t Deck::size() { return cards.size(); }

std::string Deck::cardBelowSeven() {
  for (auto riter = cards.rbegin(); riter != cards.rend(); ++riter) {
    if (*riter != "7")
      return *riter;
  }
  return "";
}

void Deck::emptyDeck() { cards.clear(); }