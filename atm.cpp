#include <iostream>
#include <string>
#include <map>

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

    bool Login(const std::string& name, const std::string& password) {
        // Replace with actual authentication logic (e.g., retrieving from a database)
        return accounts_.count(name) > 0 && accounts_[name].second == password;
    }

    bool CreateAccount(const std::string& name, const std::string& password) {
        // Check for existing account
        if (accounts_.count(name) > 0) {
            std::cout << "Account already exists." << std::endl;
            return false;
        }

        // Add new account to map
        accounts_[name] = {0.0, password}; // Initialize balance to 0.0

        // Explicitly return true to indicate successful creation
        return true; // Added to fix issue 1
    }

private:
    double balance_;
    std::map<std::string, std::pair<double, std::string>> accounts_; // Store accounts (name, {balance, password})
};

int main() {
    ATM atm(1000);
    std::string name, password, choice, transaction;

    while (true) {
        std::cout << "Do you have an account? (yes/no): ";
        std::cin >> choice;

        if (choice == "yes") {
            std::cout << "Enter name: ";
            std::cin >> name;

            std::cout << "Enter password: ";
            std::cin >> password;

            if (atm.Login(name, password)) {
                std::cout << "Welcome, " << name << "!" << std::endl; // Welcome message
                break; // Login successful, proceed to transaction menu
            } else {
                std::cout << "Invalid credentials\n";
            }
        } else if (choice == "no") {
            std::cout << "Enter a name for your new account: ";
            std::cin >> name;

            std::cout << "Enter a password for your account: ";
            std::cin >> password;

            if (atm.CreateAccount(name, password)) {
                std::cout << "Account created successfully!\n";

                // Ask for initial transaction after successful creation
                std::cout << "Would you like to make a deposit now? (yes/no): ";
                std::cin >> transaction;

                if (transaction == "yes") {
                    // Handle deposit logic
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    atm.DepositCash(amount);
                    std::cout << "Deposit successful!" << std::endl;
                }

                break; // Account creation and initial transaction complete
            } else {
                std::cout << "Error creating account\n";
            }
        } else {
            std::cout << "Invalid choice. Please enter 'yes' or 'no'\n";
        }
    }

    // Transaction menu (after successful login or account creation)
    while (true) {
        // ... existing transaction logic (using name if applicable) ...
    }

    return 0;
}
