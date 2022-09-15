#ifndef BANK_ACCOUNT_H__
#define BANK_ACCOUNT_H__

#include <iostream>

enum AccountStatus {Active, Restricted, Closed };

/**
 * @brief BankAccount Class represents a client bank account and related operations.
 *
 */
class BankAccount {
private: // friend declarations
friend std::ostream & operator<<(std::ostream & os, const BankAccount & account);
private: // member variables
    std::string m_name;
    std::string m_address;
    std::string m_nationalID;
    std::string m_guardianName;
    std::string m_guardianNationalID;
    std::string m_password;
    unsigned long m_bankAccountID;
    double m_balance;
    int m_age;
    AccountStatus m_status;
public:


    /**
     * @brief The only constructor used to create a new acount.
     *
     * @param  name The name of the client.
     * @param  address The address of the client.
     * @param  nationalID The nationalID of the client.
     * age is less than 21 years old.
     * @param password The password of the account.
     * @param bankAccountID The ID of the account.
     * @param age The age of the client.
     * @param  guardianName The guardianName of the client if the client
     * age is less than 21 years old.
     * @param guardianNationalID The guardianNationalID of the client if the client
     */
    BankAccount( std::string name,
                 std::string address,
                 std::string nationalID,
                 std::string password,
                 unsigned long bankAccountID,
                 int age,
                 std::string guardianName = "",
                 std::string guardianNationalID = "" )
        :
        m_name(name),
        m_address(address),
        m_nationalID(nationalID),
        m_guardianName(guardianName),
        m_guardianNationalID(guardianNationalID),
        m_password(password),
        m_bankAccountID(bankAccountID),
        m_balance(0),
        m_age(age),
        m_status(Active)
    { }

    /**
     * @brief Returns the status of current account.
     * 
     * @return The status of current account. 
     * Possible values of return of this method are: Active, Restricted, and Closed.
     * @see set_status()
     */
    AccountStatus get_status() const {
        return m_status;
    }

    /**
     * @brief Sets the status of current account.
     *
     * @param status The status to set this account to.
     * @return None.
     * @see get_status()
     */
    void set_status(AccountStatus status) {
        m_status = status;
    }

    /**
     * @brief Updates the password of the current account.
     *
     * @param password The new password to set for current account.
     * @return None.
     * @warning Actually no one stores passwords as plain text. This is a know "Bug".
     * @see validate_password()
     *
     */
    void update_password(std::string password) {
        m_password = password;
    }

    /**
     * @brief Validates the given password against the stored one.
     *
     * @param password The password to validate against the account password.
     * @return bool: whether the supplied password is correct or not.
     * @warning Actually no one stores passwords as plain text. This is a known "Bug"
     * @see update_password()
     */
    bool validate_password(std::string password) {
        return m_password == password;
    }

    /**
     * @brief Withdraw an amount of money from current account if contains sufficient balance.
     *
     * @param amount Amount of money to withdraw from current account.
     * @return bool Whether the operations is successful or not.
     * @note If account balance is in-sufficient; It does nothing.
     * @note If Account Status is not Active; It does nothing.,
     * @see make_transaction()
     *
     */
    bool get_cash(double amount) {
        if (amount <= m_balance && m_status == Active) {
            m_balance -= amount;
            return true;
        }
        return false;
    }

    /**
     * @brief Transfers an amount of money from current account to 
     * another account given that this account contains a sufficient amount of money.
     *
     * @param account The account to transfer money to.
     * @param amount The amount of money to transfer.
     * @return bool whether the operation is successfull or not.
     * @note If account balance is insufficient; It does nothing.
     * @note If one of the tow accounts is not active, It does nothing.
     * @see get_cash()
     *
     */
    bool make_transaction(BankAccount & account, double amount) {
        if (amount <= m_balance && m_status == Active && account.m_status == Active) {
            m_balance -= amount;
            account.m_balance += amount;
            return true;
        }
        return false;
    }

    /**
     * @brief Deposit money into this account.
     *
     * @param amount The amount of money to deposit into this account.
     * @return bool Whether or not the operation is successful.
     *
     */
    bool deposit(double amount) {
        if (m_status == Active) {
            m_balance += amount;
            return true;
        }
        return false;
    }

    /**
     * @brief Returns the Balance in the current account.
     *
     * @return double the Balance in the current account.
     */
    double balance() {
        return m_balance;
    }
};


/**
 * @brief Prints the attributes of an account to the specified stream.
 * 
 * @param os The stream to which the output is printed.
 * @param account The count to print its attributes.
 * @return The stream specified as input to the function.
 */
std::ostream& operator<<(std::ostream & os, const BankAccount & account);

#endif // BANK_ACCOUNT_H__

