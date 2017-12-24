#ifndef TEXT_QUERY_
#define TEXT_QUERY_

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <set>
#include <map>

#include "QueryResult.h"

class QueryResult;

class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;

  TextQuery(std::ifstream&);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif
