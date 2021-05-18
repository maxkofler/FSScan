#include "uimenu.h"

UIMenu::UIMenu(MainWindow* win){
    FUN();
    this->_mainwindow = win;
    this->_filemenu = win->_menubar->addMenu("Datei");
    p_createActions(win);
    p_registerSlots();
    p_setMenus(win);
    LOGD("Set up menu");
}
