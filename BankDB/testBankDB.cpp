#include "BankDB.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

int main()
{
  BankDB db;
  db.addAccount(BankAccount(100, "Nicklas"));
  db.addAccount(BankAccount(200, "Scarlet"));
  try {
    auto acct = db.findAccount(100);
    cout << "Found account 100" << endl;
    acct.setClientName("Nick");

    auto acct2 = db.findAccount("Scarlet");
    cout << "Find account of Scarlet" << endl;

    auto acct3 = db.findAccount(1000);
  } catch (const out_of_range& ) {
    cout << "Unable to find account" << endl;
  }

  return 0;
}
