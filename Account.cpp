#include "Account.h"
#include <iostream>
#include <string>

Account::Account(std::string name, double initialBalance)
    : ownerName(name), 
      balance(initialBalance), 
      isActive(true), 
      overdraftLimit(0.0), 
      accountType("Standard") 
{
    if (initialBalance < 0) {
        balance = 0;
    }
    addTransactionToHistory("Account created. Initial balance: " + std::to_string(balance));
}

void Account::addTransactionToHistory(std::string transactionDetails) {
    transactionHistory.push_back(transactionDetails);
}

bool Account::deposit(double amount) {
    if (!isActive) return false;
    if (amount <= 0) return false;

    balance += amount;
    addTransactionToHistory("Deposit: +" + std::to_string(amount));
    return true;
}

bool Account::withdraw(double amount) {
    if (!isActive) return false;
    if (!canWithdraw(amount)) {
        addTransactionToHistory("Failed withdraw attempt: " + std::to_string(amount));
        return false;
    }

    balance -= amount;
    addTransactionToHistory("Withdrawal: -" + std::to_string(amount));
    return true;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getOwnerName() const {
    return ownerName;
}

void Account::setOwnerName(std::string newName) {
    this->ownerName = newName;
}

void Account::setAccountNumber(std::string num) {
    this->accountNumber = num;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

void Account::setAccountType(std::string type) {
    this->accountType = type;
}

std::string Account::getAccountType() const {
    return accountType;
}

bool Account::closeAccount() {
    if (balance != 0) {
        return false; 
    }
    isActive = false;
    addTransactionToHistory("Account closed.");
    return true;
}

void Account::reopenAccount() {
    isActive = true;
    addTransactionToHistory("Account reopened.");
}

bool Account::isActive() const {
    return isActive;
}

bool Account::transfer(Account& destinationAccount, double amount) {
    if (!this->isActive || !destinationAccount.isActive) {
        return false;
    }

    if (this->canWithdraw(amount)) {
        this->balance -= amount;
        destinationAccount.balance += amount;

        this->addTransactionToHistory("Transfer Out: -" + std::to_string(amount) + " to " + destinationAccount.getAccountNumber());
        destinationAccount.addTransactionToHistory("Transfer In: +" + std::to_string(amount) + " from " + this->getAccountNumber());
        return true;
    }
    return false;
}

void Account::setOverdraftLimit(double limit) {
    if (limit >= 0) {
        this->overdraftLimit = limit;
    }
}

double Account::getOverdraftLimit() const {
    return overdraftLimit;
}

void Account::applyInterest(double rate) {
    if (!isActive || rate <= 0) return;
    double interest = balance * (rate / 100.0);
    if (interest > 0) {
        deposit(interest);
        transactionHistory.pop_back(); 
        addTransactionToHistory("Interest applied: +" + std::to_string(interest));
    }
}

void Account::applyMonthlyFee(double fee) {
    if (!isActive || fee <= 0) return;
    withdraw(fee);
    transactionHistory.pop_back(); 
    addTransactionToHistory("Monthly fee applied: -" + std::to_string(fee));
}

void Account::printTransactionHistory() const {
    std::cout << "\n--- Transaction History for " << accountNumber << " ---" << std::endl;
    for (const std::string& transaction : transactionHistory) {
        std::cout << transaction << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}

void Account::clearTransactionHistory() {
    transactionHistory.clear();
    addTransactionToHistory("Transaction history cleared.");
}

void Account::printSummary() const {
    std::cout << "\n--- Account Summary ---" << std::endl;
    std::cout << "Owner: \t\t" << ownerName << std::endl;
    std::cout << "Account #: \t" << accountNumber << std::endl;
    std::cout << "Type: \t\t" << accountType << std::endl;
    std::cout << "Status: \t" << (isActive ? "Active" : "Closed") << std::endl;
    std::cout << "Balance: \t" << balance << std::endl;
    std::cout << "Overdraft Limit: " << overdraftLimit << std::endl;
    std::cout << "-----------------------" << std::endl;
}

bool Account::isOverdrawn() const {
    return balance < 0;
}

bool Account::canWithdraw(double amount) const {
    if (amount <= 0) return false;
    return (balance + overdraftLimit) >= amount;
}

int Account::compare(Account& otherAccount) {
    if (this->balance > otherAccount.balance) {
        return 1;
    } else if (this->balance < otherAccount.balance) {
        return -1;
    } else {
        return 0;
    }
}