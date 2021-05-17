#include "uimenu.h"

void UIMenu::p_registerSlots(){
    FUN();
    connect(this->_action_new_scan, &QAction::triggered, this, &UIMenu::sl_new_scan);
    connect(this->_action_load_db, &QAction::triggered, this, &UIMenu::sl_load_db);
    connect(this->_action_store_db, &QAction::triggered, this, &UIMenu::sl_store_db);
    connect(this->_action_cleanup_db, &QAction::triggered, this, &UIMenu::sl_cleanup_db);
    connect(this->_action_delete_db, &QAction::triggered, this, &UIMenu::sl_delete_db);
    connect(this->_action_quit, &QAction::triggered, this, &UIMenu::sl_quit);
    LOGD("Registered all private slots");
}
