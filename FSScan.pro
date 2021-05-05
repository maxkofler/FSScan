TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        indexer/indexer.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp

HEADERS += \
    indexer/indexer.h \
    log/log.h \
    log/logfunction.h
