#include "mainwindow.h"

void MainWindow::p_connectSignals(){
    FUN();
    connect(this->_menu, &UIMenu::onNewScan, this, &MainWindow::sl_new_scan);
    connect(this->_menu, &UIMenu::onLoadDB, this, &MainWindow::sl_load_db);
    connect(this->_menu, &UIMenu::onStoreDB, this, &MainWindow::sl_store_db);
    connect(this->_menu, &UIMenu::onCleanupDB, this, &MainWindow::sl_cleanup_db);
    connect(this->_menu, &UIMenu::onDeleteDB, this, &MainWindow::sl_delete_db);
    connect(this->_menu, &UIMenu::onQuit, this, &MainWindow::close);
    LOGD("Connected signals");
}
