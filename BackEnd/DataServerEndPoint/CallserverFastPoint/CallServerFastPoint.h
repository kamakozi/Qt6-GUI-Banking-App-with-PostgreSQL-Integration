
#ifndef CALLSERVERFASTPOINT_H
#define CALLSERVERFASTPOINT_H
#include <pqxx/pqxx>
#include "../DataServerEndPoint.h"


class CallServerFastPoint {
public:

    static pqxx::connection& getInstance() {
        auto env = DataServerEndPoint::load("../database.env");

        static pqxx::connection conn("dbname=" + env["DB_NAME"] + " user=" + env["DB_USER"] + " password=" +env["DB_PASSWORD"] + " host=" + env["DB_HOST"] + " port=" + env["DB_PORT"]);
        return conn;
    }


};



#endif //CALLSERVERFASTPOINT_H
