#include "iostream"

class Account
{
    private:
        double balance;
        std::string owner_name;
        std::string account_type;
        bool is_active;

    public:
        Account(double start_balance, std::string owner_name, std::string type, bool status)
        {
            this->balance = start_balance;
            this->owner_name = owner_name;
            this->account_type = type;
            this->is_active = status;
        }

        void deposit(double amount)
        {
            if (amount <= 0)
            {
                throw "cannot add a negative deposit";
            }
            else
            {
                this->balance += amount;
            }
        }

        // withdra money from the bank account
        bool withdraw(double amount)
        {
            if((this->balance - amount) < 0)
            {
                std::cout << "theres not anought money at the balance" << std::endl;
                return false;
            }
            else
            {
                this->balance = this->balance-amount;
            }
            return true;
        }

        // return the bank account balance
        double get_balance()
        {
            return this->balance;
        }

        //return the owner name
        std::string get_owner_name()
        {
            return this->owner_name;
        }

        //set the bank account balance
        void set_balance(double new_balance)
        {
            this->balance = new_balance;
        }

        //set the owner name 
        void set_owner_name(std::string new_owner_name)
        {
            this->owner_name = new_owner_name;
        }

        //set the account type
        void set_account_type(std::string type)
        {
            this->account_type = type;
        }

        //get the account type
        std::string get_account_type()
        {
            return this->account_type;
        }

        //set the account status
        void set_account_status(bool status)
        {
            this->is_active = status;
        }

        //get the account status
        bool get_account_status()
        {
            return this->is_active;
        }

        //close active account ensure hes not having any debts
        //return the status of the account active or not
        bool close_account()
        {
            if(this->balance < 0)
            {
                std::cout << "the account has negative balance cannot close it until it will be fixed" << std::endl;
                return this->is_active;
            }
            else if(this->balance > 0)
            {
                std::cout << "there is balance of: " << this->balance << " in the account please contect us on how you want to receive it" << std::endl;
                return this->is_active;
            }
            else
            {
                this->is_active = false;
            }
            return this->is_active;
        }

        //reopen closed account
        void reopen_account()
        {
            this->is_active = true;
            std::cout << "account opened successfully";
        }

        
};