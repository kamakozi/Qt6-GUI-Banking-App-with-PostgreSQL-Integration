//
// Created by ziga zoric on 24.05.25.
//

#ifndef REGISTERUSER_H
#define REGISTERUSER_H
#include <QString>


class RegisterUser {
public:
    RegisterUser() = default;
    bool insertUser(const QString& username,const QString& password,const QString& email, const QString& countrySelector);
};



#endif //REGISTERUSER_H
