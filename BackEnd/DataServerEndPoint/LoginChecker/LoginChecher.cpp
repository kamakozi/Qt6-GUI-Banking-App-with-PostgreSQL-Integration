//
// Created by ziga zoric on 24.05.25.
//

#include "LoginChecher.h"
#include <string>
#include "../CallserverFastPoint/CallServerFastPoint.h"
#include <iostream>
#include "../registerUser/PasswordHash/PasswordHash.h"
#include "UserData.h"

std::optional<UserData> LoginChecher::loginChecker(const QString& email, const QString& password) {
    try{

    pqxx::connection& conn = CallServerFastPoint::getInstance();
    pqxx::work txn(conn);

    std::string stringEmail = email.toStdString();
    std::string stringPassword = password.toStdString();

    PasswordHash ph;
    std::string hashedPassword = ph.sha256(stringPassword);
        std::string query =
            "SELECT id, username, email, balance, role_id FROM users "
            "WHERE (email = " + txn.quote(stringEmail) +
            " OR username = " + txn.quote(stringEmail) +
            ") AND password_hash = " + txn.quote(hashedPassword) + " LIMIT 1;";
        pqxx::result res = txn.exec(query);
    txn.commit();

        if (!res.empty()) {
            UserData user;
            user.id = res[0][0].as<int>();
            user.username = QString::fromStdString(res[0][1].as<std::string>());
            user.email = QString::fromStdString(res[0][2].as<std::string>());
            user.balance = res[0][3].as<double>();
            user.role_id = res[0][4].is_null() ? -1 : res[0][4].as<int>();
            return user;
        }
    }catch (const std::exception& e) {
        std::cerr << "Unable to retrieve login: " << e.what() << std::endl;
    }

    return std::nullopt;


}
