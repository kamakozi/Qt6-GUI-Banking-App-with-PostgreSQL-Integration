#include "ShowInfo.h"
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QString>
#include "../MainBankWindow.h"
#include "../../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"

void ShowInfo::showInfo(const UserData& user) {
    QWidget* window = new QWidget;
    window->resize(850, 600);
    window->setWindowTitle("User Information");

    window->setStyleSheet(R"(
        QWidget {
            background-color: #1e1e2f;
            color: #ffffff;
            font-family: 'Segoe UI', sans-serif;
        }

        QLabel#titleLabel {
            font-size: 32px;
            font-weight: bold;
            color: #ffffff;
            margin-bottom: 20px;
        }

        QLabel#infoLabel {
            font-size: 20px;
            font-weight: 500;
            color: #cccccc;
            margin-top: 10px;
        }

        QPushButton {
            background-color: #0078D7;
            color: white;
            font-size: 18px;
            font-weight: bold;
            border: none;
            border-radius: 8px;
            padding: 12px 24px;
            margin-top: 25px;
        }

        QPushButton:hover {
            background-color: #005BBB;
        }
    )");

    QLabel* title = new QLabel("Account Information");
    title->setObjectName("titleLabel");
    title->setAlignment(Qt::AlignCenter);

    QLabel* username = new QLabel("Username: " + user.username);
    QLabel* email = new QLabel("Email: " + user.email);
    QLabel* balance = new QLabel("Balance: " + QString::number(user.balance, 'f', 2) + " €");
    QString roleName = (user.role_id == 2) ? "Admin" : "User";
    QLabel* role = new QLabel("Role: " + roleName);

    for (QLabel* label : {username, email, balance, role}) {
        label->setObjectName("infoLabel");
        label->setAlignment(Qt::AlignCenter);
    }

    QPushButton* backBtn = new QPushButton("Back");

    QObject::connect(backBtn, &QPushButton::clicked, [=] {
        MainBankWindow mbw;
        mbw.mainBankWindow(user);
        window->close();
    });

    QVBoxLayout* layout = new QVBoxLayout(window);
    layout->setContentsMargins(60, 40, 60, 40);
    layout->setSpacing(25);

    layout->addWidget(title);
    layout->addSpacing(15);
    layout->addWidget(username);
    layout->addWidget(email);
    layout->addWidget(balance);
    layout->addWidget(role);
    layout->addSpacing(30);
    layout->addWidget(backBtn, 0, Qt::AlignCenter);
    layout->addStretch();

    window->setLayout(layout);
    window->show();
}