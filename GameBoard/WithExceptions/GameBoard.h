#ifndef GAME_BOARD_H_
#define GAME_BOARD_H_

#include <stdexcept>
#include <new>

class GamePiece
{
 public:
  explicit GamePiece(int num = 0)
  : mNumber(num) {}

  const int getNum() const { return mNumber; }

 protected:
  int mNumber;
};

class GameBoard
{
 public:
  GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight) throw (std::bad_alloc);
  GameBoard(const GameBoard& src) throw (std::bad_alloc);
  ~GameBoard() noexcept;
  GameBoard& operator=(const GameBoard& rhs) throw (std::bad_alloc);

  void setPieceAt(int x, int y, const GamePiece& inPiece) throw (std::out_of_range);
  GamePiece& getPieceAt(int x, int y) throw (std::out_of_range);
  const GamePiece& getPieceAt(int x, int y) const throw (std::out_of_range);
  int getHeight() const throw (std::out_of_range) { return mHeight; }
  int getWidth() const throw (std::out_of_range){ return mWidth; }

  static const int kDefaultWidth = 100;
  static const int kDefaultHeight = 100;
  
 private:
  GamePiece** mCells;
  int mWidth, mHeight;

  void copyFrom(const GameBoard& src) throw (std::bad_alloc);
};

#endif
