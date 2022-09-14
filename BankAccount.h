#ifndef BANK_ACCOUNT_H__
#define BANK_ACCOUNT_H__

#include <iostream>

enum class AccountStatus {Active, Restricted, Closed };

class BankAccount {
private: // friend declarations
friend std::ostream & operator<<(std::ostream & os, const BankAccount & account);
private: // member variables
    std::string m_name;
    std::string m_address;
    std::string m_nationalID;
    int m_age;
    unsigned long m_bankAccountID;
    std::string m_guardianName;
    std::string m_guardianNationalID;
    AccountStatus m_status;
    double m_balance;
    std::string m_password;
private:  // static class variables
    constexpr unsigned system_capacity = 1000;
    static unsigned long id_list[system_capacity];
    static bool id_list_initialized = false;
public:

    BankAccount() = 0;

    AccountStatus get_status() const {
        return status;
    }

    void set_status(AccountStatus status) {
        m_status = status;
    }

    void update_password(std::string password) {
        m_password = password;
    }

    bool validate_password(std::string password) {
        return m_password == password;
    }

    double balance() {
        return m_balance;
    }

private: // private utility functions
    static std::string generate_password(void);
    static unsigned long generate_unique_id(void);
};


std::ostream& operator<<(std::ostream & os, const BankAccount & account);

#endif // BANK_ACCOUNT_H__

