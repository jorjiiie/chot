/*
 *
 * Version 1
 * May 11, 2020
 *
 */

#include <string>
class board {
 int pos[8][8],atk[8][8];
 public:
   std::string printBoard(void);
   void startGame(void);
   void setPos(int, int, int);
   void swp(int, int, int, int);
};
std::string getName(int a) {
  switch (a) {
    case 1:
      return "P";
      break;
    case 2:
      return "B";
      break;
    case 3:
      return "K";
      break;
    case 4:
      return "R";
      break;
    case 5:
      return "Q";
      break;
    case 6:
      return "G";
      break;
    default:
      return " ";
      break;
  }
}
std::string board::printBoard() {
 std::string ret = "";
 for (int i = 0; i < 8; i++) {
   ret+=std::to_string(i+1)+" ";
   for (int a = 0; a < 8; a++) {
     ret+=(getName(pos[i][a]) + " ");
   }
   ret+="\n";
 }
 ret += "  A B C D E F G H";
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
   for (int a = 0; a < 8; a++) {
     pos[i][a] = tmp[i][a];
   }
 }
}
