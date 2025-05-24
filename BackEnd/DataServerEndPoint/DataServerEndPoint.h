//
// Created by ziga zoric on 24.05.25.
//

#ifndef DATASERVERENDPOINT_H
#define DATASERVERENDPOINT_H
#include <string>
#include <map>

class DataServerEndPoint {
public:
    static std::map<std::string,std::string> load(const std::string& path);

};



#endif //DATASERVERENDPOINT_H
