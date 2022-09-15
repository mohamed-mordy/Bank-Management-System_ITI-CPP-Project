#include <iostream>
#include "BankAccount.h"



std::ostream& operator<<(std::ostream & os, const BankAccount & account)
{
    os << "Name                 :" << account.m_name << "\n";    
    os << "Address              :" << account.m_address << "\n";    
    os << "National ID          :" << account.m_nationalID << "\n";    
    os << "Age                  :" << account.m_age << "\n";    
    os << "Account ID           :" << account.m_bankAccountID << "\n";    
    os << "Guardian Name        :" << account.m_guardianName << "\n";    
    os << "Guardian National ID :" << account.m_guardianNationalID << "\n";    
    os << "Account Status       :" << account.m_status << "\n";    
    os << "Balance              :" << account.m_balance << "\n";    
    os << "Password             :" << account.m_password << "\n";    
    return os;
}
