//
// Created by ziga zoric on 24.05.25.
//

#ifndef MAINBANKWINDOW_H
#define MAINBANKWINDOW_H
#include <QWidget>

#include "../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"


class MainBankWindow {
public:
    QWidget* mainBankWindow(const UserData& user);
};



#endif //MAINBANKWINDOW_H
