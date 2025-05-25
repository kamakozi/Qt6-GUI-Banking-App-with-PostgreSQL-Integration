#include "DepositFrontEnd.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <qmessagebox.h>

#include "../../../../../BackEnd/DataServerEndPoint/Deposit/DepositBack.h"
#include "../../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"
#include "../MainBankWindow.h"



void DepositFrontEnd::deposit(const UserData& user) {
    QWidget* window = new QWidget;
    const int width = 850;
    const int height = 600;
    window->resize(width, height);
    window->setWindowTitle("Deposit Funds");

    window->setStyleSheet(R"(
        QWidget {
            background-color: #1e1e2f;
            color: #ffffff;
        }

        QLabel#titleLabel {
            font-size: 24px;
            font-weight: bold;
            color: #ffffff;
        }

        QLabel#balanceLabel {
            font-size: 20px;
            color: #00cc99;
        }

        QLineEdit {
            background-color: #2e2e40;
            border: 2px solid #444;
            border-radius: 8px;
            padding: 10px;
            color: #ffffff;
            font-size: 16px;
        }

        QLineEdit:focus {
            border: 2px solid #0078D7;
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


    QLabel* title = new QLabel("Deposit to Your Account");
    title->setObjectName("titleLabel");
    title->setAlignment(Qt::AlignCenter);


    QLabel* amount = new QLabel("Current Balance: " + QString::number(user.balance, 'f', 2) + " €");
    amount->setObjectName("balanceLabel");
    amount->setAlignment(Qt::AlignCenter);


    QLineEdit* depositInput = new QLineEdit;
    depositInput->setPlaceholderText("Enter amount to deposit");


    QPushButton* depositBtn = new QPushButton("Confirm Deposit");
    QPushButton* backToMenu = new QPushButton("Cancel");


    QVBoxLayout* boxLayout = new QVBoxLayout;
    boxLayout->setContentsMargins(60, 40, 60, 40);
    boxLayout->setSpacing(25);
    boxLayout->addWidget(title);
    boxLayout->addWidget(amount);
    boxLayout->addWidget(depositInput);
    boxLayout->addWidget(depositBtn);
    boxLayout->addWidget(backToMenu);
    boxLayout->addStretch();

    window->setLayout(boxLayout);
    window->show();


    QObject::connect(depositBtn,&QPushButton::clicked,[window,depositInput,userCopy = user] {
        bool ok;
        double depositAmount = depositInput->text().toDouble(&ok);

        if (!ok || depositAmount < 0) {
            QMessageBox::warning(window,"Invalid amount","Please enter a valid deposit amount.");
            return;
        }
        DepositBack db;
        UserData updateUser = db.deposit(userCopy,depositAmount);

        QString depositText = depositInput->text();
        QMessageBox::information(window,"Deposit successful", "You deposited: " + depositText + "€");
        MainBankWindow mbw;
        QWidget* mainWindow =  mbw.mainBankWindow(updateUser);
        mainWindow->show();
        window->close();
    });

    QObject::connect(backToMenu,&QPushButton::clicked,[=] {
        MainBankWindow mbw;
        mbw.mainBankWindow(user);
        window->close();
    });


}