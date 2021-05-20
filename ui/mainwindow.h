#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>
#include <QStringListModel>

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
    explicit                    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void                        refreshItemList();

    friend class                UIMenu;

private slots:
    void                        sl_new_scan(std::string dir);
    void                        sl_onFinishedScanning();
    void                        sl_load_db(std::string path);
    void                        sl_store_db(std::string path);
    void                        sl_cleanup_db();
    void                        sl_delete_db();

    void                        sl_postStatusUpdate(QString status);

    void                        sl_doubleClickedItem(QModelIndex index);

private:
    Ui::MainWindow *ui;

    Indexer*                    _indexer;

    QMenuBar*                   _menubar;
    QStatusBar*                 _statusbar;

    UIMenu*                     _menu;

    //UI
    bool                        _filterActive;
    std::vector<std::string>    _curFilter;
    QLineEdit*                  _le_search;
    QPushButton*                _bt_search;
    QListView*                  _lv_results;
    QStringList                 _lv_list;
    QStringListModel*           _lv_model;


    void                        p_connectSignals();
};

#endif // MAINWINDOW_H
