#ifndef UIMENU_H
#define UIMENU_H

class UIMenu;

#include <QMenuBar>
#include <QMenu>
#include <QObject>

#include "log/log.h"
#include "../mainwindow.h"

class UIMenu : public QObject
{
    Q_OBJECT
public:
    UIMenu(MainWindow* win);

signals:
    void                    onNewScan();
    void                    onLoadDB(std::string path);
    void                    onStoreDB(std::string path);
    void                    onCleanupDB();
    void                    onDeleteDB();
    void                    onQuit();

private slots:
    void                    sl_new_scan();
    void                    sl_load_db();
    void                    sl_store_db();
    void                    sl_cleanup_db();
    void                    sl_delete_db();
    void                    sl_quit();

private:
    QMenu*                  _filemenu;

    QAction*                _action_new_scan;
    QAction*                _action_load_db;
    QAction*                _action_store_db;
    QAction*                _action_cleanup_db;
    QAction*                _action_delete_db;
    QAction*                _action_quit;

    void                    p_createActions(MainWindow* win);
    void                    p_setMenus(MainWindow* win);
    void                    p_registerSlots();
};

#endif // UIMENU_H
