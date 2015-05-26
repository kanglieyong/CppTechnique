#include "GameBoard.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
  GameBoard gb(5, 6);
  GamePiece theElem(10);
  gb.setPieceAt(3, 4, theElem);

  for (int i = 0; i < gb.getWidth(); i++) {
    for (int j = 0; j < gb.getHeight(); j++) {
      cout << gb.getPieceAt(i, j).getNum() << " ";
    }
    cout << endl;
  }

  return 0;
}
