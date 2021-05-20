QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
        indexer/fsentry/fsentry.cpp \
        indexer/indexer.cpp \
        indexer/indexerio.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        ui/connectsignals.cpp \
        ui/mainwindow.cpp \
        ui/menu/p_createActions.cpp \
        ui/menu/p_registerSlots.cpp \
        ui/menu/p_setMenus.cpp \
        ui/menu/uimenu.cpp \
        #MainWindow slots
        ui/private_slots/mainwindow_sl_cleanup_db.cpp \
        ui/private_slots/mainwindow_sl_delete_db.cpp \
        ui/private_slots/mainwindow_sl_load_db.cpp \
        ui/private_slots/mainwindow_sl_new_scan.cpp \
        ui/private_slots/mainwindow_sl_postStatusUpdate.cpp \
        ui/private_slots/mainwindow_sl_store_db.cpp \
        #UIMenu slots
        ui/menu/private_slots/uimenu_sl_cleanup_db.cpp \
        ui/menu/private_slots/uimenu_sl_delete_db.cpp \
        ui/menu/private_slots/uimenu_sl_load_db.cpp \
        ui/menu/private_slots/uimenu_sl_new_scan.cpp \
        ui/menu/private_slots/uimenu_sl_quit.cpp \
        ui/menu/private_slots/uimenu_sl_store_db.cpp \
        ui/ui_methods/refreshItemList.cpp

HEADERS += \
    indexer/fsentry/fsentry.h \
    indexer/indexer.h \
    log/log.h \
    log/logfunction.h \
    ui/mainwindow.h \
    ui/menu/uimenu.h

FORMS += \
    ui/mainwindow.ui
