#include <string>
#include "board.h"
#include <iostream>

int main() {
  board game;
  game.startGame();
  std::cout << game.printBoard() << "\n";
}
