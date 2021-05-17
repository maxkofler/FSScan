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
        ui/mainwindow.cpp \
        ui/menu/p_createActions.cpp \
        ui/menu/p_registerSlots.cpp \
        ui/menu/p_setMenus.cpp \
        ui/menu/private_slots/sl_cleanup_db.cpp \
        ui/menu/private_slots/sl_delete_db.cpp \
        ui/menu/private_slots/sl_load_db.cpp \
        ui/menu/private_slots/sl_new_scan.cpp \
        ui/menu/private_slots/sl_quit.cpp \
        ui/menu/private_slots/sl_store_db.cpp \
        ui/menu/uimenu.cpp

HEADERS += \
    indexer/fsentry/fsentry.h \
    indexer/indexer.h \
    log/log.h \
    log/logfunction.h \
    ui/mainwindow.h \
    ui/menu/uimenu.h

FORMS += \
    ui/mainwindow.ui
