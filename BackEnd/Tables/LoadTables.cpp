
#include <fstream>
#include "LoadTables.h"
#include <sstream>
#include <pqxx/pqxx>
#include "../DataServerEndPoint/CallserverFastPoint/CallServerFastPoint.h"

void LoadTables::loadTables() {

    pqxx::connection& conn= CallServerFastPoint::getInstance();

    pqxx::work txn(conn);

    std::ifstream readFile("/Users/zigazoric/Desktop/cpp/qtlearn/BackEnd/Tables/Tables.sql");
    if (!readFile) {
        throw std::runtime_error("Failed to open Tables.sql");
    }
    std::stringstream buffer;

    buffer << readFile.rdbuf();

    txn.exec(buffer.str());
    txn.commit();
}

