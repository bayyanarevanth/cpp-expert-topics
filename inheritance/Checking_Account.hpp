//
// Created by revanth on 20.11.25.
//

#ifndef CPP_PROJECT_CHECKER_ACCOUNT_HPP
#define CPP_PROJECT_CHECKER_ACCOUNT_HPP
#include "Account.h"


class Checking_Account: public Account
{
    private:
        static constexpr const char* def_name = "Checking_Account";
        static constexpr double def_fee = 1.5F;
        static constexpr double def_balance = 0.0F;
    public:
        // Checking_Account(): Account(def_name, def_balance)
        // {
        //
        // }
        // when Checking_Account{} is used to declare,
        // {} could mean empty initializer list
        // Or it could prefer the constructor that is closest to an initializer-list match

        Checking_Account(const char* name = def_name, const double balance = def_balance)
        : Account(name, balance)
        {

        }
        bool withdraw(double amount);
};


#endif //CPP_PROJECT_CHECKER_ACCOUNT_HPP