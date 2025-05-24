#include "RegisterWindow/RegisterWindow.h"
#include "PopOutWindow.h"
#include <QtWidgets>
#include <QApplication>
#include <QBoxLayout>
#include <QLabel>

QWidget* PopOutWindow::createWindow() {
    QWidget *window = new QWidget;
    window->resize(480, 360);
    window->setWindowTitle("Bank app");

    QLabel *label = new QLabel("Zoric bank app", window);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 20px; font-weight: bold;");

    QLineEdit *username = new QLineEdit(window);
    QLineEdit *password = new QLineEdit(window);
    password->setEchoMode(QLineEdit::Password);

    username->setPlaceholderText("Email");
    password->setPlaceholderText("Password");

    QString inputStyle = R"(
        QLineEdit {
            padding: 8px;
            font-size: 15px;
            border: 2px solid #ccc;
            border-radius: 8px;
            background-color: #f8f8f8;
            color: black;
        }
        QLineEdit::placeholder {
            color: black;
        }
        QLineEdit:focus {
            border: 2px solid #0078D7;
            background-color: #ffffff;
        }
    )";

    username->setStyleSheet(inputStyle);
    password->setStyleSheet(inputStyle);

    QString buttonStyle = R"(
        QPushButton {
            background-color: #0078D7;
            color: white;
            font-size: 16px;
            border-radius: 8px;
            padding: 8px 16px;
        }
        QPushButton:hover {
            background-color: #005BBB;
        }
    )";

    QPushButton *loginButton = new QPushButton("Login", window);
    loginButton->setStyleSheet(buttonStyle);

    QObject::connect(loginButton, &QPushButton::clicked, [=]() {
        if (username->text().isEmpty() || password->text().isEmpty()) {
            QMessageBox::warning(window, "Invalid Input", "Username and password can't be empty!");
        }
    });

    QLabel *donthaveacc = new QLabel("Don't have an account?", window);
    donthaveacc->setAlignment(Qt::AlignCenter);

    QPushButton *registerButton = new QPushButton("Register", window);
    registerButton->setStyleSheet(buttonStyle);

    QObject::connect(registerButton, &QPushButton::clicked, [=]() {
        RegisterWindow rw;
        QWidget *regWindow = rw.registerWindow();
        regWindow->show();
        window->close(); // close login window if you want
    });

    QVBoxLayout *boxLayout = new QVBoxLayout(window);
    boxLayout->setSpacing(12);
    boxLayout->setContentsMargins(40, 20, 40, 20);

    boxLayout->addWidget(label);
    boxLayout->addWidget(username);
    boxLayout->addWidget(password);
    boxLayout->addWidget(loginButton);
    boxLayout->addSpacing(10);
    boxLayout->addWidget(donthaveacc);
    boxLayout->addWidget(registerButton);

    window->setLayout(boxLayout);
    return window;
}

int PopOutWindow::run(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget *window = createWindow();
    window->show();
    return app.exec();
}