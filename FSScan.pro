TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        indexer/fsentry/fsentry.cpp \
        indexer/indexer.cpp \
        indexer/indexerio.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp

HEADERS += \
    indexer/fsentry/fsentry.h \
    indexer/indexer.h \
    log/log.h \
    log/logfunction.h
