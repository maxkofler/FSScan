#include "uimenu.h"

void UIMenu::p_createActions(MainWindow* win){
    FUN();
    this->_action_new_scan = new QAction("Neuer Scan", win);
    this->_action_load_db = new QAction("Datenbank öffnen", win);
    this->_action_store_db = new QAction("Datenbank speichern", win);
    this->_action_cleanup_db = new QAction("Datenbank aufräumen", win);
    this->_action_delete_db = new QAction("Datenbank leeren", win);
    this->_action_quit = new QAction("Beenden", win);
    LOGD("Created all menu actions");
}
