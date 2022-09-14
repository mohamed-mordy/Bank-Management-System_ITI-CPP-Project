#ifndef BANK_SYSTEM_MANAGER_H__
#define BANK_SYSTEM_MANAGER_H__

#include <iostream>
#include <unorderd_map>
#include "BankAccount.h"

class BankSystemManager {
private:
    std::unordered_map<unsigned long, BankAccount> accounts;
public: 
    BankSystemManager() = default;    
    void make_transaction(unsigned long from, unsigned long to, double amount);
    void get_cash(unsigned long account, double amount);
    void change_account_status(unsigned long accountID, AccountStatus status);
    double get_balance(unsigned long accountID);
    void deposit(unsigned long accountId, double amount);
    bool validate_id(unsigned long accountID);
};

#endif // BANK_SYSTEM_MANAGER_H__

