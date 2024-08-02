#include "../../include/commands/play.h"
#include "../../include/dealer.h"
#include <algorithm>
#include <iostream>
#include <memory>

bool PlayCommand::execute() {
  if (!Dealer::instance()->playTurn(playedCard)) {
    if (!Dealer::instance()->checkTop().empty())
      throw std::invalid_argument("Invalid play: Try again please!!!");
  }
  Dealer::instance()->view();
  return true;
}

void PlayCommand::help() {
  std::cout << "play [card] - plays a card. Ex: play A or play 2 (not case "
               "sensitive)\n";
  std::cout << "play hidden - plays a hidden card (only when all visible cards "
               "have been played\n";
}

PlayCommand::PlayCommand(const std::deque<std::string> &params)
    : CommandImpl() {
  // Parse command parameters
  if (params.size() != 1)
    throw std::length_error("invalid number of parameters (1)");
  std::string card = params[0];
  std::transform(card.begin(), card.end(), card.begin(), ::toupper);
  if (card != "2" && card != "3" && card != "4" && card != "5" && card != "6" &&
      card != "7" && card != "8" && card != "9" && card != "10" &&
      card != "HIDDEN" && card != "J" && card != "K" && card != "Q" &&
      card != "A") {
    throw std::invalid_argument("invalid command argument (" + card +
                                " is not a card)");
  }
  playedCard = card;
}
