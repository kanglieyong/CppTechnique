#include "GameBoard.h"

GameBoard::GameBoard(int inWidth, int inHeight)
  : mWidth(inWidth),
    mHeight(inHeight)
{
  mCells = new GamePiece* [mWidth];
  for (int i = 0; i < mWidth; i++) mCells[i] = new GamePiece[mHeight];
}

GameBoard::GameBoard(const GameBoard& src)
{
  copyFrom(src);
}

GameBoard::~GameBoard()
{
  for (int i = 0; i < mWidth; i++) {
    delete[] mCells[i];
  }
  delete[] mCells;
  mCells = nullptr;
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
  if (this == &rhs) return *this;
  for (int i = 0; i < mWidth; i++) {
    delete[] mCells[mWidth];
  }
  delete[] mCells;
  mCells = nullptr;
  copyFrom(rhs);
  return *this;
}

void GameBoard::copyFrom(const GameBoard& src)
{
  mWidth = src.mWidth;
  mHeight = src.mHeight;
  mCells = new GamePiece* [mWidth];
  for (int i = 0; i < mWidth; i++) {
    mCells[i] = new GamePiece[mHeight];
  }
  for (int i = 0; i < mWidth; i++) {
    for (int j = 0; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
}

void GameBoard::setPieceAt(int x, int y, const GamePiece& inElem)
{
  mCells[x][y] = inElem;
}

GamePiece& GameBoard::getPieceAt(int x, int y)
{
  return mCells[x][y];
}

const GamePiece& GameBoard::getPieceAt(int x, int y) const
{
  return mCells[x][y];
}
