
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

    return user;
    }catch (std::exception& e) {
        std::cerr << "Unable to withdrew funds! " << e.what() << std::endl;
    }
}
