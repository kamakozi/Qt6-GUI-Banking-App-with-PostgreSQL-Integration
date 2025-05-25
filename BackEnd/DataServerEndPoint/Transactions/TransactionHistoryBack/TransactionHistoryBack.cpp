
#include <pqxx/pqxx>
#include "../../CallserverFastPoint/CallServerFastPoint.h"
#include "TransactionHistoryBack.h"
#include <iostream>
#include <vector>
#include "../Transaction.h"

    std::vector<transaction>TransactionHistoryBack::transactionHistoryBack(UserData user) {
    std::vector<transaction> transactions;
    try{
    pqxx::connection& conn = CallServerFastPoint::getInstance();

    pqxx::work xtn(conn);

    int userId = user.id;

    std::string query = "SELECT type, amount, created_at FROM transactions "
        "WHERE user_id =" + xtn.quote(userId) + " ORDER BY created_at DESC";
    pqxx::result r = xtn.exec(query);
        for (const auto& row: r) {
            transaction t;
            t.type = QString::fromStdString(row["type"].as<std::string>());
            t.amount = row["amount"].as<double>();
            t.date =QString::fromStdString(row["created_at"].as<std::string>());
            transactions.push_back(t);

        }


    }catch (const std::exception& e) {
        std::cerr << "Ubable to get transactions!" << std::endl;
    }
    return transactions;
}

