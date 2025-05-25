//
// Created by ziga zoric on 25.05.25.
//

#ifndef TRANSACTIONHISTORYBACK_H
#define TRANSACTIONHISTORYBACK_H
#include "../../LoginChecker/UserData.h"
#include "../Transaction.h"



class TransactionHistoryBack {

public:
   static std::vector<transaction>transactionHistoryBack(UserData user);
};



#endif //TRANSACTIONHISTORYBACK_H
