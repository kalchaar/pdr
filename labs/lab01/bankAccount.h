// Keenan Alchaar | ka5nt | 02/19/20 | bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {
 public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();

  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;
};

#endif
