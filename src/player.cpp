#include "../include/player.h"
#include "../include/dealer.h"
#include <algorithm>
#include <iostream>

bool Player::playCard(const std::string &card) {
  if (card == "HIDDEN") {
    bool played = playHidden();
    if (played || Dealer::instance()->checkTop() == "10") {
        std::cout << "Player Played: " << Dealer::instance()->checkTop() << std::endl;
    } else {
      std::cout << "The Hidden Card was a " << Dealer::instance()->checkTop()
                << std::endl;
      std::cout << "It wasn't good enough. Player picked up the deck!"
                << std::endl;
    }
    return true;
  }

  if (!isValid(card))
    return false;

  bool cardFound = false;
  if (!hand.empty()) {
    for (const auto &i : hand) {
      if (i == card) {
        cardFound = true;
        Dealer::instance()->addCard(card);
      }
    }
    hand.remove(card);
  } else if (!shown.empty()) {
    for (const auto &i : shown) {
      if (i == card) {
        cardFound = true;
        Dealer::instance()->addCard(card);
      }
    }
    shown.remove(card);
  }

  while (hand.size() < 3 && playerDeck.size() != 0) {
    hand.push_front(playerDeck.drawCard());
  }

  if (card == "10") {
    Dealer::instance()->boom();
    return false;
  }

  return cardFound;
}

bool Player::botTurn(size_t botNum) {
  std::string card;
  auto cardCompare = [&](const std::string &a, const std::string &b) {
    return getRank(a) < getRank(b);
  };
  if (!hand.empty()) {
    hand.sort(cardCompare);
    for (const auto &i : hand) {
      if (card.empty() && isValid(i)) {
        card = i;
      }
      if (i == card) {
        Dealer::instance()->addCard(card);
      }
    }
    hand.remove(card);
  } else if (!shown.empty()) {
    shown.sort(cardCompare);
    for (const auto &i : shown) {
      if (card.empty() && isValid(i)) {
        card = i;
      }
      if (i == card) {
        Dealer::instance()->addCard(card);
      }
    }
    shown.remove(card);
  } else {
    bool played = playHidden();
    if (played || Dealer::instance()->checkTop() == "10")
      std::cout << "Bot " << botNum
                << " Played: " << Dealer::instance()->checkTop() << std::endl;
    else
      std::cout << "Bot " << botNum << " picked up the deck!" << std::endl;
    return played;
  }

  while (hand.size() < 3 && playerDeck.size() != 0) {
    hand.push_back(playerDeck.drawCard());
  }

  if (card.empty())
    std::cout << "Bot " << botNum << " picked up the deck!" << std::endl;
  else
    std::cout << "Bot " << botNum << " Played: " << card << std::endl;

  if (card == "10") {
    Dealer::instance()->boom();
    return false;
  }

  return !card.empty();
}

bool Player::playHidden() {
    std::string card;
    card = *hidden.begin();
  if (card == "10") {
    hidden.erase(hidden.begin());
    Dealer::instance()->boom();
    return true;
  }
  Dealer::instance()->addCard(card);
  hidden.erase(hidden.begin());
  if (isValid(card)) {
    return true;
  }
  pickUpDeck(Dealer::instance()->mainDeck);
  return false;
}

void Player::fill(Deck &deck) {
  for (size_t i = 0; i < 3; ++i) {
    hidden.push_back(deck.drawCard());
    shown.push_back(deck.drawCard());
    hand.push_back(deck.drawCard());
    playerDeck.addCard(deck.drawCard());
  }
  playerDeck.addCard(deck.drawCard());
}

void Player::pickUpDeck(Deck &deck) {
  for (size_t i = 0; i < deck.size(); ++i) {
    hand.push_back(deck.drawCard());
  }
}

bool Player::isValid(const std::string &card) {
  std::string top = Dealer::instance()->checkTop();
  if (top == "7")
    top = Dealer::instance()->cardBelowSeven();

  if (top.empty() || top == "2" || card == "2" || card == "7" || card == "10")
    return true;

  return getRank(card) >= getRank(top);
}

size_t Player::getRank(const std::string &card) {
  if (card == "3")
    return 1;
  if (card == "4")
    return 2;
  if (card == "5")
    return 3;
  if (card == "6")
    return 4;
  if (card == "8")
    return 5;
  if (card == "9")
    return 6;
  if (card == "J")
    return 7;
  if (card == "Q")
    return 8;
  if (card == "K")
    return 9;
  if (card == "A")
    return 10;
  if (card == "2")
    return 11;
  if (card == "7")
    return 12;
  if (card == "10")
    return 13;
  return 0;
}
