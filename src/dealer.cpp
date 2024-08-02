
#include "../include/dealer.h"
#include <iostream>
#include <string>

Dealer *Dealer::inst = nullptr;

Dealer::Dealer() : bot1(), bot2(), bot3(), player(), mainDeck() {
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 2; j <= 9; ++j) {
      mainDeck.addCard(std::to_string(j));
    }
    mainDeck.addCard("10");
    mainDeck.addCard("J");
    mainDeck.addCard("Q");
    mainDeck.addCard("K");
    mainDeck.addCard("A");
  }
  mainDeck.shuffle();

  bot1.fill(mainDeck);
  bot2.fill(mainDeck);
  bot3.fill(mainDeck);
  player.fill(mainDeck);
}

Dealer *Dealer::instance() {
  if (inst == nullptr) {
    inst = new Dealer();
  }
  return inst;
}

Dealer::~Dealer() { inst = nullptr; }

void Dealer::addCard(const std::string &card) { mainDeck.addCard(card); }

void Dealer::viewTable() {
  std::cout << "Player Shown Cards:";
  for (const auto &s : player.shown) {
    std::cout << " [" << s << "] ";
  }
  std::cout << std::endl;
  if (player.shown.empty())
    std::cout << player.hidden.size() << " hidden cards left" << std::endl;


  std::cout << "Bot 1 Shown Cards: ";
  for (const auto &i : bot1.shown) {
    std::cout << " [" << i << "] ";
  }
  std::cout << std::endl;
  if (bot1.shown.empty())
    std::cout << bot1.hidden.size() << " hidden cards left" << std::endl;


  std::cout << "Bot 2 Shown Cards: ";
  for (const auto &j : bot2.shown) {
    std::cout << " [" << j << "] ";
  }
  std::cout << std::endl;
  if (bot2.shown.empty())
    std::cout << bot2.hidden.size() << " hidden cards left" << std::endl;


  std::cout << "Bot 3 Shown Cards: ";
  for (const auto &k : bot3.shown) {
    std::cout << " [" << k << "] ";
  }
  std::cout << std::endl;
  if (bot3.shown.empty())
    std::cout << bot3.hidden.size() << " hidden cards left" << std::endl;
}

void Dealer::view() {
  std::cout << "Current Card On Deck:";
  std::cout << " [" << mainDeck.checkTop() << "] " << std::endl;
  if (mainDeck.checkTop() == "7") {
    std::cout << "The Card Under the 7 is";
    std::cout << " [" << cardBelowSeven() << "] " << std::endl;
  }
  std::cout << "Player Hand:";
  for (auto h : player.hand) {
    std::cout << " [" << h << "] ";
  }
  std::cout << std::endl;
  if (player.hand.empty()) {
      std::cout << "Player Shown Cards:";
      for (const auto &s : player.shown) {
          std::cout << " [" << s << "] ";
      }
      std::cout << std::endl;
      if (player.shown.empty())
          std::cout << player.hidden.size() << " hidden cards left" << std::endl;
  }
}

bool Dealer::playTurn(const std::string &card) {
  bool played = player.playCard(card);
  if (played) {

      if (player.hidden.empty()) {
          winner(0);
          return true;
      }

    while (!bot1.botTurn(1)) {
      bot1.pickUpDeck(mainDeck);
    }

      if (bot1.hidden.empty()) {
          winner(1);
          return true;
      }

    while (!bot2.botTurn(2)) {
      bot2.pickUpDeck(mainDeck);
    }

      if (bot2.hidden.empty()) {
          winner(2);
          return true;
      }

    while (!bot3.botTurn(3)) {
      bot3.pickUpDeck(mainDeck);
    }


    if (bot3.hidden.empty()) {
      winner(3);
      return true;
    }

    for (const auto &i : player.hand) {
      if (Player::isValid(i))
        return true;
    }
    if (player.hand.empty()) {
      for (const auto &i : player.shown) {
        if (Player::isValid(i))
          return true;
      }
    }
    if (player.shown.empty())
      return true;
    player.pickUpDeck(mainDeck);
    std::cout << "Player had no valid moves and thus picked up the deck!"
              << std::endl;
  }

  return played;
}

std::string Dealer::checkTop() { return mainDeck.checkTop(); }

std::string Dealer::cardBelowSeven() { return mainDeck.cardBelowSeven(); }

void Dealer::boom() {
  std::cout << "BOOM!!! Play Another Card!" << std::endl;
  mainDeck.emptyDeck();
}

void Dealer::winner(size_t playerNum) {
  if (playerNum == 0) {
    std::cout << "Congratulations!! You win!!" << std::endl << std::endl;;
  } else {
    std::cout << "Bot " << playerNum << " has won!!" << std::endl << std::endl;;
  }
  std::cout << "----------[ Resetting Game Now ]----------" << std::endl << std::endl;
  bot1 = Player();
  bot2 = Player();
  bot3 = Player();
  player = Player();
  mainDeck = Deck();
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 2; j <= 9; ++j) {
      mainDeck.addCard(std::to_string(j));
    }
    mainDeck.addCard("10");
    mainDeck.addCard("J");
    mainDeck.addCard("Q");
    mainDeck.addCard("K");
    mainDeck.addCard("A");
  }
  mainDeck.shuffle();

  bot1.fill(mainDeck);
  bot2.fill(mainDeck);
  bot3.fill(mainDeck);
  player.fill(mainDeck);
  viewTable();
}