#include <QWidget>
#include "RegisterWindow.h"
#include <QBoxLayout>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtextedit.h>
#include <QLineEdit>
#include <qmessagebox.h>
#include <QLabel>
#include <QFormLayout>
#include "../PopOutWindow.h"
#include "../../../BackEnd/DataServerEndPoint/registerUser/RegisterUser.h"
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include "../../../BackEnd/DataServerEndPoint/registerUser/PasswordHash/PasswordHash.h"

QWidget* RegisterWindow::registerWindow() {

    QWidget *window = new QWidget;
    window->resize(480,360);

    QLabel *title = new QLabel("Create new account", window);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 20px; font-weight: bold; padding-bottom: 10px;");

    QLabel *usernameLabel = new QLabel("Username");
    QLabel *passwordLabel = new QLabel("Password");
    QLabel *emailLabel = new QLabel("Email");

    QLineEdit *username =new QLineEdit(window);
    QLineEdit *password = new QLineEdit(window);
    QLineEdit *email = new QLineEdit(window);


    username->setPlaceholderText("Username");
    password->setPlaceholderText("Password");
    email->setPlaceholderText("Email");

    password->setEchoMode(QLineEdit::Password);

    QPushButton *backToLoginBtn = new QPushButton("Login",window);
    QPushButton *registerbtn = new QPushButton("Register",window);

    QString inputStyle = R"(
        QLineEdit {
            padding: 8px;
            font-size: 15px;
            border: 2px solid #ccc;
            border-radius: 8px;
            background-color: #f8f8f8;
            color: black;
        }
        QLineEdit::placeholder{
        color: black;
        }
        QLineEdit:focus {
            border: 2px solid #0078D7;
            background-color: #ffffff;
        }
    )";
    QString buttonStyle = R"(
        QPushButton {
            background-color: #0078D7;
            color: white;
            font-size: 16px;
            border-radius: 8px;
            padding: 8px 16px;
        }
        }
        QPushButton:hover {
            background-color: #005BBB;
        }
    )";
    username->setStyleSheet(inputStyle);
    password->setStyleSheet(inputStyle);
    email->setStyleSheet(inputStyle);
    email->setStyleSheet(inputStyle);
    registerbtn->setStyleSheet(buttonStyle);
    backToLoginBtn->setStyleSheet(buttonStyle);

    QVBoxLayout *mainLayout = new QVBoxLayout(window);
    mainLayout ->setSpacing(10);
    mainLayout->setContentsMargins(40,30,40,30);

    mainLayout->addWidget(title);

    QFormLayout *formLayout = new QFormLayout;

    formLayout->addRow(usernameLabel,username);
    formLayout->addRow(passwordLabel,password);
    formLayout->addRow(emailLabel,email);
    mainLayout->addLayout(formLayout);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(registerbtn,0,Qt::AlignCenter);
    mainLayout->addWidget(backToLoginBtn,0,Qt::AlignCenter);

    window->setLayout(mainLayout);

    QObject::connect(registerbtn,&QPushButton::clicked,[=]() {
        QString usernameInput = username->text();
        QString passwordInput = password->text();
        QString emailInput = email->text();

        if (username->text().isEmpty() || password->text().isEmpty() || email->text().isEmpty()) {
            QMessageBox::warning(window,"Input error", "Username and password cannot be empty!");
            return;
        }
        if (!emailInput.contains("@")) {
            QMessageBox::warning(window,"Invalid email!","Email must contain '@' symbol!");
        }
        std::string hashedpass = passwordInput.toStdString();
        PasswordHash ph;
        std::string hashedPassword = ph.sha256(hashedpass);
        QString hashedPass = QString::fromStdString(hashedPassword);
        qDebug() << "Username: " << usernameInput;
        qDebug() << "Password: " << passwordInput;
        qDebug() << "Hashed pass: " << hashedPass;
        qDebug() << "Email: " << emailInput;

        RegisterUser ru;
        if (ru.insertUser(usernameInput,hashedPass,emailInput)) {
            QMessageBox::information(window,"Success","User registered!");
            PopOutWindow pow;
            QWidget *backToLog = pow.createWindow();
            backToLog->show();
            window->close();
        }else {
            QMessageBox::warning(window,"Error", "Unable to register user.");
        }



    });



    QObject::connect(backToLoginBtn, &QPushButton::clicked, [=]() {
    PopOutWindow pow;
    QWidget *login = pow.createWindow();
    login->show();
    window->close();
});


return window;

}
