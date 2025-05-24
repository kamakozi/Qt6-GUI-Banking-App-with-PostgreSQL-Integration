
#include "DataServerEndPoint.h"
#include <fstream>
#include <sstream>

std::map<std::string, std::string> DataServerEndPoint::load(const std::string &path) {
    std::ifstream readFile(path);
    std::map<std::string,std::string> env;
    std::string line;

    while (std::getline(readFile,line)) {
        size_t pos = line.find("=");
        if (pos != std::string::npos) {
            std::string key = line.substr(0,pos);
            std::string value = line.substr(pos+1);
            env[key] = value;
        }
    }
    return env;
}

