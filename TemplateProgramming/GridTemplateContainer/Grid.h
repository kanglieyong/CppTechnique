#include <cstddef>
using std::size_t;

template <typename T, typename Container>
  class Grid
{
 public:
  Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
  virtual ~Grid();

  Grid(const Grid<T, Container>& src);
  Grid<T, Container>& operator=(const Grid<T, Container>& rhs);

  void setElementAt(size_t x, size_t y, const T& inElem);
  const T& getElementAt(size_t x, size_t y) const;
  T& getElementAt(size_t x, size_t y);
  size_t getWidth() const { return mWidth; }
  size_t getHeight() const { return mHeight; }

  static const size_t kDefaultWidth = 10;
  static const size_t kDefaultHeight = 10;
  
 private:
  void copyFrom(const Grid<T, Container>& src);

  Container* mCells;
  size_t mWidth, mHeight;
};

#include "Grid.cpp"
