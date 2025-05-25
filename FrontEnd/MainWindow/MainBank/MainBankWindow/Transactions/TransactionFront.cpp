#include "TransactionFront.h"
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include "../MainBankWindow.h"

void MakeTransaction::makeTransaction(UserData user) {
    QWidget* window = new QWidget;
    window->resize(850, 600);
    window->setWindowTitle("Transactions");

    window->setStyleSheet(R"(
        QWidget {
            background-color: #1e1e2f;
            color: white;
            font-family: 'Segoe UI', sans-serif;
        }

        QLabel#welcomeLabel {
            font-size: 26px;
            font-weight: bold;
            color: #ffffff;
            margin-bottom: 40px;
        }

        QLabel#footerLabel {
            font-size: 14px;
            color: #777;
            margin-top: 10px;
        }

        QPushButton {
            background-color: #0078D7;
            color: white;
            font-size: 18px;
            padding: 12px 24px;
            border: none;
            border-radius: 8px;
            margin: 10px 0;
        }

        QPushButton:hover {
            background-color: #005BBB;
        }
    )");

    QLabel* welcomeMsg = new QLabel("Hey " + user.username);
    welcomeMsg->setObjectName("welcomeLabel");
    welcomeMsg->setAlignment(Qt::AlignCenter);

    QPushButton* createTransactionBtn = new QPushButton("Create Transaction");
    QPushButton* seeTransactionsBtn = new QPushButton("See Transactions");
    QPushButton* backBtn = new QPushButton("Back");

    QLabel* bankLabel = new QLabel("Zoric Bank Company");
    bankLabel->setObjectName("footerLabel");
    bankLabel->setAlignment(Qt::AlignCenter);

    QLabel* creditsLabel = new QLabel("Created by kama");
    creditsLabel->setObjectName("footerLabel");
    creditsLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(100, 60, 100, 40);
    layout->setSpacing(25);
    layout->addWidget(welcomeMsg);
    layout->addWidget(createTransactionBtn);
    layout->addWidget(seeTransactionsBtn);
    layout->addWidget(backBtn);
    layout->addStretch();
    layout->addWidget(bankLabel);
    layout->addWidget(creditsLabel);

    QObject::connect(backBtn, &QPushButton::clicked, [=] {
        MainBankWindow mbw;
        mbw.mainBankWindow(user);
        window->close();
    });

    window->setLayout(layout);
    window->show();
}