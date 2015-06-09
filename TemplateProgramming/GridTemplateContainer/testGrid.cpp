#include "Grid.h"
#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::vector;
using std::deque;

int main()
{
  Grid<int ,vector<int>> myIntGrid;
  Grid<int, deque<int>> myIntGrid2;
  myIntGrid.setElementAt(3, 4, 5);
  cout << myIntGrid.getElementAt(3, 4);

  Grid<int, vector<int>> grid2(myIntGrid);
  grid2 = myIntGrid;
  
  return 0;
}
