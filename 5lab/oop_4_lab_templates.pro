TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    tstack.cpp \
    tstackitem.cpp \
    triangle.cpp \
    hexagon.cpp \
    octagon.cpp \
    figure.cpp \
    titerator.cpp

HEADERS += \
    tstack.h \
    tstackitem.h \
    point.h \
    triangle.h \
    hexagon.h \
    octagon.h \
    figure.h \
    titerator.h
