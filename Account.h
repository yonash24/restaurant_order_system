#pragma once
#include <string>
#include <vector>
#include <iostream>

class Account {
private:
    double balance;
    std::string ownerName;
    std::string accountNumber;
    std::string accountType;
    bool isActive;
    double overdraftLimit;
    std::vector<std::string> transactionHistory;

    void addTransactionToHistory(std::string transactionDetails);

public:
    Account(std::string name, double initialBalance);

    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    std::string getOwnerName() const;

    void setOwnerName(std::string newName);
    void setAccountNumber(std::string num);
    std::string getAccountNumber() const;
    void setAccountType(std::string type);
    std::string getAccountType() const;
    bool closeAccount();
    void reopenAccount();
    bool isActive() const;

    bool transfer(Account& destinationAccount, double amount);
    void setOverdraftLimit(double limit);
    double getOverdraftLimit() const;
    void applyInterest(double rate);
    void applyMonthlyFee(double fee);

    void printTransactionHistory() const;
    void clearTransactionHistory();

    void printSummary() const;
    bool isOverdrawn() const;
    bool canWithdraw(double amount) const;
    int compare(Account& otherAccount);
};