#include <iostream>
#include <string>
class ATM {
public:
ATM(double balance) : balance_(balance) {}
double CheckBalance() { return balance_; }
bool WithdrawCash(double amount) {
if (amount > balance_) {
std::cout << "Insufficient funds" << std::endl;
return false;
}
balance_ -= amount;
return true;
}
bool DepositCash(double amount) {
balance_ += amount;
return true;
}
private:
double balance_;
};
int main() {
ATM atm(1000);
std::string input;
while (true) {
std::cout << "Enter transaction (withdraw, deposit, check balance,exit): ";
std::cin >> input;
if (input == "withdraw") {
double amount;
std::cout << "Enter amount: ";
std::cin >> amount;
if (atm.WithdrawCash(amount)) {
std::cout << "Transaction successful" << std::endl;
}
} else if (input == "deposit") {
double amount;
std::cout << "Enter amount: ";
std::cin >> amount;
if (atm.DepositCash(amount)) {
std::cout << "Transaction successful" << std::endl;
}
} else if (input == "check balance") {
std::cout << "Current balance: " << atm.CheckBalance() << std::endl;
} else if (input == "exit") {
break;
} else {
std::cout << "Invalid transaction" << std::endl;
}
}
return 0;
}
