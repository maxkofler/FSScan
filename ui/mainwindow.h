#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>

#include <string>

#include "log/log.h"
#include "menu/uimenu.h"
#include "indexer/indexer.h"

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

private slots:
    void                    sl_new_scan(std::string dir);
    void                    sl_load_db(std::string path);
    void                    sl_store_db(std::string path);
    void                    sl_cleanup_db();
    void                    sl_delete_db();

    void                    sl_statusUpdate(std::string msg);

private:
    Ui::MainWindow *ui;

    Indexer*                _indexer;

    QMenuBar*               _menubar;
    QStatusBar*             _statusbar;

    UIMenu*                 _menu;

    void                    p_connectSignals();
};

#endif // MAINWINDOW_H
