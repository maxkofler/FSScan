#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>

#include "log/log.h"
#include "menu/uimenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    friend class UIMenu;
private:
    Ui::MainWindow *ui;

    QMenuBar*               _menubar;
    QStatusBar*             _statusbar;

    UIMenu*                 _menu;
};

#endif // MAINWINDOW_H
