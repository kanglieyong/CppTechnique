#ifndef TEXTRESULT_H_
#define TEXTRESULT_H_
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <iostream>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
  QueryResult(std::string s,
              std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
  : sought(s), lines(p), file(f) {}

private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};
#endif
