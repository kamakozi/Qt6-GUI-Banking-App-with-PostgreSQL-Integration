#include <QtWidgets/QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include "TransactionHistoryFront.h"
#include "../../../../../../BackEnd/DataServerEndPoint/Transactions/Transaction.h"
#include "../../../../../../BackEnd/DataServerEndPoint/Transactions/TransactionHistoryBack/TransactionHistoryBack.h"
#include "../../MainBankWindow.h" // needed for back navigation

void TransactionHistory::transactionHistory(UserData user) {
    QWidget* window = new QWidget;
    window->resize(860, 600);
    window->setWindowTitle("All Transactions");

    auto* layout = new QVBoxLayout(window);
    auto* table = new QTableWidget(window);

    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Type", "Amount (€)", "Date"});
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    std::vector<transaction> transactions = TransactionHistoryBack::transactionHistoryBack(user);
    table->setRowCount(static_cast<int>(transactions.size()));

    for (int i = 0; i < transactions.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(transactions[i].type));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(transactions[i].amount, 'f', 2)));
        table->setItem(i, 2, new QTableWidgetItem(transactions[i].date));
    }

    QPushButton* backBtn = new QPushButton("Back");
    backBtn->setFixedWidth(120);
    backBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #0078D7;
            color: white;
            font-size: 16px;
            padding: 10px;
            border-radius: 6px;
        }
        QPushButton:hover {
            background-color: #005BBB;
        }
    )");

    QObject::connect(backBtn, &QPushButton::clicked, [=] {
        MainBankWindow mbw;
        mbw.mainBankWindow(user);
        window->close();
    });

    layout->addWidget(table);
    layout->addWidget(backBtn, 0, Qt::AlignCenter);

    window->setLayout(layout);
    window->show();
}