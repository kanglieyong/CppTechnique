#ifndef GAME_BOARD_H_
#define GAME_BOARD_H_

#include <stdexcept>
#include <new>

using std::bad_alloc;
using std::out_of_range;

class GamePiece
{
 public:
  explicit GamePiece(int num = 0)
  : number(num) {}

  const int getNum() const { return number; }

 protected:
  int number;
};

class GameBoard
{
 public:
  GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight) throw (bad_alloc);
  GameBoard(const GameBoard& src) throw (bad_alloc);
  ~GameBoard() noexcept;
  GameBoard& operator=(const GameBoard& rhs) throw (bad_alloc);

  void setPieceAt(int x, int y, const GamePiece& inPiece) throw (out_of_range);
  GamePiece& getPieceAt(int x, int y) throw (out_of_range);
  const GamePiece& getPieceAt(int x, int y) const throw (out_of_range);
  int getHeight() const throw (out_of_range) { return mHeight; }
  int getWidth() const throw (out_of_range){ return mWidth; }

  static const int kDefaultWidth = 100;
  static const int kDefaultHeight = 100;
  
 private:
  GamePiece** mCells;
  int mWidth, mHeight;

  void copyFrom(const GameBoard& src) throw (bad_alloc);
};

#endif
