// Keenan Alchaar | ka5nt | 02/19/20 | bankAccount.cpp

#include "bankAccount.h"

bankAccount::bankAccount() {
  balance = 0;
}

bankAccount::bankAccount(double amount) {
  balance = amount;
}

bankAccount::~bankAccount() {

}

double bankAccount::withdraw(double amount) {
  if (amount > balance) {
    return balance;
  } else {
    balance -= amount;
    return balance;
  }
}

double bankAccount::deposit(double amount) {
  balance += amount;
  return balance;
}

double bankAccount::getBalance() {
  return balance;
}
