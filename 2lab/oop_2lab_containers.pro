TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hexagon.cpp \
    tstack.cpp \
    tstackitem.cpp

HEADERS += \
    hexagon.h \
    point.h \
    tstack.h \
    TStackItem.h
