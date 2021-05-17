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
        ui/mainwindow.cpp

HEADERS += \
    indexer/fsentry/fsentry.h \
    indexer/indexer.h \
    log/log.h \
    log/logfunction.h \
    ui/mainwindow.h

FORMS += \
    ui/mainwindow.ui
