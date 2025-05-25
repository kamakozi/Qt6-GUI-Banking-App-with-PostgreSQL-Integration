#include "WithdrawFront.h"

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

#include "../../../../../BackEnd/DataServerEndPoint/WithdrawalBack/WithdrawalBack.h"
#include "../../../../../BackEnd/DataServerEndPoint/LoginChecker/UserData.h"
#include "../MainBankWindow.h"

void WithdrawFront::withdraw(const UserData& user) {
    QWidget* window = new QWidget;
    window->resize(850, 600);
    window->setWindowTitle("Withdraw Funds");

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

    QLabel* title = new QLabel("Withdraw from Your Account");
    title->setObjectName("titleLabel");
    title->setAlignment(Qt::AlignCenter);

    QLabel* seeBalance = new QLabel("Balance: " + QString::number(user.balance, 'f', 2) + " €");
    seeBalance->setObjectName("balanceLabel");
    seeBalance->setAlignment(Qt::AlignCenter);

    QLineEdit* withdrawAmount = new QLineEdit;
    withdrawAmount->setPlaceholderText("Enter amount to withdraw");

    QPushButton* confirmWithdrawal = new QPushButton("Withdraw");
    QPushButton* backToMenu = new QPushButton("Cancel");

    QVBoxLayout* boxLayout = new QVBoxLayout(window);
    boxLayout->setContentsMargins(60, 40, 60, 40);
    boxLayout->setSpacing(25);
    boxLayout->addWidget(title);
    boxLayout->addWidget(seeBalance);
    boxLayout->addWidget(withdrawAmount);
    boxLayout->addWidget(confirmWithdrawal);
    boxLayout->addWidget(backToMenu);
    boxLayout->addStretch();
    window->setLayout(boxLayout);

    QObject::connect(backToMenu, &QPushButton::clicked, [=]() {
        MainBankWindow mbw;
        QWidget* mainWindow = mbw.mainBankWindow(user);
        mainWindow->show();
        window->close();
    });

    QObject::connect(confirmWithdrawal, &QPushButton::clicked, [=]() {
        bool ok;
        double amount = withdrawAmount->text().toDouble(&ok);

        if (!ok || amount <= 0 || amount > user.balance) {
            QMessageBox::warning(window, "Withdrawal Error", "Please enter a valid amount.");
            return;
        }

        UserData userCopy = user;
        WithdrawalBack wb;
        UserData updatedUser = wb.withdrawalBack(userCopy, amount);

        QMessageBox::information(window, "Withdrawal Successful", 
                                 "You withdrew: " + QString::number(amount, 'f', 2) + " €");

        MainBankWindow mbw;
        QWidget* mainWindow = mbw.mainBankWindow(updatedUser);
        mainWindow->show();
        window->close();
    });

    window->show();
}