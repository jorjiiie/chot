#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "legal.h"

class board {
 int pos[8][8][2],atk[8][8][2];
 public:
   std::string printBoard(void); // print board
   void startGame(void); // starts game with default setup
   void setPos(int, int, int, int); // testing method to just throw something somewhere (swp without legal checking)
   void swp(int, int, int, int); // swap , also the move
   std::vector<bool> getMoves(int); // get valid types of moves
   int retLoc(int, int); // return the piece at a certain position (no team)
   std::string printRaw(void); // printing the board without color or side stuff

};


std::string board::printRaw() {
  std::string ret = "";
  for (int i = 0; i < 8; i++) {
    for (int a = 0; a < 8; a++) {
      ret+= std::to_string(pos[i][a][0]) + " ";
    }
    ret+="\n";
  }
  return ret;
}

int board::retLoc(int x, int y) {
  return pos[7-x][y][0];
}

std::vector<bool> board::getMoves(int id) {
  bool diag,straight,horse,pawn,king;
  diag = straight = horse = pawn = king = false;
  switch (id) {
    case 1:
      pawn = true;
      break;
    case 2:
      diag = true;
      break;
    case 3:
      horse = true;
      break;
    case 4:
      straight = true;
      break;
    case 5:
      diag = true;
      straight = true;
      break;
    case 6:
      king = true;
      break;
  }
  std::vector<bool> ret = {diag, straight, horse, pawn, king};
  return ret;
}


void board::swp(int x, int y, int a, int b) {
  if (x > 7 || x < 0 || y > 7 || y < 0|| a > 7 || a < 0 || b > 7 || b < 0) return;
  if (legal(pos[7-x][y][0],x,y,a,b)) {
    a = 7-a;
    // b = 7-b;
    x = 7-x;
    // y = 7-y; //orients coordinates to lower left
    pos[a][b][0] = pos[x][y][0];
    pos[a][b][1] = pos[x][y][1];
    pos[x][y][0] = pos[x][y][1] = 0;
  } else {
    std::cout << "\n   Illegal move \n\n";
    std::cout << "   For debugging, here's some info: " << pos[x][y][0] << " " << x << " " << y << "\n\n" ;
  }
}

std::string getName(int a) {
  switch (a) {
    case 1:
      return "P";
      break;
    case 2:
      return "B";
      break;
    case 3:
      return "N";
      break;
    case 4:
      return "R";
      break;
    case 5:
      return "Q";
      break;
    case 6:
      return "K";
      break;
    default:
      return " ";
      break;
  }
}

std::string board::printBoard() {
 std::string ret = "";
 for (int i = 0; i < 8; i++) {
   ret+=std::to_string(7-i)+"  ";
   for (int a = 0; a < 8; a++) {
     if (pos[i][a][0]) {
       if (pos[i][a][1] == 1) {
         ret+=("\033[1;31m"+getName(pos[i][a][0])+"\033[0m" + " ");
       } else {
         ret+=("\033[1;34m"+getName(pos[i][a][0])+"\033[0m" + " ");
       }
     }
     else
       ret+= "x ";
   }
   ret+="\n";
 }
 ret += "\n   0 1 2 3 4 5 6 7";
 return ret;
}

void board::startGame() {
 int tmp[8][8] = {
   {4, 3, 2, 6, 5, 2, 3, 4},
   {1, 1, 1, 1, 1, 1, 1, 1},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {1, 1, 1, 1, 1, 1, 1, 1},
   {4, 3, 2, 6, 5, 2, 3, 4}
 };
 for (int i = 0; i < 8; i++) {
   int n = 1;
   if (i > 1) n = 0;
   if (i > 5) n = 2;
   for (int a = 0; a < 8; a++) {
     pos[i][a][0] = tmp[i][a];
     pos[i][a][1] = n;
   }
 }
}
