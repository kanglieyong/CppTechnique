#ifndef GAME_BOARD_H_
#define GAME_BOARD_H_

class GamePiece
{
 public:
  explicit GamePiece(int num = 0)
  : mNumber(num) {}
  
  const int getNum() const { return mNumber; }

 private:
  int mNumber;
};

class GameBoard
{
 public:
  GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
  GameBoard(const GameBoard& src);
  ~GameBoard();
  GameBoard& operator=(const GameBoard& rhs);

  void setPieceAt(int x, int y, const GamePiece& inPiece);
  GamePiece& getPieceAt(int x, int y);
  const GamePiece& getPieceAt(int x, int y) const;
  int getHeight() const { return mHeight; }
  int getWidth() const { return mWidth; }

  static const int kDefaultWidth = 100;
  static const int kDefaultHeight = 100;
  
 private:
  GamePiece** mCells;
  int mWidth, mHeight;

  void copyFrom(const GameBoard& src);
};

#endif
