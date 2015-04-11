#ifndef BANK_DB_H_
#define BANK_DB_H_

#include <string>
#include <map>
#include <stdexcept>

class BankAccount
{
 public:
  BankAccount(int acctNum, const std::string& name)
    : mAcctNum(acctNum),
    mClientName(name) {}

  void setAcctNum(int acctNum) { mAcctNum = acctNum; }
  int getAcctNum() const { return mAcctNum; }

  void setClientName(const std::string& name) { mClientName = name; }
  std::string getClientName() const { return mClientName; }
  
 protected:
  int mAcctNum;
  std::string mClientName;
};

class BankDB
{
 public:
  BankDB() {}
  
  bool addAccount(const BankAccount& acct);
  void deleteAccount(const BankAccount& acct);
  
  BankAccount& findAccount(int acctNum) throw (std::out_of_range);
  BankAccount& findAccount(const std::string) throw (std::out_of_range);
  
  void mergeDatabase(BankDB& db);

 protected:
  std::map<int, BankAccount> mAccounts;
};

#endif
