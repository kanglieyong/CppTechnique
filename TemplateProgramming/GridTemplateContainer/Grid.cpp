template <typename T, typename Container>
Grid<T, Container>::Grid(size_t inWidth, size_t inHeight)
  : mWidth(inWidth),
    mHeight(inHeight)
{
  mCells = new Container[mWidth];
  for (size_t i = 0; i < mWidth; i++) mCells[i].resize(mHeight);
}

template <typename T, typename Container>
Grid<T, Container>::~Grid()
{
  delete[] mCells;
  mCells = nullptr;
}

template <typename T, typename Container>
void Grid<T, Container>::copyFrom(const Grid<T, Container>& src)
{
  mWidth = src.mWidth;
  mHeight = src.mHeight;
  mCells = new Container[mWidth];
  for (size_t i = 0; i < mWidth; i++) mCells[i].resize(mHeight);
  for (size_t i = 0; i < mWidth; i++) {
    for (size_t j = 0; j < mHeight; j++) mCells[i][j] = src.mCells[i][j];
  }
}

template <typename T, typename Container>
Grid<T, Container>::Grid(const Grid<T, Container>& src)
{
  copyFrom(src);
}

template <typename T, typename Container>
Grid<T, Container>& Grid<T, Container>::operator=(const Grid<T, Container>& rhs)
{
  if (this == &rhs) return *this;
  delete[] mCells;
  mCells = nullptr;
  copyFrom(rhs);
  return *this;
}

template <typename T, typename Container>
void Grid<T, Container>::setElementAt(size_t x, size_t y, const T& inElem)
{
  mCells[x][y] = inElem;
}

template <typename T, typename Container>
T& Grid<T, Container>::getElementAt(size_t x, size_t y)
{
  return mCells[x][y];
}

template <typename T, typename Container>
const T& Grid<T, Container>::getElementAt(size_t x, size_t y) const
{
  return mCells[x][y];
}
