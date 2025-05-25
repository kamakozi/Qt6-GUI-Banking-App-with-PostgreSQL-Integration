
#include "WithdrawalBack.h"
#include "../CallserverFastPoint/CallServerFastPoint.h"
#include <pqxx/pqxx>
#include <iostream>
UserData WithdrawalBack::withdrawalBack(UserData& user,double amount) {
    try{

    pqxx::connection& conn = CallServerFastPoint::getInstance();
    pqxx::work xtn(conn);

    user.balance -= amount;
    std::string query=
        "UPDATE users SET balance = " + xtn.quote(user.balance) + " WHERE id = " + xtn.quote(user.id) + ";";
    xtn.exec(query);
    xtn.commit();

    pqxx::work xxt(conn);

        std::string withdrawalQuery =
        "INSERT INTO transactions (user_id, type, amount) VALUES (" +
        xxt.quote(user.id) + ", " +
        xxt.quote("withdraw") + ", " +
        xxt.quote(amount) + ");";

    pqxx::result r = xxt.exec(withdrawalQuery);
        xxt.commit();

    return user;
    }catch (std::exception& e) {
        std::cerr << "Unable to withdrew funds! " << e.what() << std::endl;
        return user;
    }
}
