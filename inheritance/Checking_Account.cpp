//
// Created by revanth on 20.11.25.
//

#include "Checking_Account.hpp"

#include "Trust_Account.hpp"


bool Checking_Account::withdraw(double amount)
{
    amount = amount+def_fee;
    return Account::withdraw(amount);
}

