#include <QWidget>
#include "RegisterWindow.h"
#include <QBoxLayout>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtextedit.h>
#include <QLineEdit>
#include <qmessagebox.h>

QWidget* RegisterWindow::registerWindow() {

    QWidget *window;
    window->resize(480,360);
    window->show();

    QLineEdit *username =new QLineEdit(window);
    username->setAlignment(Qt::AlignCenter);
    username->setPlaceholderText("Username");

    QLineEdit *password = new QLineEdit(window);
    password->setEchoMode(QLineEdit::Password);
    password->setAlignment(Qt::AlignCenter);
    password->setPlaceholderText("Password");

    QPushButton *registerbtn = new QPushButton("Register",window);


    QBoxLayout *box_layout = new QBoxLayout(QBoxLayout::BottomToTop,window);
    box_layout->addWidget(username);
    box_layout->addWidget(password);
    box_layout->addWidget(registerbtn);
    window->setLayout(box_layout);

    QObject::connect(registerbtn,&QPushButton::clicked,[=]() {
        if (username->text().isEmpty() || password->text().isEmpty()) {
            QMessageBox::warning(window,"Input error", "Username and password cannot be empty!");
            return;
        }
        QMessageBox::information(window,"Success!","User registered!");
    });


    window->show();

return window;

}
