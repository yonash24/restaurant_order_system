#include <iostream>
#include "Account.h"

int main() {
    Account acc1("Israel Israeli", 1000.0);
    acc1.setAccountNumber("100-123");
    acc1.setAccountType("Checking");
    acc1.setOverdraftLimit(500);

    Account acc2("Yael Cohen", 500.0);
    acc2.setAccountNumber("100-456");
    acc2.setAccountType("Savings");

    acc1.printSummary();
    acc2.printSummary();

    std::cout << "\n>>> Performing transfer..." << std::endl;
    acc1.transfer(acc2, 600.0);

    acc1.printSummary();
    acc2.printSummary();

    std::cout << "\n>>> Applying interest and fees..." << std::endl;
    acc2.applyInterest(5.0); 
    acc1.applyMonthlyFee(10.0);

    acc1.printSummary();
    acc2.printSummary();

    std::cout << "\n>>> Attempting to overdraw..." << std::endl;
    bool withdrawSuccess = acc1.withdraw(1000.0); 
    std::cout << "Withdrawal attempt status: " << (withdrawSuccess ? "Success" : "Failed") << std::endl;

    acc1.printSummary();

    acc1.printTransactionHistory();
    acc2.printTransactionHistory();

    return 0;
}