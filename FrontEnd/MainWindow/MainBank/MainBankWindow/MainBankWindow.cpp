#include "MainBankWindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include "../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"
#include "Deposit/DepositFrontEnd.h"
#include "Withdraw/WithdrawFront.h"
#include "ShowInfo/ShowInfo.h"

QWidget* MainBankWindow::mainBankWindow(const UserData& user) {
    QWidget* window = new QWidget;
    window->resize(850, 600);
    window->setWindowTitle("Zoric Bank Dashboard");


    window->setStyleSheet(R"(
        QWidget {
            background-color: #1e1e2f;
            color: #ffffff;
        }

        QLabel#titleLabel {
            font-size: 28px;
            font-weight: bold;
            color: #ffffff;
        }

        QLabel#balanceLabel {
            font-size: 22px;
            font-weight: bold;
            color: #00cc99;
        }

        QPushButton {
            background-color: #29293d;
            color: #ffffff;
            padding: 12px;
            border-radius: 10px;
            font-size: 16px;
        }

        QPushButton:hover {
            background-color: #3f3f5a;
        }
    )");

    QLabel* welcomeMessage = new QLabel("Welcome, " + user.username);
    welcomeMessage->setObjectName("titleLabel");
    welcomeMessage->setAlignment(Qt::AlignCenter);


    QLabel* balanceLabel = new QLabel("Balance: " + QString::number(user.balance, 'f', 2) + " €");
    balanceLabel->setObjectName("balanceLabel");
    balanceLabel->setAlignment(Qt::AlignCenter);


    QPushButton* depositButton = new QPushButton("Deposit");
    QPushButton* withdrawButton = new QPushButton("Withdraw");
    QPushButton* userInfoButton = new QPushButton("User Info");

    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->setSpacing(15);
    buttonLayout->addWidget(depositButton);
    buttonLayout->addWidget(withdrawButton);
    buttonLayout->addWidget(userInfoButton);
    buttonLayout->addStretch();


    QVBoxLayout* mainLayout = new QVBoxLayout(window);
    mainLayout->setContentsMargins(60, 40, 60, 40);
    mainLayout->setSpacing(30);
    mainLayout->addWidget(welcomeMessage);
    mainLayout->addWidget(balanceLabel);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(buttonLayout);

    QObject::connect(userInfoButton,&QPushButton::clicked,[=] {
        ShowInfo si;
        si.showInfo(user);
        window->close();
    });
    QObject::connect(depositButton,&QPushButton::clicked,[=] {
        DepositFrontEnd d;
        d.deposit(user);
        window->close();
    });

    QObject::connect(withdrawButton,&QPushButton::clicked,[=] {
    WithdrawFront wf;
        wf.withdraw(user);
        window->close();
    });


    window->setLayout(mainLayout);
    window->show();

    return window;
}