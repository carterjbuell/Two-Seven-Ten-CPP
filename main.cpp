#include "include/commands/command.h"
#include "include/commands/factory.h"
#include "include/dealer.h"
#include <iostream>
#include <memory>

int main() {
  std::cout << "Welcome to Two-Seven-Ten" << std::endl;
  std::cout << "Instructions:" << std::endl;
  std::cout << "Four players are each given a hand of 3 cards,";
  std::cout << "a small deck of face down cards to draw from,";
  std::cout << "three cards visible to the whole table,";
  std::cout << "and three cards face down so no one can see them." << std::endl;
  std::cout << "The first player places down any card in their hand then draws";
  std::cout << "cards from their deck to replenish the amount they played." << std::endl;
  std::cout << "A player can play multiple of the same numbered card." << std::endl;
  std::cout << "The next player has to play a card of equal or higher value (Aces are high) " << std::endl;
  std::cout << std::endl;
  std::cout << "Special Cards: These can all be player on top of any card " << std::endl;
  std::cout << "A 2 resets the pile to a value of 2 " << std::endl;
  std::cout << "A 7 acts as if no card was played and the next player plays based on the card before " << std::endl;
  std::cout << "A 10 bombs the pile, removing anything in it from the game " << std::endl;
  std::cout << "The player who plays the 10 can play another card after bombing the pile " << std::endl;
  std::cout << std::endl;
  std::cout << "Your three visible cards can only be played when your hand and deck are depleted " << std::endl;
  std::cout << "Your three hidden cards can be flipped and played one at a time once all other cards are all played";
  std::cout << std::endl;
  std::cout << "To win...get rid of all your cards" << std::endl;
  std::cout << std::endl;

  Dealer *dealer(Dealer::instance());
  CommandFactory factory;
  std::string input;
  Command help = factory.makeCommand("help");
  help.execute();
  std::cout << std::endl;
  Dealer::instance()->viewTable();
  std::cout << std::endl;
  Dealer::instance()->view();
  bool run = true;
  while (run) {
    std::getline(std::cin, input);
    if (std::cin.fail()) {
      std::cerr << "error getting input\n";
      std::terminate();
    }
    try {
      Command cmd = factory.makeCommand(input);
      run = cmd.execute();
    } catch (std::exception &ex) {
      std::cout << ex.what() << "\n";
    }
  }
  return 0;
}
