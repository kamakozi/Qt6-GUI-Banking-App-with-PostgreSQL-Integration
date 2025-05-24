//
// Created by ziga zoric on 24.05.25.
//

#ifndef PASSWORDHASH_H
#define PASSWORDHASH_H
#include <string>



class PasswordHash {
public:
    std::string sha256(const std::string& str);
};



#endif //PASSWORDHASH_H
