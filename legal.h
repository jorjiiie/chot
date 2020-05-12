#include <vector>
#include <string>
#include <cmath>
#include "board.h"

bool checkStr(int ul, int pn, int x, int y, int d) {
  if (d > 7 || x > 7 || y > 7 || d < 0 || x < 0 || y < 0) return false;
  int use = 0;
  d+=pn;
  if (ul){
    use = y;
    while (abs(d-use) > 0) {
      if(retLoc(x,d))
        return false;
      d+=pn;
      }
  } else {
    use = x;
    while (abs(d-use) > 0) {
      if (retLoc(d,y))
        return false;
      d+=pn;
    }
  }
  return true;
}

bool legal(int x, int y, int a, int b, std::vector<bool> moves) {
  if (pos[7-x][y][1] == pos[7-a][b][1]) return false;
  if (moves[0]) {
    if (abs(x-a) == abs(y-b)) return true;
  }
  if (moves[1]) {
    if (x == a || y == b) return true;
  }
  if (moves[2]) {
    if ((abs(x-a) == 1 && abs(y-b == 2)) || (abs(x-a == 2) && abs(y-b == 1))) return true;
  }
  if (moves[3]) {
    if (abs(x-a) <= 2) return true;
  }
  if (moves[4]) {
    if (abs(x-a) < 2 && abs(y-b) < 2) return true;
  }
  return false;
}

bool legal(int id, int x, int y, int a, int b) {
  if (pos[7-x][y][1] == pos[7-a][b][1]) return false;
  std::vector<bool> moves = getMoves(id);
  if (moves[0]) {
    int quad;
    if (abs(x-a) == abs(y-b)) return true;
  }
  if (moves[1]) {
    int ul,pn,d;
    if (x == a || y == b) {
      if (x == a) {
        // std::cout << " change in y \n";
        ul = 1;
        d = b;
        if (y > b) pn = 1;
        else pn = -1;
      } else {
        // std::cout << "change in x\n";
        ul = 0;
        d = a;
        if (x > a) pn = 1;
        else pn = -1;
      }
      // std::cout << ul << " " << pn << " " << x << " " << y << " " << d << "\n";
      return checkStr(ul, pn, x, y, d);
    }
  }
  if (moves[2]) {
    if ((abs(x-a) == 1 && abs(y-b) == 2) || (abs(x-a)==2 && abs(y-b) == 1)) return true;
  }
  if (moves[3]) {
    if (pos[7-x][y][1] == 1) {
       if (x == 6) return (x-a <=2 && x-a > 0);
       else return x-a ==1;
    }
    else {
      if (x == 1) return (a-x <= 2 && a-x > 0);
      else return a-x == 1;
    }
  }
  if (moves[4]) {
    if (abs(x-a) < 2 && abs(y-b) < 2) return true;
  }
  return false;
}
