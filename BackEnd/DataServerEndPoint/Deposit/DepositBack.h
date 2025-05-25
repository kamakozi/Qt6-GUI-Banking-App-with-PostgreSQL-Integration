#ifndef DEPOSIT_BACK_H
#define DEPOSIT_BACK_H

#include "../LoginChecker/UserData.h"

class DepositBack {
public:
    UserData deposit(UserData user, double amount);
};

#endif // DEPOSIT_BACK_H