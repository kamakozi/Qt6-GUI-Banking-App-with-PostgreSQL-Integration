#include "../CallserverFastPoint/CallServerFastPoint.h"
#include "DepositBack.h"
#include <pqxx/pqxx>
#include <iostream>
UserData DepositBack::deposit(UserData user,double amount) {
try{
    pqxx::connection& conn = CallServerFastPoint::getInstance();
    pqxx::work xtn(conn);
    user.balance += amount;
    std::string query=
        "UPDATE users SET balance = " + xtn.quote(user.balance) + " WHERE id = " + xtn.quote(user.id) + ";";
    xtn.exec(query);
    xtn.commit();

    pqxx::work xxt(conn);
    std::string depositQuery =
    "INSERT INTO transactions (user_id, type, amount) VALUES (" +
    xxt.quote(user.id) + ", " +
    xxt.quote("deposit") + ", " +
    xxt.quote(amount) + ");";
    pqxx::result r = xxt.exec(depositQuery);
    xxt.commit();

    return user;
}catch (const std::exception& e) {
    std::cerr << "Unable to deposit money!" << e.what() << std::endl;
}
return user;
}
