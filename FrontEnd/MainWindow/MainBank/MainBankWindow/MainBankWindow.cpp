#include <QtWidgets/QWidget>
#include "MainBankWindow.h"

#include <QLabel>
#include <QBoxLayout>
#include <QFormLayout>

#include "../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"

QWidget *MainBankWindow::mainBankWindow(const UserData& user) {
    QWidget *window = new QWidget;
    window->resize(850,600);

    QLabel *welcomeMassage = new QLabel("Welcome " + user.username);
    QLabel *displayBalance = new QLabel(QString::number(user.balance, 'f', 2) +  "€",window);

    QBoxLayout *box_layout = new QBoxLayout(QBoxLayout::TopToBottom);
    box_layout->addWidget(welcomeMassage);
    box_layout->addWidget(displayBalance);

    window->setLayout(box_layout);
    window->show();

}
