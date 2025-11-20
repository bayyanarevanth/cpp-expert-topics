//
// Created by revanth on 20.11.25.
//

#ifndef CPP_PROJECT_TRUST_ACCOUNT_HPP
#define CPP_PROJECT_TRUST_ACCOUNT_HPP
#include "Savings_Account.h"


class Trust_Account: public Savings_Account
{
    private:
        static constexpr auto def_name = "Unnamed Trust Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
        int num_withdrawals;
    public:
        Trust_Account(const char* name = def_name, const double balance = def_balance, const double int_rate = def_int_rate)
        : num_withdrawals{0}, Savings_Account(name, balance,int_rate)
        {
            // do nothing
        }
        bool deposit(double amount);
        bool withdraw(double amount);

};


#endif //CPP_PROJECT_TRUST_ACCOUNT_HPP