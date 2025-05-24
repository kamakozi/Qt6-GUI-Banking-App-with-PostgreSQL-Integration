#include "../CallserverFastPoint/CallServerFastPoint.h"
#include "RegisterUser.h"
#include <pqxx/pqxx>
#include <iostream>
bool RegisterUser::insertUser(const QString &username, const QString &password, const QString &email) {
    try{
    pqxx::connection& conn = CallServerFastPoint::getInstance();

    pqxx::work xtn(conn);

    std::string stringUsername = username.toStdString();
    std::string stringPassword = password.toStdString();
    std::string stringEmail = email.toStdString();

        pqxx::result r = xtn.exec("SELECT id FROM roles WHERE name = 'user' LIMIT 1;");
        int roleId = r[0][0].as<int>();

        std::string query =
            "INSERT INTO users (username, email, password_hash, balance, role_id) VALUES (" +
            xtn.quote(stringUsername) + ", " +
            xtn.quote(stringEmail) + ", " +
            xtn.quote(stringPassword) + ", " +
            xtn.quote(0.00) + ", " +
            xtn.quote(roleId) + ");";

    xtn.exec(query);
    xtn.commit();
    return true;
    }catch (const std::exception& e) {
        std::cerr << "Database insert failed: " << e.what() << std::endl;
        return false;
    }

}
