//
// Created by ziga zoric on 24.05.25.
//

#ifndef LOGINCHECHER_H
#define LOGINCHECHER_H
#include <QString>

#include "UserData.h"


class LoginChecher {
public:
    std::optional<UserData> loginChecker(const QString& email,const QString& password);
};



#endif //LOGINCHECHER_H
