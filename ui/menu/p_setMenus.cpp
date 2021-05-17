#include "uimenu.h"

void UIMenu::p_setMenus(MainWindow* win){
    /*
        this->actionNewScan = new QAction("Neuer Scan", this);
        connect(this->actionNewScan, &QAction::triggered, this, &MainWindow::onMenuNewScan);
        this->_fileMenu->addAction(this->actionNewScan);
    */
    FUN();
    this->_filemenu->addAction(this->_action_new_scan);
    this->_filemenu->addAction(this->_action_load_db);
    this->_filemenu->addAction(this->_action_store_db);
    this->_filemenu->addAction(this->_action_cleanup_db);
    this->_filemenu->addAction(this->_action_delete_db);
    this->_filemenu->addAction(this->_action_quit);
    LOGD("Added all actions to the menu");
}
