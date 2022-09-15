#ifndef BANK_SYSTEM_MANAGER_H__
#define BANK_SYSTEM_MANAGER_H__

#include <iostream>
#include <unorderd_map>
#include "BankAccount.h"

/**
 * BankSystemManager class represents the controller component of the system.
 *
 */
class BankSystemManager {
private:
    std::unordered_map<unsigned long, BankAccount> accounts;
public:  // Public Methods

};

#endif // BANK_SYSTEM_MANAGER_H__

