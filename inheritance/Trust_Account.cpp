//
// Created by revanth on 20.11.25.
//

#include "Trust_Account.hpp"


bool Trust_Account::deposit(const double amount)
{
    if (amount >= 5000)
    {
        return Savings_Account::deposit((amount + 50));
    }
    else
    {
        return Savings_Account::deposit((amount));
    }
}

bool Trust_Account::withdraw(const double amount)
{
    const double bal = get_balance();
    if ((num_withdrawals < 4) && (amount <= (bal* 0.2)))
    {
        num_withdrawals++;
        return Savings_Account::withdraw((amount));
    }
    else
    {
        return false;
    }
}