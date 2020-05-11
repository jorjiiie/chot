#include <string>
#include "board.h"
#include <iostream>

int main() {
  board game;
  game.startGame();
  std::cout << game.printBoard() << "\n";
  game.swp(0,1,2,0);
  std::cout << game.printBoard() << "\n";
  game.swp(1,1,3,1);
  std::cout << game.printBoard() << "\n";
  game.swp(3,1,4,1);
  std::cout << game.printBoard() << "\n";
  game.swp(2,0,3,1);
  std::cout << game.printBoard() << "\n";
  game.swp(2,0,4,1);
  std::cout << game.printBoard() << "\n";
}
