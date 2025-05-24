// Created by ziga zoric on 24.05.25.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class PopOutWindow {
public:
    int run(int argc, char *argv[]);        // Starts the full Qt app
    QWidget* createWindow();                // Returns the login window (for reuse)
};

#endif // MAINWINDOW_H