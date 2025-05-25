//
// Created by ziga zoric on 25.05.25.
//

#ifndef WITHDRAW_H
#define WITHDRAW_H
#include <QWidget>

#include "../../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"


class WithdrawFront {
public:
    void withdraw(const UserData& user);
};



#endif //WITHDRAW_H
