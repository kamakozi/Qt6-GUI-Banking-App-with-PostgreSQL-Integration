#include "ShowInfo.h"
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include "../../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"

void ShowInfo::showInfo(const UserData& user) {
    QWidget* window = new QWidget;
    window->resize(850, 600);
    window->setWindowTitle("User Information");

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

        QLabel#infoLabel {
            font-size: 20px;
            font-weight: normal;
            color: #cccccc;
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

    QVBoxLayout* layout = new QVBoxLayout(window);
    layout->setContentsMargins(60, 40, 60, 40);
    layout->setSpacing(25);
    layout->addWidget(title);
    layout->addWidget(username);
    layout->addWidget(email);
    layout->addWidget(balance);
    layout->addWidget(role);
    layout->addStretch();

    window->setLayout(layout);
    window->show();
}