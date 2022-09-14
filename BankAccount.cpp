#include <iostream>
#include "BankAccount.h"


static unsigned long BankAccount::id_list[system_capacity];
static bool BankAccount::id_list_initialized = false;

std::ostream& operator<<(std::ostream & os, const BankAccount & account)
{
    os << "Name                 :"                 << m_name << "\n";    
    os << "Address              :"              << m_address << "\n";    
    os << "National ID          :"          << m_nationalID << "\n";    
    os << "Age                  :"                  << m_age << "\n";    
    os << "Account ID           :"           << m_bankAccountID << "\n";    
    os << "Guardian Name        :"        << m_guardianName << "\n";    
    os << "Guardian National ID :" << m_guardianNationalID << "\n";    
    os << "Account Status       :"       << m_status << "\n";    
    os << "Balance              :"              << m_balance << "\n";    
    os << "Password             :"             << m_password << "\n";    
    return os;
}
