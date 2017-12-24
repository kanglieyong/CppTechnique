#include "QueryResult.h"

ostream &print(ostream &os, const QueryResult &qr)
{
  os << qr.sought << " occours " << qr.lines->size() << " times" << endl;
  for (auto num : *qr.lines) {
    os << "\t(line " << num+1 << ") "
       << *(qr.file->begin() + num) << endl;
  }
  return os;
}
